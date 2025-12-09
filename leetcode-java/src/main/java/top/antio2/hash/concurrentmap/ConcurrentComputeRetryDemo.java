/*
 * Copyright 2025 PixelsDB.
 *
 * This file is part of Pixels.
 *
 * Pixels is free software: you can redistribute it and/or modify
 * it under the terms of the Affero GNU General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * Pixels is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Affero GNU General Public License as more details.
 *
 * You should have received a copy of the Affero GNU General Public
 * License along with Pixels.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

package top.antio2.hash.concurrentmap;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;

public class ConcurrentComputeRetryDemo {

    /**
     * 模拟您的 SinkContext，包含一个可变状态
     */
    class Context {
        private final String id;
        private final AtomicInteger counter = new AtomicInteger(0); // 使用 AtomicInteger 简化内部并发修改，但 Lambda 外部的 compute 仍是关键

        public Context(String id) {
            this.id = id;
        }

        public void incrementCounter() {
            counter.incrementAndGet();
        }

        public int getCounter() {
            return counter.get();
        }

        @Override
        public String toString() {
            return "Context[id=" + id + ", counter=" + counter + "]";
        }
    }

    // 核心 Map：Key 是 String，Value 是我们自定义的 Context 对象
    private final ConcurrentHashMap<String, Context> map = new ConcurrentHashMap<>();

    // 外部的副作用计数器（全局）：记录 Lambda 内部的副作用被执行了多少次。
    private final AtomicInteger sideEffectCounter = new AtomicInteger(0);

    // --- 实验参数 ---
    private static final int KEY_COUNT = 5;               // 增加 Key 的数量
    private static final int THREAD_COUNT = 20;           // 线程池大小
    private static final int UPDATES_PER_THREAD = 100; // 每个 Key 对应的线程执行的更新次数
    private static final long CALCULATION_DELAY_MS = 10;
    // ---

    public void runDemo() throws InterruptedException {
        // 总任务数 = KEY_COUNT
        // 总预期成功更新次数 = KEY_COUNT * UPDATES_PER_KEY_THREAD * THREAD_COUNT (因为每个 Key 都有 THREAD_COUNT 个线程去更新)
        // 更正：这里的设计是一个线程池执行 KEY_COUNT 个任务，每个任务内部再循环 UPDATES_PER_KEY_THREAD 次更新。
        // 总成功更新次数 = KEY_COUNT * UPDATES_PER_KEY_THREAD * 1 (每个Key由一个任务线程完成所有更新)
        // 进一步修改：让 THREAD_COUNT 个线程去抢 KEY_COUNT 个 Key 的更新机会。

        // 重新定义实验目标：让 THREAD_COUNT 个线程并发地去更新 KEY_COUNT 个 Key。
        // 为了确保重试高发，我们让所有线程都去竞争所有 Key 的更新。

        ExecutorService executor = Executors.newFixedThreadPool(THREAD_COUNT);

        final int TOTAL_UPDATES = THREAD_COUNT * UPDATES_PER_THREAD; // 总的 compute() 调用次数

        System.out.println("--- 启动多 Key 并发重试演示 ---");
        System.out.println("并发线程数: " + THREAD_COUNT);
        System.out.println("实验 Key 数量: " + KEY_COUNT);
        System.out.println("Map 中每个 Key 最终预期计数器值: " + UPDATES_PER_THREAD); // 因为每个线程只对每个Key更新1次，这里简化为每个Key更新UPDATES_PER_THREAD次
        System.out.println("总预期成功更新次数 (Map 内部总和): " + (KEY_COUNT * UPDATES_PER_THREAD));

        // 提交所有线程任务
        for (int i = 0; i < THREAD_COUNT; i++) {
            executor.submit(() -> {
                for (int j = 0; j < UPDATES_PER_THREAD; j++) {
                    // 随机或轮询选择 Key，这里使用轮询确保每个 Key 都会被更新
                    String currentKey = "KEY_" + (j % KEY_COUNT);

                    map.compute(currentKey, (k, oldCtx) -> {

                        // 副作用：在这里记录外部操作。
                        sideEffectCounter.incrementAndGet();

                        // 1. 模拟昂贵的计算
                        try {
                            Thread.sleep(CALCULATION_DELAY_MS);
                        } catch (InterruptedException ignored) {
                            Thread.currentThread().interrupt();
                        }

                        // --- 核心逻辑切换：创建/修改 ---
                        if (oldCtx == null) {
                            // 场景 1: Key 不存在，创建新对象并返回
                            return new Context(k);
                        } else {
                            // 场景 2: Key 存在，在老对象上修改并返回老对象
                            oldCtx.incrementCounter();
                            return oldCtx;
                        }
                    });
                }
            });
        }

        executor.shutdown();
        executor.awaitTermination(60, TimeUnit.SECONDS);

        System.out.println("\n--- 模拟结果 ---");

        int totalExpectedUpdates = KEY_COUNT * UPDATES_PER_THREAD;
        int totalActualUpdates = 0;
        int totalActualSideEffects = sideEffectCounter.get();

        System.out.println("--- 逐个 Key 分析 ---");
        for (int i = 0; i < KEY_COUNT; i++) {
            String key = "KEY_" + i;
            Context finalContext = map.get(key);
            if (finalContext != null) {
                System.out.printf("Key %s | 最终计数: %d%n", key, finalContext.getCounter());
                totalActualUpdates += finalContext.getCounter();
            }
        }

        System.out.println("\n--- 统计摘要 ---");
        System.out.println("1. Map 内部总成功更新次数: " + totalActualUpdates);
        System.out.println("2. 副作用执行次数 (sideEffectCounter): " + totalActualSideEffects);


        if (totalActualSideEffects > totalExpectedUpdates) {
            System.out.println("\n✅ 结论: 副作用被重复执行! (Repetitive Side Effect Triggered)");
            System.out.println("总预期 Map 内部更新次数: " + totalExpectedUpdates);
            System.out.println("额外副作用执行次数 (重试次数): " + (totalActualSideEffects - totalExpectedUpdates));
        } else {
            System.out.println("\n⚠️ 结论: 未检测到明显的重试。");
        }
    }

    public static void main(String[] args) throws InterruptedException {
        new ConcurrentComputeRetryDemo().runDemo();
    }
}
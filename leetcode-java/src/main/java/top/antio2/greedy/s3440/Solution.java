package top.antio2.greedy.s3440;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.function.IntUnaryOperator;

class Solution {

    private class Gap {
        public int len;
        public int left;
        public int right; // 冗余
        public Gap(int len, int left, int right) {
            this.len = len;
            this.left = left;
            this.right = right;
        }

        public boolean isNextTo(int i) {
            return i == left || i == right;
        }
    }


    private class Top3 {
        public List<Gap> top = new ArrayList<Gap>(3);
        public Top3() {
            top.add(new Gap(0, 0 ,0));
            top.add(new Gap(0, 0 ,0));
            top.add(new Gap(0, 0 ,0));
        }
        public void add(Gap a) {
            if (a.len > top.get(2).len) {
                top.set(2, a);
            }

            if (top.get(2).len > top.get(1).len) {
                Collections.swap(top, 2, 1);
            }

            if (top.get(1).len > top.get(0).len) {
                Collections.swap(top, 0, 1);
            }
        }
    }

    

    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        Top3 top3 = new Top3();
        int len = startTime.length;

        top3.add(new Gap(startTime[0], -1, 0));
        top3.add(new Gap(eventTime - endTime[len - 1], len - 1, len));

        for(int i = 0; i < len - 1; i++) {
            top3.add(new Gap(startTime[i + 1] - endTime[i], i, i + 1));
        }
        

        IntUnaryOperator calGap = (i) -> {
            int left, right;
            if(i==0) {
                left = 0;
            } else {
                left = endTime[i - 1];
            }
            if(i == len - 1) {
                right = eventTime;
            } else {
                right = startTime[i + 1];
            }
            return right - left;
        };

        IntUnaryOperator calLen = (i) -> {
            return endTime[i] - startTime[i];
        };

        int ans = top3.top.get(0).len;
        for(int i = 0; i < len; i++) {
            if(!top3.top.get(0).isNextTo(i) && top3.top.get(0).len >= calLen.applyAsInt(i)) {
                ans = Math.max(ans, calGap.applyAsInt(i));
                continue;
            }

            if(!top3.top.get(1).isNextTo(i) && top3.top.get(1).len >= calLen.applyAsInt(i)) {
                ans = Math.max(ans, calGap.applyAsInt(i));
                continue;
            }

            if(top3.top.get(2).len >= calLen.applyAsInt(i)) {
                ans = Math.max(ans, calGap.applyAsInt(i));
                continue;
            }

            ans = Math.max(ans, calGap.applyAsInt(i) - calLen.applyAsInt(i));
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] startTime = {0, 17, };
        int[] endTime = {14, 19};
        Solution s = new Solution();
        int eventTime = 34;
        System.out.println(s.maxFreeTime(eventTime, startTime, endTime));
    }
}
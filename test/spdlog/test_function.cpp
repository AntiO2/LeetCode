#include "spdlog/spdlog.h"
#include "test_function.h"

namespace spdtest{
int add(int a, int b) {
    SPDLOG_INFO("add {} and {}",a, b); // 子文件也能沿用设置的全局logger 和 pattern
    return a + b;
}
}


#include "test_function.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_sinks.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/cfg/env.h"  
#include "spdlog/fmt/ostr.h"


void subtest(); 

int main() {
    auto std_logger = spdlog::stdout_color_mt("console");  // 输出到fd 1
    auto err_logger = spdlog::stderr_color_mt("stderr"); // 输出到fd 2。
    SPDLOG_LOGGER_INFO(std_logger, "打印信息", "print info", "stdout");

    err_logger->set_level(spdlog::level::debug); 
    err_logger->set_pattern("%^[%l] [%T.%e]%$ [thread %t] [(%s):%!:%#] %v"); // 设置全局打印的格式。 感觉这样比较舒服
    err_logger->debug("jugg"); // debug level还不知道怎么用。。感觉有问题。。。 设置的pattern，macro没用
    spdlog::set_default_logger(err_logger); // 设置全局logger
    // spdlog::set_level(spdlog::level::debug); // 好像没用，这里。
    SPDLOG_INFO("dota2"); // 使用全局logger
    SPDLOG_DEBUG("lol"); // 默认为info level。 从低到高(应该是)： trace debug info warn critical
    SPDLOG_WARN("1999"); // 警告信息
    SPDLOG_CRITICAL("genshin impact"); // 错误信息

    subtest(); // 模拟子模块
}

void subtest() { 
    SPDLOG_INFO("result is {}", spdtest::add(1,2)); 
}

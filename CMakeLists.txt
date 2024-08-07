cmake_minimum_required(VERSION 3.17)

project(LeetCode)
message(${CMAKE_SYSTEM_PROCESSOR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
if (CMAKE_SYSTEM_PROCESSOR MATCHES "x86")
    # 如果系统是 x86，则启用特定的编译选项
    message("Enable AddressSanitizer")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
endif ()
# 启用 AddressSanitizer


# 设置 CMake 构建类型为 Debug
set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(codeforces)
add_subdirectory(codewars)
add_subdirectory(leetcode_cpp) # LC C++解答
add_subdirectory(lab)
add_subdirectory(deps) # 第三方库
add_subdirectory(test) # 实验

include_directories(deps)


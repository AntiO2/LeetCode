cmake_minimum_required(VERSION 3.17)

project(LeetCode)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(solution) # C++解答

include_directories(deps)
add_subdirectory(deps) # 第三方库

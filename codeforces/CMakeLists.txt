include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/deps/fmt/include)
include_directories(${PROJECT_SOURCE_DIR}/deps)
enable_testing()
include(GoogleTest)

file(GLOB_RECURSE SOLUTION_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
message("start to build codeforces solution targets")
foreach (SOLUTION_SOURCE ${SOLUTION_SOURCES})
    get_filename_component(solution_filename ${SOLUTION_SOURCE} NAME)
    string(REPLACE ".cpp" "" solution_name ${solution_filename})
    
    string(CONCAT solution_name "CF" ${solution_name})
    message("detect solution: ${solution_name}")
    add_executable(${solution_name} EXCLUDE_FROM_ALL ${SOLUTION_SOURCE})
    gtest_discover_tests(${solution_name}
            EXTRA_ARGS
            --gtest_color=auto
            --gtest_catch_exceptions=0
            --verbose
            DISCOVERY_TIMEOUT 120
            PROPERTIES
            TIMEOUT 120
            )

    target_link_libraries(${solution_name} gtest gmock_main fmt)

    # Set test target properties and dependencies.
    #    set_target_properties(${solution_name}
    #            PROPERTIES
    #            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
    #            COMMAND ${solution_name}
    #            )
endforeach ()
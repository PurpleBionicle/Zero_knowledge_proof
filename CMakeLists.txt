cmake_minimum_required(VERSION 3.17)
project(authentication_protocol)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(authentication_protocol main.cpp)

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)
    file(GLOB \${PROJECT_NAME}_TEST_SOURCES test.cpp)
    add_executable(check \${\${PROJECT_NAME}_TEST_SOURCES})
    target_link_libraries(check \${PROJECT_NAME} gtest_main)
    add_test(NAME check COMMAND check)
endif()
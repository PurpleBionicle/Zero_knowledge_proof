cmake_minimum_required(VERSION 3.17)
project(authentication_protocol)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(protocol main.cpp header.hpp point.hpp test.cpp)
add_subdirectory(third-party/gtest)
#add_executable(Google_Tests_run test.cpp)

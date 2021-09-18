cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(
        HUNTER_CACHE_SERVERS
        "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
        CACHE STRING "Default cache server"
)
include("cmake/tools/gate/cmake/HunterGate.cmake")

HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.314.tar.gz"
        SHA1 "95c47c92f68edb091b5d6d18924baabe02a6962a"
)

project(authentication_protocol)

hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)

#set(CMAKE_MODULE_PATH "/home/gmp_build/lib;${CMAKE_MODULE_PATH}")
#find_package(GMP REQUIRED)

add_library(${PROJECT_NAME} STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/header.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/point.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/curve.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/server.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/client.hpp)

add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)

#target_link_libraries(demo gmp libgmp)

add_executable(tests test.cpp)

target_link_libraries(tests PUBLIC GTest::gtest_main)
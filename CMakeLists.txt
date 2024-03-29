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

hunter_add_package(nlohmann_json)
find_package(nlohmann_json 3.2.0 REQUIRED)
hunter_add_package(GTest)
find_package(GTest CONFIG REQUIRED)


include_directories(${PROJECT_NAME} ${GMP_DIR}/include)
find_library(GMP_LIBRARY NAMES gmp PATHS "/usr/local/lib")


add_library(${PROJECT_NAME} STATIC
        realization/hpp/header.hpp
        realization/hpp/point.hpp
        realization/hpp/curve.hpp
        realization/hpp/server.hpp
        realization/main.cpp
        realization/hpp/client.hpp
        realization/hpp/attacker.hpp
        )

add_executable(demo realization/main.cpp)

target_link_libraries(demo gmp nlohmann_json::nlohmann_json -lgmpxx )

add_executable(tests realization/test.cpp)



target_link_libraries(tests PUBLIC GTest::gtest_main gmp -lgmpxx -lgmp)
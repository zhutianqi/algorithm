cmake_minimum_required(VERSION 3.16)
project(algorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------- 头文件路径 ---------
include_directories(${CMAKE_SOURCE_DIR}/include)

# --------- 自动搜集 src 下的 cpp ---------
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# --------- 编译成静态库 ---------
add_library(algo STATIC ${SRC_FILES})

# --------- 主程序 ---------
add_executable(app app/main.cpp)
target_link_libraries(app PRIVATE algo)

# --------- GoogleTest (可选) ---------
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)
add_executable(unit_tests ${TEST_FILES})
target_link_libraries(unit_tests PRIVATE algo GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(unit_tests)

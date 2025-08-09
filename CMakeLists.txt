cmake_minimum_required(VERSION 3.16)
# --------- cmake Xcode ---------
set(CMAKE_OSX_DEPLOYMENT_TARGET "14.6" CACHE STRING "Minimum OS X deployment version")

project(algorithm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------- 头文件路径 ---------
include_directories(${CMAKE_SOURCE_DIR}/include)

# --------- 自动搜集 src 下的 cpp ---------
file(GLOB_RECURSE SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB CONFIGURE_DEPENDS TEST_FILES ${CMAKE_SOURCE_DIR}/tests/*.cpp)
foreach(test_src ${TEST_FILES})
  get_filename_component(test_name ${test_src} NAME_WE)
  add_executable(${test_name}_tests ${test_src})
  target_link_libraries(${test_name}_tests PRIVATE algo GTest::gtest_main)
  gtest_discover_tests(${test_name}_tests)
endforeach()

# --------- 编译成静态库 ---------
add_library(algo STATIC ${SRC_FILES})

# --------- hpp ---------
file(GLOB_RECURSE HDRS CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/include/*.hpp)
target_sources(algo PUBLIC ${HDRS})

# ---- 让 README 和顶层 CMakeLists 也显示在 IDE 里 ----
set(META_FILES
    ${CMAKE_SOURCE_DIR}/README.md
    ${CMAKE_SOURCE_DIR}/CMakeLists.txt
)

target_sources(algo PRIVATE ${META_FILES})
# 标记为“只读源文件”，避免被当作可编译文件
set_source_files_properties(${META_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)

# 分组（Xcode/VS 可见更清晰）
source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${SRC_FILES} ${HDRS} ${META_FILES})

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
gtest_discover_tests(unit_tests DISCOVERY_MODE PRE_TEST)


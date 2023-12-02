cmake_minimum_required(VERSION 3.25)
project(AdventOfCodeCpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

set(PUZZLE_CLASSES
        utils.cpp

        2022/day01/day01.cpp
        2022/day02/day02.cpp

        2023/day01/day01.cpp
        2023/day02/Day02.cpp
)

add_executable(
        AdventOfCodeCpp
        main.cpp
        ${PUZZLE_CLASSES}
)

add_executable(
        AdventOfCodeCppTest
        ${PUZZLE_CLASSES}
        2022/day01/day01_test.cpp
        2023/day01/day01_test.cpp
        2023/day02/Day02_test.cpp
)

target_link_libraries(
        AdventOfCodeCppTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(AdventOfCodeCppTest)

cmake_minimum_required(VERSION 3.11) # at least 3.11 required for FetchContent

# Set the project name
project(MatrixPathTest)

# Include FetchContent module
include(FetchContent)

# Declare GoogleTest as a content we want to fetch
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)

# Fetch GoogleTest
FetchContent_MakeAvailable(googletest)

# Set the C++ standard version
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Add your .cpp file
add_definitions(-Wno-maybe-uninitialized)
add_executable(MatrixPathTest
    matrixPath_test.cpp
)

# Link against GoogleTest library
target_link_libraries(MatrixPathTest gtest_main)

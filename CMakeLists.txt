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
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
  target_compile_options(gtest PRIVATE -Wno-maybe-uninitialized)
  target_compile_options(gtest_main PRIVATE -Wno-maybe-uninitialized)
endif()


# Set the C++ standard version
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Add your .cpp file
add_executable(MatrixPathTest
    matrixPath_test.cpp
)

# Link against GoogleTest library
target_link_libraries(MatrixPathTest gtest_main)

# Add your second .cpp file
add_executable(matrixMdimSumTest
    matrixMdimSum_test.cpp
)

# Link against GoogleTest library
target_link_libraries(matrixMdimSumTest gtest_main)

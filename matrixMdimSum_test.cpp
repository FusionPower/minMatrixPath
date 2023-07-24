#include <gtest/gtest.h>
#include <vector>
#include "matrixMdimSum.h"


// Test when the matrix has one element.
TEST(findMDimMinSumTest, HandlesSingleElement) {
  std::vector<std::vector<int>> matrix = {{7}};
  auto result = findMDimMinSum(matrix, 1, 2);
  EXPECT_EQ(std::get<int>(result), 7);
}

// Test when the matrix is 2x2.
TEST(findMDimMinSumTest, HandlesTwoByTwoMatrix) {
    std::vector<std::vector<int>> matrix = {
        {1, 3}, 
        {2, 4}
    };
    auto result = findMDimMinSum(matrix, 2, 2);
    EXPECT_EQ(std::get<int>(result), 7);
}

// Test when the matrix is 3x3.
TEST(findMDimMinSumTest, HandlesThreeByThreeMatrix) {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 1}, 
        {1, 5, 1}, 
        {4, 2, 1}
    };
    auto result = findMDimMinSum(matrix, 3, 2);
    EXPECT_EQ(std::get<int>(result), 7);
}

// Test when the matrix is 3x3x3.
TEST(findMDimMinSumTest, HandlesThreeByThreeByThreeMatrix) {
  std::vector<std::vector<std::vector<int>>> matrix = {
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}
  };
  auto result = findMDimMinSum(matrix, 3, 3);
  EXPECT_EQ(std::get<int>(result), 9);
}

// Test when the matrix is 2x2 with doubles.
TEST(findMDimMinSumTest, HandlesTwoByTwoMatrixDouble) {
    std::vector<std::vector<double>> matrix = {
        {1.1, 3.1}, 
        {2.1, 4.1}
    };
    auto result = findMDimMinSum(matrix, 2, 2);
    EXPECT_EQ(std::get<double>(result), 7.3);
}


// Test when the matrix is 3x3x3 with doubles.
TEST(findMDimMinSumTest, HandlesThreeByThreeByThreeMatrixDouble) {
  std::vector<std::vector<std::vector<double>>> matrix = {
    {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}}, 
    {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}}, 
    {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}}
  };
  auto result = findMDimMinSum(matrix, 3, 3);
  EXPECT_EQ(std::get<double>(result), 9.7);
}

// Test when matrix is 2x2 with floats.
TEST(findMDimMinSumTest, HandlesTwoByTwoMatrixFloat) {
    std::vector<std::vector<float>> matrix = {
        {1.1, 3.1}, 
        {2.1, 4.1}
    };
    auto result = findMDimMinSum(matrix, 2, 2);
    EXPECT_NEAR(std::get<float>(result), 7.3, 1e-5f);
}

// Test when matrix is 3x3x3 with floats.
TEST(findMDimMinSumTest, HandlesThreeByThreeByThreeMatrixFloat) {
  std::vector<std::vector<std::vector<float>>> matrix = {
    {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}}, 
    {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}}, 
    {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}}
  };
  auto result = findMDimMinSum(matrix, 3, 3);
  EXPECT_NEAR(std::get<float>(result), 9.7f, 1e-5f);
}

// Test when matrix is 2x2 with long.
TEST(findMDimMinSumTest, HandlesTwoByTwoMatrixLong) {
    std::vector<std::vector<long>> matrix = {
        {1, 3}, 
        {2, 4}
    };
    auto result = findMDimMinSum(matrix, 2, 2);
    EXPECT_EQ(std::get<long>(result), 7);
}

// Test when matrix is 3x3x3 with long.
TEST(findMDimMinSumTest, HandlesThreeByThreeByThreeMatrixLong) {
  std::vector<std::vector<std::vector<long>>> matrix = {
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}
  };
  auto result = findMDimMinSum(matrix, 3, 3);
  EXPECT_EQ(std::get<long>(result), 9);
}

// Test when matrix is 2x2 with short.
TEST(findMDimMinSumTest, HandlesTwoByTwoMatrixShort) {
    std::vector<std::vector<short>> matrix = {
        {1, 3}, 
        {2, 4}
    };
    auto result = findMDimMinSum(matrix, 2, 2);
    EXPECT_EQ(std::get<short>(result), 7);
}

// Test when matrix is 3x3x3 with short.
TEST(findMDimMinSumTest, HandlesThreeByThreeByThreeMatrixShort) {
  std::vector<std::vector<std::vector<short>>> matrix = {
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}
  };
  auto result = findMDimMinSum(matrix, 3, 3);
  EXPECT_EQ(std::get<short>(result), 9);
}

// Test when matrix is 2x2 with unsigned.
TEST(findMDimMinSumTest, HandlesTwoByTwoMatrixUnsigned) {
    std::vector<std::vector<unsigned>> matrix = {
        {1, 3}, 
        {2, 4}
    };
    auto result = findMDimMinSum(matrix, 2, 2);
    EXPECT_EQ(std::get<unsigned>(result), 7);
}

// Test when matrix is 3x3x3 with unsigned.
TEST(findMDimMinSumTest, HandlesThreeByThreeByThreeMatrixUnsigned) {
  std::vector<std::vector<std::vector<unsigned>>> matrix = {
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 
    {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}
  };
  auto result = findMDimMinSum(matrix, 3, 3);
  EXPECT_EQ(std::get<unsigned>(result), 9);
}


// Test invalid arg when matrix is 3x4
TEST(findMDimMinSumTest, HandlesThreeByFourMatrix) {
  std::vector<std::vector<int>> matrix = {
    {1, 3, 1, 1}, 
    {1, 5, 1, 1}, 
    {4, 2, 1, 1}
  };
  EXPECT_THROW(findMDimMinSum(matrix, 3, 2), std::invalid_argument);
}

// Test invalid arg when matrix is null
TEST(findMDimMinSumTest, HandlesNullMatrix) {
  std::vector<std::vector<int>> matrix = {};
  EXPECT_THROW(findMDimMinSum(matrix, 3, 2), std::invalid_argument);
}

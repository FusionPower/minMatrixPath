#include <gtest/gtest.h>
#include <vector>
#include "matrixMdimPath.h"


// Test when the matrix has one element.
TEST(findMDimMinSumTest, HandlesSingleElement) {
  std::vector<std::vector<int>> matrix = {{7}};
  auto result = findMDimMinSum(matrix, 1, 1);
  EXPECT_EQ(std::get<int>(result), 7);
}

// Test when the matrix is 2x2.
TEST(findMDimMinSumTest, HandlesTwoByTwoMatrix) {
    std::vector<std::vector<int>> matrix = {
        {1, 3}, 
        {2, 4}
    };
    auto result = findMDimMinSum(matrix, 2, 2);
    // cast variant_vector to int
    EXPECT_EQ(std::get<int>(result), 7);
}

// Test when the matrix is 3x3.
TEST(findMDimMinSumTest, HandlesThreeByThreeMatrix) {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 1}, 
        {1, 5, 1}, 
        {4, 2, 1}
    };
    auto result = findMDimMinSum(matrix, 3, 3);
    // cast variant_vector to int
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
  // cast variant_vector to int
  EXPECT_EQ(std::get<int>(result), 9);
}
#include <gtest/gtest.h>
#include <vector>
#include "matrixPath.h"


// Test when the matrix has one element.
TEST(smallestSumTest, HandlesSingleElement) {
  std::vector<std::vector<int>> matrix = {{7}};
  auto result = smallestSum<int>(matrix);
  EXPECT_EQ(result.first, std::abs(7));
}

// Test when the matrix is 2x2.
TEST(smallestSumTest, HandlesTwoByTwoMatrix) {
  std::vector<std::vector<int>> matrix = {{1, 3}, {2, 4}};
  auto result = smallestSum<int>(matrix);
  EXPECT_EQ(result.first, 7);
}

// Test when the matrix is 3x3.
TEST(smallestSumTest, HandlesThreeByThreeMatrix) {
  std::vector<std::vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  auto result = smallestSum<int>(matrix);
  EXPECT_EQ(result.first, 7);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
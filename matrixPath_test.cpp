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

// Test with doubles.
TEST(smallestSumTest, HandlesDouble) {
  std::vector<std::vector<double>> matrix = {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}};
  auto result = smallestSum<double>(matrix);
  EXPECT_EQ(result.first, 7.7);
}

// Test with floats.
TEST(smallestSumTest, HandlesFloat) {
  std::vector<std::vector<float>> matrix = {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}};
  auto result = smallestSum<float>(matrix);
  EXPECT_EQ(result.first, 7.7);
}

// Test with long.
TEST(smallestSumTest, HandlesLong) {
  std::vector<std::vector<long>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  auto result = smallestSum<long>(matrix);
  EXPECT_EQ(result.first, 7);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
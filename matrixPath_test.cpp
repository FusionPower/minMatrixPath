#include <gtest/gtest.h>
#include <vector>
#include "matrixPath.h"


// Test when the matrix has one element.
TEST(findMinPathTest, HandlesSingleElement) {
  std::vector<std::vector<int>> matrix = {{7}};
  auto result = findMinPath<int>(matrix);
  EXPECT_EQ(result.first, std::abs(7));
}

// Test when the matrix is 2x2.
TEST(findMinPathTest, HandlesTwoByTwoMatrix) {
  std::vector<std::vector<int>> matrix = {{1, 3}, {2, 4}};
  auto result = findMinPath<int>(matrix);
  EXPECT_EQ(result.first, 7);
}

// Test when the matrix is 3x3.
TEST(findMinPathTest, HandlesThreeByThreeMatrix) {
  std::vector<std::vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  auto result = findMinPath<int>(matrix);
  EXPECT_EQ(result.first, 7);
}

// Test with doubles.
TEST(findMinPathTest, HandlesDouble) {
  std::vector<std::vector<double>> matrix = {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}};
  auto result = findMinPath<double>(matrix);
  EXPECT_EQ(result.first, 7.5);
}

// Test with floats.
TEST(findMinPathTest, HandlesFloat) {
  std::vector<std::vector<float>> matrix = {{1.1f, 3.1f, 1.1f}, {1.1f, 5.1f, 1.1f}, {4.1f, 2.1f, 1.1f}};
  auto result = findMinPath<float>(matrix);
  EXPECT_NEAR(result.first, 7.5f, 1e-5f);
}

// Test with long.
TEST(findMinPathTest, HandlesLong) {
  std::vector<std::vector<long>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  auto result = findMinPath<long>(matrix);
  EXPECT_EQ(result.first, 7);
}

// Test correct path with int 3x3 matrix.
TEST(findMinPathTest, HandlesThreeByThreeMatrixPath) {
  std::vector<std::vector<int>> matrix = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  auto result = findMinPath<int>(matrix);
  std::vector<std::pair<int, int>> path = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}};
  EXPECT_EQ(result.second, path);
}

// Test correct path with float 3x3 matrix.
TEST(findMinPathTest, HandlesThreeByThreeMatrixPathFloat) {
  std::vector<std::vector<float>> matrix = {{1.1f, 3.1f, 1.1f}, {1.1f, 5.1f, 1.1f}, {4.1f, 2.1f, 1.1f}};
  auto result = findMinPath<float>(matrix);
  std::vector<std::pair<int, int>> path = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}};
  EXPECT_EQ(result.second, path);
}

// Test correct path with double 3x3 matrix.
TEST(findMinPathTest, HandlesThreeByThreeMatrixPathDouble) {
  std::vector<std::vector<double>> matrix = {{1.1, 3.1, 1.1}, {1.1, 5.1, 1.1}, {4.1, 2.1, 1.1}};
  auto result = findMinPath<double>(matrix);
  std::vector<std::pair<int, int>> path = {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 2}};
  EXPECT_EQ(result.second, path);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
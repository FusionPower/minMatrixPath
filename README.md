[![C++ CI](https://github.com/FusionPower/minMatrixPath/actions/workflows/main.yml/badge.svg)](https://github.com/FusionPower/minMatrixPath/actions/workflows/main.yml)

# minMatrixPath

## Description
`minMatrixPath` is a C++ library that finds the minimum sum path in a square matrix from `(0,0)` to `(n-1,n-1)`. The path can only move down or to the right.

The space complexity of the algorithm is O(1) and time complexity is O(n^2), making it efficient even for larger matrices.

## Building and Running Tests

You can build and test the project using the following commands:

```sh
mkdir build
cd build
cmake ..
make
./MatrixPathTest

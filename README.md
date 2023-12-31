[![C++ CI](https://github.com/FusionPower/minMatrixPath/actions/workflows/main.yml/badge.svg)](https://github.com/FusionPower/minMatrixPath/actions/workflows/main.yml)

# minMatrixPath

## Description
`minMatrixPath` is a C++ library that finds the minimum sum path in a square matrix from `(0,0)` to `(n-1,n-1)`. The path can only move down or to the right.

The space complexity of the algorithm is O(1) and time complexity is O(N^2). To keep the memory constant, the algorithm modifies tha matrix in-place. This also means that it can't support negative numbers in the path. To support them, I'd have to use O(N^2) memory.
## Building and Running Tests

You can build and test the project using the following commands:

```sh
mkdir build
cd build
cmake ..
make
./MatrixPathTest
./MatrixMdimSumTest
```

## matrixPath.h

*This works for 2D matrices with positive numbers!*

The main function in this library is findMinPath. The first element in the output is the minSum, the second element is the minPath to get there.

## matrixMdimSum.h

*WORKS WITH C++ 17 ->*
*This works for matrices that are N^M dimentional with N>=1 and M>=2*

The main function in this library is findMDimMinSum. This returns the minSum in a variant_vector, so remember to cast it to the type you used in your matrix via:

```cpp
std::get<int>(result)
```


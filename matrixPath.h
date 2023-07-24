#ifndef MATRIXPATH_H_
#define MATRIXPATH_H_

#include <vector>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <utility>

/*
Assumptions:
- weights in matrix are positive
- matrix info doesn't need to be preserved
*/

void throwIfNegative(int i, int j){
    throw std::invalid_argument("Found negative element in position (" + std::to_string(i) + ", " + std::to_string(j) + ").");
}

template <typename T>
void preprocessMatrix(std::vector<std::vector<T>>& matrix, int n) {
    /*
    find the best element between i-1,j and i,j-1 to add to the current element to
    for every element in the matrix, except the first row and column.
    */

    // Update first row and column
    for(int i=1; i<n; i++){
        if (matrix[i][0]<0){
            throwIfNegative(i,0);
        }
        if (matrix[0][i]<0){
            throwIfNegative(0,i);
        }
        matrix[i][0] += matrix[i-1][0];
        matrix[0][i] = -(std::abs(matrix[0][i-1])+std::abs(matrix[0][i]));
    }
    // Update the rest of the matrix
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if (matrix[i][j]<0){
                throwIfNegative(i,j);
            }
            if(std::abs(matrix[i][j-1]) < std::abs(matrix[i-1][j])){
                matrix[i][j] = -std::abs(matrix[i][j-1]) - matrix[i][j];
            } else {
                matrix[i][j] = std::abs(matrix[i-1][j]) + matrix[i][j];
            }
        }
    }
}

template <typename T>
std::vector<std::pair<int, int>> backtrackPath(std::vector<std::vector<T>>& matrix, int n){
    /*
    backtrack from the bottom right corner to the top left corner to find the path
    */
	std::vector<std::pair<int, int>> path;
    int i = n-1;
	int j = n-1;
	while (~i!=0 && ~j!=0) {
		if (matrix[i][j]<0){
			path.push_back(std::make_pair(i, j));
			j-=1;
		}
		else {
			path.push_back(std::make_pair(i, j));
			i-=1;
		}

	}
	std::reverse(path.begin(), path.end());
    return path;
}

template <typename T>
std::pair <T, std::vector<std::pair<int, int>>> findMinPath(std::vector<std::vector<T>>& matrix) {
    /*
    Returns minimum path sum and shortest path
    */ 
    if (matrix.empty() || matrix.size() != matrix[0].size()) {
        throw std::invalid_argument("Matrix must be non-empty and square.");
    }
    int n = matrix.size();
    
    preprocessMatrix(matrix, n);
    std::vector<std::pair<int, int>> path = backtrackPath(matrix, n);
    return {std::abs(matrix[n-1][n-1]), path};
}

#endif  // MATRIXPATH_H_

#ifndef MATRIXPATH_H_
#define MATRIXPATH_H_

#include <vector>
#include <cmath>

/*
Assumptions:
- weights in matrix are positive
- matrix info doesn't need to be preserved
*/

template <typename T>
// Returns minimum path sum and shortest path
std::pair <T, std::vector<std::pair<int, int>>> findMinPath(std::vector<std::vector<T>>& matrix) {
    if (matrix.empty() || matrix.size() != matrix[0].size()) {
        throw std::invalid_argument("Matrix must be non-empty and square.");
    }
    
    int n = matrix.size();
	
	std::vector<std::pair<int, int>> path;
    for(int i=1; i<n; i++){
        matrix[i][0] += matrix[i-1][0];
        matrix[0][i] = -(std::abs(matrix[0][i-1])+std::abs(matrix[0][i]));
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(std::abs(matrix[i][j-1]) < std::abs(matrix[i-1][j])){
                matrix[i][j] = -std::abs(matrix[i][j-1]) - matrix[i][j];
            } else {
                matrix[i][j] = std::abs(matrix[i-1][j]) + matrix[i][j];
            }
        }
    }
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
    return {std::abs(matrix[n-1][n-1]), path};
}

#endif  // MATRIXPATH_H_

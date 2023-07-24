#ifndef MDIMMATRIXSUM_H_
#define MDIMMATRIXSUM_H_


#include <vector>
#include <iostream>
#include <type_traits>
#include <variant>

using variant_vector = std::variant<int, long, unsigned, short, float, double>;

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;



// TODO add more datatypes
auto variant_visitor = overloaded{
    [](int arg) { std::cout << arg; },
    [](float arg) { std::cout << arg; },
    [](double arg) { std::cout << arg; },
    [](long arg) { std::cout << arg; },
    [](unsigned arg) { std::cout << arg; },
    [](short arg) { std::cout << arg; },
};

template<typename T>
void updateMatrix(std::vector<T>& matrix, const T& new_value,const std::vector<int>& indices, int dim) {
        matrix[indices[dim]] = new_value;
}

template<typename T, typename T2>
void updateMatrix(std::vector<T>& matrix, const T2& new_value,const std::vector<int>& indices, int dim = 0) {
    updateMatrix(matrix[indices[dim]], new_value, indices, dim + 1);
}

template<typename T>
variant_vector getWeight(const T& weight, const std::vector<int>& indices, int dim) {
    return weight;
}

template<typename T>
variant_vector getWeight(const std::vector<T>& matrix, const std::vector<int>& indices, int dim = 0) {
    return getWeight(matrix[indices[dim]], indices, dim + 1);
}

template<typename T, typename Matrix>
void preprocessMatrix(const T& cellWeight, Matrix& matrix, std::vector<int> indexes) {
    /*
    Once an element is found, it is compared against all the posible paths that lead
    to that element. The path with the minimum weight is chosen and the matrix is updated.
    */    
    int m = indexes.size();
    variant_vector minWeightYet;
    int minIndex = -1;
    // Flag to initialize element the minWeightYet
    bool revisedOneElement = false;

    // Find the min weight that this cell should choose
    for (int i = 0; i < m; i++) {
        if (indexes[i]==0)
            continue;
        indexes[i]-=1;
        variant_vector weightFound = getWeight(matrix,indexes);
        if (!revisedOneElement || weightFound < minWeightYet){
            minWeightYet = weightFound;
            minIndex = i;
        }
        indexes[i]+=1;
        revisedOneElement = true;
    }
    // update the matrix current cell with the min weight
    if (revisedOneElement){
        if (std::holds_alternative<T>(minWeightYet)){
            T minWeight = std::get<T>(minWeightYet);
            minWeight += cellWeight;
            updateMatrix(matrix, minWeight, indexes);
        }
    }
    
}

template<typename T, typename Matrix>
void preprocessMatrix(const std::vector<T>& vec, Matrix& matrix, std::vector<int> indexes) {
    /*
    Recursively finds the elements on the matrix
    */ 
    int n = vec.size();
    // Get a matrix position to explore
    for (int i = 0; i < n; i++) {
        indexes.push_back(i);
        preprocessMatrix(vec[i], matrix, indexes);
        indexes.pop_back();
    }
}

template<typename T>
void printFlattenedMatrix(const T& el, std::vector<int> indexes) {
    std::cout << el << " ";
}

template<typename T>
void printFlattenedMatrix(const std::vector<T>& vec, std::vector<int> indexes) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        indexes.push_back(i);
        printFlattenedMatrix(vec[i], indexes);
        indexes.pop_back();
    }
}

template<typename T>
variant_vector findMDimMinSum(std::vector<T>& matrix, int n, int m) {
    /*
    Returns minimum path sum from an N^M matrix
    */ 
    // Initialize vectors for starting and ending positions
    std::vector<int> startIndices (m, 0);
    std::vector<int> endIndices (m, n-1);
    // Initialize indexes util for matrix preprocess
    std::vector<int> indexes;
    // Preprocess matrix
    preprocessMatrix(matrix, matrix, indexes);
    // Get answer
    variant_vector min_sum = getWeight(matrix, endIndices);
    return min_sum;
}

#endif // MDIMMATRIXSUM_H_
#include <vector>
#include <iostream>
#include <type_traits>
#include <variant>

using variant_vector = std::variant<int, float, double, std::vector<int>, std::vector<float>, std::vector<double>>;

template<class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts> overloaded(Ts...) -> overloaded<Ts...>;

std::vector<std::vector<int>> path;


// TODO add more datatypes
auto variant_visitor = overloaded{
    [](int arg) { std::cout << arg; },
    [](float arg) { std::cout << arg; },
    [](double arg) { std::cout << arg; },
    [](const std::vector<int>& arg) { 
        for(const auto& el : arg) std::cout << el << " "; 
    },
    [](const std::vector<float>& arg) { 
        for(const auto& el : arg) std::cout << el << " "; 
    },
    [](const std::vector<double>& arg) { 
        for(const auto& el : arg) std::cout << el << " "; 
    }
};

template<typename T>
void updateDP(std::vector<T>& dp, const T& new_value,const std::vector<int>& indices, int dim) {
        dp[indices[dim]] = new_value;
}

template<typename T, typename T2>
void updateDP(std::vector<T>& dp, const T2& new_value,const std::vector<int>& indices, int dim = 0) {
    updateDP(dp[indices[dim]], new_value, indices, dim + 1);
}

template<typename T>
variant_vector compareAgainst(const T& el, const std::vector<int>& indices, int dim) {
    return el;
}

template<typename T>
variant_vector compareAgainst(const std::vector<T>& matrix, const std::vector<int>& indices, int dim = 0) {
    return compareAgainst(matrix[indices[dim]], indices, dim + 1);
}

template<typename T, typename Matrix>
void processElement(const T& el, Matrix& originalMatrix, std::vector<int> indexes, Matrix& dp) {  
    // TODO deal with all 0's indexes  
    int m = indexes.size();
    variant_vector element;
    int minIndex = -1;
    bool revised = false;
    for (int i = 0; i < m; i++) {
        if (indexes[i]==0)
            continue;
        indexes[i]-=1;
        variant_vector current = compareAgainst(originalMatrix,indexes);
        if (!revised || current < element){
            element = current;
            minIndex = i;
        }
        indexes[i]+=1;
        revised = true;
    }

    if (minIndex!=-1){
        if (std::holds_alternative<int>(element)){
            T element_value = std::get<T>(element);
            element_value += el;
            updateDP(dp, element_value, indexes);
        }
    }
}

template<typename T, typename Matrix>
void processElement(const std::vector<T>& vec, Matrix& originalMatrix, std::vector<int> indexes, Matrix& dp) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        indexes.push_back(i);
        processElement(vec[i], originalMatrix, indexes, dp);
        indexes.pop_back();
    }
}

template<typename T>
std::vector<T> copyWithMaxValue(const std::vector<T>& original) {
    std::vector<T> copy(original.size(), std::numeric_limits<T>::max());
    return copy;
}

template<typename T>
std::vector<std::vector<T>> copyWithMaxValue(const std::vector<std::vector<T>>& original) {
    std::vector<std::vector<T>> copy;
    for (const auto& inner_vector : original) {
        copy.push_back(copyWithMaxValue(inner_vector));
    }
    return copy;
}

int main() {
    // 3D matrix of size 3x3x3
    std::vector<std::vector<std::vector<int>>> matrix = {
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
        {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}
    };

    std::vector<int> indexes;
    std::vector<std::vector<std::vector<int>>> dp = copyWithMaxValue(matrix);

    processElement(matrix, matrix, indexes, dp);
    variant_vector min_sum = compareAgainst(dp, {2, 2, 2});
    std::visit(variant_visitor, min_sum);
    
    return 0;
}

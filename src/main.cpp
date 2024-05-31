#include "mergesort.h"
#include <iostream>
#include <vector>

int main() {
    // Exemplo 1: Vetor de inteiros desordenado
    std::vector<int> vec1 = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "Vetor desordenado 1: ";
    for (const auto &val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    mergesort_recursive(vec1);

    std::cout << "Vetor ordenado 1: ";
    for (const auto &val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Exemplo 2: Vetor de inteiros com valores repetidos
    std::vector<int> vec2 = {5, 3, 8, 3, 2, 7, 1, 4, 1};
    std::cout << "Vetor desordenado 2: ";
    for (const auto &val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    mergesort_recursive(vec2);

    std::cout << "Vetor ordenado 2: ";
    for (const auto &val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Exemplo 3: Vetor de inteiros já ordenado
    std::vector<int> vec3 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Vetor desordenado 3: ";
    for (const auto &val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    mergesort_recursive(vec3);

    std::cout << "Vetor ordenado 3: ";
    for (const auto &val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

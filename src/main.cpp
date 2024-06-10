#include "mergesort.h"
#include "timeit.h"
#include <iostream>
#include <vector>

bool is_sorted(const std::vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] < v[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> vec1 = {38, 27, 43, 3, 9, 82, 10, 34, 32, 56, 74, 23};
    std::cout << "Vetor desordenado 1: ";
    for (const auto &val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    TIME_IT({
        mergesort(vec1);
    });

    std::cout << "Vetor ordenado 1: ";
    for (const auto &val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec2 = {5, 3, 12, 8, 3, 2, 10, 11, 7, 1, 4, 9};
    std::cout << "Vetor desordenado 2: ";
    for (const auto &val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    TIME_IT({
        mergesort(vec2);
    });

    std::cout << "Vetor ordenado 2: ";
    for (const auto &val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec3 = {4, 2, 1, 3};
    std::cout << "Vetor desordenado 3: ";
    for (const auto &val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    TIME_IT({
        mergesort(vec3);
    });

    std::cout << "Vetor ordenado 3: ";
    for (const auto &val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<int> vec4(10000);
    for (int i = 0; i < 10000; ++i) {
        vec4[i] = std::rand() % 1000;
    }

    TIME_IT({
        mergesort(vec4);
    });

    if (is_sorted(vec4)) {
        std::cout << "Vec4 is sorted." << std::endl;
    } else {
        std::cout << "Vec4 is NOT sorted." << std::endl;
    }

    return 0;

    return 0;
}

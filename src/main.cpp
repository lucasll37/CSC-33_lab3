#include "mergesort.h"
#include "mergesort_sequential.h"
#include "timeit.h"
#include <iostream>
#include <vector>
#include <ctime>

bool is_sorted(const std::vector<int>& v) {
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] < v[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n = 1000000;

    std::srand(std::time(0)); // Initialize random seed

    std::cout << "CSC-33_lab3\n" << std::endl;
    std::cout << "Alunos: Denys Derlian, Lucas Lima e Rafael Hoffmann" << std::endl;
    std::cout << "MERGESORT (w/ THREADS)\n" << std::endl;

    std::vector<int> vec1 = {38, 27, 43, 3, 9, 82, 10, 34, 32, 56, 74, 23};
    std::cout << "Unsorted vector 1: ";
    for (const auto &val : vec1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Mergesort with threads:" << std::endl;
    TIME_IT({
        mergesort(vec1);
    });

    if (is_sorted(vec1)) {
        std::cout << "Vec1 is sorted. (thread)" << std::endl;
    } else {
        std::cout << "Vec1 is NOT sorted. (thread)" << std::endl;
    }

    std::cout << "Mergesort sequential:" << std::endl;
    TIME_IT({
        mergesort_sequential(vec1);
    });

    if (is_sorted(vec1)) {
        std::cout << "Vec1 is sorted. (sequential)\n" << std::endl;
    } else {
        std::cout << "Vec1 is NOT sorted. (sequential)\n" << std::endl;
    }

    std::vector<int> vec2 = {5, 3, 12, 8, 3, 2, 10, 11, 7, 1, 4, 9};
    std::cout << "Unsorted vector 2: ";
    for (const auto &val : vec2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Mergesort with threads:" << std::endl;
    TIME_IT({
        mergesort(vec2);
    });

    if (is_sorted(vec2)) {
        std::cout << "Vec2 is sorted. (thread)" << std::endl;
    } else {
        std::cout << "Vec2 is NOT sorted. (thread)" << std::endl;
    }

    std::cout << "Mergesort sequential:" << std::endl;
    TIME_IT({
        mergesort_sequential(vec2);
    });

    if (is_sorted(vec2)) {
        std::cout << "Vec2 is sorted. (sequential)\n" << std::endl;
    } else {
        std::cout << "Vec2 is NOT sorted. (sequential)\n" << std::endl;
    }

    std::vector<int> vec3 = {4, 2, 1, 3};
    std::cout << "Unsorted vector 3: ";
    for (const auto &val : vec3) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Mergesort with threads:" << std::endl;
    TIME_IT({
        mergesort(vec3);
    });

    if (is_sorted(vec3)) {
        std::cout << "Vec3 is sorted. (thread)" << std::endl;
    } else {
        std::cout << "Vec3 is NOT sorted. (thread)" << std::endl;
    }

    std::cout << "Mergesort sequential:" << std::endl;
    TIME_IT({
        mergesort_sequential(vec3);
    });

    if (is_sorted(vec3)) {
        std::cout << "Vec3 is sorted. (sequential)\n" << std::endl;
    } else {
        std::cout << "Vec3 is NOT sorted. (sequential)\n" << std::endl;
    }

    std::vector<int> vec4(n);
    std::cout << "Unsorted vector 4 (random) of size " << vec4.size() << std::endl; 
    for (int i = 0; i < n; ++i) {
        vec4[i] = std::rand() % n;
    }

    std::cout << "Mergesort with threads:" << std::endl;
    TIME_IT({
        mergesort(vec4);
    });

    if (is_sorted(vec4)) {
        std::cout << "Vec4 is sorted. (thread)" << std::endl;
    } else {
        std::cout << "Vec4 is NOT sorted. (thread)" << std::endl;
    }

    std::cout << "Mergesort sequential:" << std::endl;
    TIME_IT({
        mergesort_sequential(vec4);
    });

    if (is_sorted(vec4)) {
        std::cout << "Vec4 is sorted. (sequential)\n" << std::endl;
    } else {
        std::cout << "Vec4 is NOT sorted. (sequential)\n" << std::endl;
    }

    return 0;
}
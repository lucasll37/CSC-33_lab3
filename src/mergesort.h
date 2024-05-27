#ifndef MERGESORT_H
#define MERGESORT_H


#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <queue>
#include <math.h>


void _merge(std::vector<int> &v, std::vector<int> &aux, int start, int middle, int end);

void _mergesort_recursive(std::vector<int> &v, std::vector<int> &aux, int start, int end);

void mergesort_recursive(std::vector<int> &v);

#endif // MERGESORT_H

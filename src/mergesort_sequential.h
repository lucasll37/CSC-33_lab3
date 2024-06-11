#ifndef MERGESORT_SEQUENTIAL_H
#define MERGESORT_SEQUENTIAL_H

#include <vector>

void _merge_sequential(std::vector<int>& v, std::vector<int>& aux, int start, int middle, int end);
void _mergesort_sequential(std::vector<int>& v, std::vector<int>& aux, int start, int end);
void mergesort_sequential(std::vector<int>& v);

#endif // MERGESORT_SEQUENTIAL_H
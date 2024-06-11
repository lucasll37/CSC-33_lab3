#include <vector>
#include <iostream>

void _merge_sequential(std::vector<int>& v, std::vector<int>& aux, int start, int middle, int end) {
    int i1 = start;
    int i2 = middle + 1;

    for (int i = start; i <= end; i++) {
        aux[i] = v[i];
    }

    for (int i = start; i <= end; i++) {
        if (i1 > middle) {
            v[i] = aux[i2++];
        } else if (i2 > end) {
            v[i] = aux[i1++];
        } else if (aux[i2] < aux[i1]) {
            v[i] = aux[i2++];
        } else {
            v[i] = aux[i1++];
        }
    }
}

void _mergesort_sequential(std::vector<int>& v, std::vector<int>& aux, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;

     _mergesort_sequential(v, aux, start, middle);
     _mergesort_sequential(v, aux, middle + 1, end);


        _merge_sequential(v, aux, start, middle, end);
    }
}

void mergesort_sequential(std::vector<int>& v) {
    std::vector<int> aux(v.size());
 _mergesort_sequential(v, aux, 0, v.size() - 1);
}

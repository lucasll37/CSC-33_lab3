#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include "mergesort.h"
#include <pthread.h>


typedef struct {
    std::vector<int>& v;
    std::vector<int>& aux;
    int start;
    int middle;
    int end;
} arguments;

void _merge(arguments* args);

void* _mergesort(void* arg);

void mergesort(std::vector<int>& v);

#endif // MERGESORT_H

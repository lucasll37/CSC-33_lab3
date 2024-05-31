#include <pthread.h>
#include <vector>
#include <iostream>

typedef struct {
    std::vector<int>& v;
    std::vector<int>& aux;
    int start;
    int middle;
    int end;
} arguments;

void _merge(arguments* args) {
    std::vector<int>& v = args->v;
    std::vector<int>& aux = args->aux;
    int start = args->start;
    int middle = args->middle;
    int end = args->end;

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

void* _mergesort(void* arg) {
    arguments* args = (arguments*) arg;
    if (args->end <= args->start) {
        return NULL;
    }

    int middle = (args->start + args->end) / 2;
    pthread_t left_thread, right_thread;

    arguments left_args = {args->v, args->aux, args->start, middle, middle};
    arguments right_args = {args->v, args->aux, middle + 1, args->end, args->end};

    pthread_create(&left_thread, NULL, _mergesort, &left_args);
    pthread_create(&right_thread, NULL, _mergesort, &right_args);

    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    _merge(args);

    return NULL;
}

void mergesort(std::vector<int>& v) {
    std::vector<int> aux(v.size());

    arguments main_args = {v, aux, 0, (int)v.size() / 2, (int)v.size() - 1};
    _mergesort(&main_args);
}
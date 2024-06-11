#include <pthread.h>
#include <vector>
#include <iostream>
#include <algorithm> 

#define MAX_DEPTH 4

typedef struct {
    std::vector<int>& v;
    std::vector<int>& aux;
    int start;
    int end;
    int depth;
} arguments;

void _merge(arguments* args) {
    std::vector<int>& v = args->v;
    std::vector<int>& aux = args->aux;
    int start = args->start;
    int middle = (args->start + args->end) / 2;
    int end = args->end;

    int i1 = start;
    int i2 = middle + 1;

    for (int i = start; i <= end; ++i) {
        if (i1 > middle) {
            aux[i] = v[i2++];
        } else if (i2 > end) {
            aux[i] = v[i1++];
        } else if (v[i1] <= v[i2]) {
            aux[i] = v[i1++];
        } else {
            aux[i] = v[i2++];
        }
    }

    for (int i = start; i <= end; ++i) {
        v[i] = aux[i];
    }
}

void* _mergesort(void* arg) {
    arguments args = *(arguments*)arg;
    if (args.start >= args.end) {
        return NULL;
    }

    int middle = (args.start + args.end) / 2;
    arguments left_args = {args.v, args.aux, args.start, middle, args.depth + 1};
    arguments right_args = {args.v, args.aux, middle + 1, args.end, args.depth + 1};

    if (args.depth < MAX_DEPTH) {
        pthread_t left_thread, right_thread;

        if(pthread_create(&left_thread, NULL, _mergesort, &left_args)) {
            std::cerr << "Error: unable to create left thread" << std::endl;
            exit(-1);
        }

        if(pthread_create(&right_thread, NULL, _mergesort, &right_args)) {
            std::cerr << "Error: unable to create right thread" << std::endl;
            exit(-1);
        }

        if(pthread_join(left_thread, NULL)) {
            std::cerr << "Error: unable to join left thread" << std::endl;
            exit(-1);
        }

        if(pthread_join(right_thread, NULL)) {
            std::cerr << "Error: unable to join right thread" << std::endl;
            exit(-1);
        }
    } else {
        std::sort(args.v.begin() + args.start, args.v.begin() + args.end + 1);
    }

    _merge(&args);

    return NULL;
}

void mergesort(std::vector<int>& v) {
    std::vector<int> aux(v);
    arguments main_args = {v, aux, 0, (int)v.size() - 1, 0};

    _mergesort(&main_args);
}
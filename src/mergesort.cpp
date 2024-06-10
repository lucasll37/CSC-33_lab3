#include <pthread.h>
#include <semaphore.h>
#include <vector>
#include <iostream>

//sem_t semaphore;

typedef struct {
    std::vector<int>& v;
    std::vector<int>& aux;
    int start;
    int end;
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
    arguments* args = (arguments*)arg;
    if (args->start >= args->end) {
        return NULL;
    }

    int middle = (args->start + args->end) / 2;
    arguments left_args = {args->v, args->aux, args->start, middle};
    arguments right_args = {args->v, args->aux, middle + 1, args->end};

    pthread_t left_thread, right_thread;

    pthread_create(&left_thread, NULL, _mergesort, &left_args);
    pthread_create(&right_thread, NULL, _mergesort, &right_args);

    pthread_join(left_thread, NULL);
    pthread_join(right_thread, NULL);

    _merge(args);

//    sem_post(&semaphore);

    return NULL;
}

void mergesort(std::vector<int>& v) {
    std::vector<int> aux(v.size());
    arguments main_args = {v, aux, 0, (int)v.size() - 1};

//    sem_init(&semaphore, 0, 0);

    _mergesort(&main_args);

//    sem_wait(&semaphore);

//    sem_destroy(&semaphore);
}

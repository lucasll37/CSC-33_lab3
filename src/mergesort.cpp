
#include "mergesort.h"
#include <pthread.h>
#include <semaphore.h>

typedef struct {
    std::vector<int> v;
    std::vector<int> aux;
    int start;
    int middle;
    int end;
} argments;

sem_t sem;

void _merge(void* arg) {
    argments* arg = (argments*)arg;
    
    std::vector<int> v = arg->aux;
    std::vector<int> aux = arg->aux;
    
    int start = arg->start;
    int middle = arg->middle;
    int end = arg->end;

    int i1 = start;
    int i2 = start;
    int i3 = middle + 1;


    while(i2 <= middle && i3 <= end) {
        if(v[i2] < v[i3]) {
            aux[i1++] = v[i2++];
        }
        else {
            aux[i1++] = v[i3++];
        }
    }
    while(i2 <= middle){
        aux[i1++] = v[i2++];
    }
    while(i3 <= end){
        aux[i1++] = v[i3++];
    }

   for(int i = start; i <= end; i++) {
      v[i] = aux[i];
   }
}

void *_mergesort(void* arg) {
    argments* arg = (argments*)arg;
    
    std::vector<int> v = arg->aux;
    std::vector<int> aux = arg->aux;
    int start = arg->start;
    int end = arg->end;

    if(end > start){
        int middle = (start + end)/2;

        pthread_t tid1, tid2;
       
        argments arg1 = {
            .v = v,
            .aux = aux,
            .start = start,
            .end = middle
        };

        argments arg2 = {
            .v = v,
            .aux = aux,
            .start = middle + 1,
            .end = end
        };

        pthread_create(&tid1, NULL, _mergesort, (void*)&arg1);
        pthread_create(&tid2, NULL, _mergesort, (void*)&arg2);

        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

        _merge(v, aux, start, middle, end);

        pthread_exit(NULL);
    }
}

void mergesort_recursive(std::vector<int> &v) {
    std::vector<int> aux(v.size());
    _mergesort_recursive(v, aux, 0, v.size()-1);
}
#include "mergesort.h"
#include <pthread.h>
#include <semaphore.h>

typedef struct {
    std::vector<int>* v;
    std::vector<int>* aux;
    int start;
    int middle;
    int end;
} argments;

sem_t sem;

void _merge(void* arg) {
    argments* args = (argments*)arg;
    
    std::vector<int>& v = *(args->v);
    std::vector<int>& aux = *(args->aux);
    
    int start = args->start;
    int middle = args->middle;
    int end = args->end;

    int i1 = start;
    int i2 = start;
    int i3 = middle + 1;

    while(i2 <= middle && i3 <= end) {
        if(v[i2] < v[i3]) {
            aux[i1++] = v[i2++];
        } else {
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
    argments* args = (argments*)arg;
    
    std::vector<int>& v = *(args->v);
    std::vector<int>& aux = *(args->aux);
    int start = args->start;
    int end = args->end;

    if(end > start){
        int middle = (start + end) / 2;

        pthread_t tid1, tid2;
       
        argments arg1 = {
            .v = &v,
            .aux = &aux,
            .start = start,
            .end = middle
        };

        argments arg2 = {
            .v = &v,
            .aux = &aux,
            .start = middle + 1,
            .end = end
        };

        pthread_create(&tid1, NULL, _mergesort, (void*)&arg1);
        pthread_create(&tid2, NULL, _mergesort, (void*)&arg2);

        pthread_join(tid1, NULL);
        pthread_join(tid2, NULL);

        argments mergeArgs = {
            .v = &v,
            .aux = &aux,
            .start = start,
            .middle = middle,
            .end = end
        };

        _merge((void*)&mergeArgs);

        pthread_exit(NULL);
    }
    return NULL;
}

void mergesort_recursive(std::vector<int> &v) {
    std::vector<int> aux(v.size());
    argments args = {
        .v = &v,
        .aux = &aux,
        .start = 0,
        .end = v.size() - 1
    };
    _mergesort((void*)&args);
}

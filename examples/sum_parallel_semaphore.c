#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include "timeit.h"

long long sum = 0;
sem_t sem;

void *sum_even(void *arg) {
    int n = *(int *)arg;

    for (int i = 2; i <= n; i += 2) {
        sem_wait(&sem);
        sum += i;
        sem_post(&sem);
    }

    pthread_exit(NULL);
}

void *sum_odd(void *arg) {
    int n = *(int *)arg;

    for (int i = 1; i <= n; i += 2) {
        sem_wait(&sem);
        sum += i;
        sem_post(&sem);
    }

    pthread_exit(NULL);
}

int main(void) {
    int n = 10000000;
    pthread_t t1, t2;

    sem_init(&sem, 0, 1);

    TIME_IT(
        pthread_create(&t1, NULL, sum_even, &n);
        pthread_create(&t2, NULL, sum_odd, &n);

        pthread_join(t1, NULL);
        pthread_join(t2, NULL);
    );

    printf("Sum of 1 to %d is %lld\n", n, sum);

    sem_destroy(&sem);

    return 0;
}

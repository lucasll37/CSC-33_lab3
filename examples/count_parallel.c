#include <stdio.h>
#include <pthread.h>

long long sum = 0;

void *sum_even(void *arg) {
    int n = *(int *)arg;

    for (int i = 2; i <= n; i += 2) {
        sum += i;
    }

    pthread_exit(NULL);
}

void *sum_odd(void *arg) {
    int n = *(int *)arg;

    for (int i = 1; i <= n; i += 2) {
        sum += i;
    }

    pthread_exit(NULL);
}

int main(void) {
    int n = 10000000;
    pthread_t t1, t2;

    pthread_create(&t1, NULL, sum_even, &n);
    pthread_create(&t2, NULL, sum_odd, &n);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Sum of 1 to %d is %lld\n", n, sum);

    return 0;
}

#include <stdio.h>
#include <pthread.h>

void *factorial(void *arg) {
    int n = *(int*)arg;

    int result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    printf("Factorial of %d is %d\n", n, result);

    return NULL;
}

int main(void) {
    int n1 = 5, n2 = 6;

    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, factorial, &n1);
    pthread_create(&tid2, NULL, factorial, &n2);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}


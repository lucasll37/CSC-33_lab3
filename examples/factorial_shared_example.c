#include <stdio.h>
#include <pthread.h>

int factorial_n;
int factorial_return;

void *factorial(void *arg) {
    int result = 1;

    for (int i = 1; i <= factorial_n; i++) {
        result *= i;
    }

    factorial_return = result;

    return NULL;
}

int main(void) {
    pthread_t tid;

    factorial_n = 5;
    pthread_create(&tid, NULL, factorial, NULL);

    pthread_join(tid, NULL);

    printf("Factorial of %d is %d\n", factorial_n, factorial_return);

    return 0;
}


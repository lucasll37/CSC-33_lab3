#include <stdio.h>

void factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    printf("Factorial of %d is %d\n", n, result);
}

int main(void) {
    int n1 = 5, n2 = 6;
    factorial(n1);
    factorial(n2);
    return 0;
}


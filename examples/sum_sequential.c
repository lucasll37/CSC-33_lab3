#include <stdio.h>

long long sum (int n) {
    long long sum_result = 0;
    
    for (int i = 1; i <= n; i++) {
        sum_result += i;
    }

    return sum_result;
}
int main(void) {
    int n = 10000000;

    printf("Sum of 1 to %d is %lld\n", n, sum(n));

    return 0;
}

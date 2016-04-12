#include <stdio.h>
#define MAX 47 //47th fib number is > 32 bits


int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

void main() {
    int n;
    do {
        scanf("%d",&n);
        printf("%d\n",fibonacci(n));
    } while (n != 0);
}

#include <stdio.h>
#define MAX 1000 //47th fib number is > 32 bits

long long int fib[MAX];

long long int fibonacci(int n)
{
    if (fib[n] == -1) 
        fib[n] = fibonacci(n-1)+fibonacci(n-2);
    return fib[n];
}

void main()
{
    long long int n,i;

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < MAX; i++)
        fib[i] = -1;

    do
    {
        puts("Enter a number:");
        scanf("%lld",&n);
        if (n >= 0 && n < MAX)
            printf("fibonacci(%lld) = %lld\n",n,fibonacci(n));
        else
            printf("Error\n");
    } while (n != 0);
}

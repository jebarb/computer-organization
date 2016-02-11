#include <stdio.h>
#define MAX 47 //47th fib number is > 32 bits

int fib[MAX];

int fibonacci(int n)
{
    if (fib[n] == -1) 
        fib[n] = fibonacci(n-1)+fibonacci(n-2);
    return fib[n];
}

void main()
{
    int n,i;

    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < MAX; i++)
        fib[i] = -1;

    do
    {
        puts("Enter a number:");
        scanf("%d",&n);
        if (n >= 0 && n < MAX)
            printf("fibonacci(%d) = %d\n",n,fibonacci(n));
        else
            printf("Error\n");
    } while (n != 0);
}

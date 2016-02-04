#include <stdio.h>
#define AMNT 6

int prime(int in)
{
    int i;

    if (in == 1) return 1;
    if (in == 2 || in == 3) return 0;
    if (in % 2 == 0) return 2;
    if (in % 3 == 0) return 3;
    for (i = 5; i*i <= in; i += 6) {
        if (in % i == 0) return i;
        if (in % (i + 2) == 0) return i + 2;
    }
    return 0;
}

void main()
{
    int i,in;

    while (1) {
        printf("Number [1-100]: ?\n");
        if (!scanf("%d",&in) || in == 0) break;
        i = prime(in);
        if (i == 0) {
            printf("Prime\n");
        } else if (i == 1) {
            printf("Non-prime (special case)\n");
        } else {
            printf("Non-prime, divisible by %d\n",i);
        }
    }
    printf("Done\n");
}


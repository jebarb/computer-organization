#include <stdio.h>
#define AMNT 5

void main()
{
    float i,in,sum,prod;

    sum = 0;
    prod = 1;

    printf("Enter five floating-point numbers:\n");
    for (i = 0; i < AMNT; ++i) {
        scanf("%f", &in);
        sum += in;
        prod *= in;
    }

    printf("Sum is %0.4f\nMean is %0.4f\nProduct is %0.4f\n", sum, sum/AMNT, prod);
}


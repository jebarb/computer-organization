#include <stdio.h>

void main()
{
    float fahr, celsius;
    float lower, upper, step;

    printf("\nEnter lower bound\n");
    scanf("%f", &lower);

    printf("\nEnter upper bound\n");
    scanf("%f", &upper);

    printf("\nEnter step size\n");
    scanf("%f", &step);

    fahr = lower;
    printf("\n%8s%14s\n", "Fahrenheit:", "Celsius:");
    while (fahr <= upper) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;
        printf("%11.2f\t%9.2f\n", fahr, celsius);
        fahr += step;
    }
}


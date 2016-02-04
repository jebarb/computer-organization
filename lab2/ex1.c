#include <stdio.h>

void main()
{
    int count,i;

    printf("Please enter a number from 1 to 5:\n");
    scanf("%i", &count);

    if (count < 1 || count > 5) {
        printf("Number is not in the range from 1 to 5\n");
        return;
    }

    for (i = 1; i <= count; ++i)
        printf("%d Hello World\n", i);
}


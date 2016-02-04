#include <stdio.h>
#define AMNT 6

unsigned long long fermat(unsigned i, unsigned in) {
    unsigned long long pow = 1;
    while (in-- > 0) {
        pow *= i;
    }
    return pow;
}

void main()
{
    unsigned long long div;
    unsigned long long in,count;

    while (1) {
        printf("Number [1-100]: ?\n");
        if (!scanf("%lld",&in) || in == 0) {
            break;
        } else if (in == 1) {
            printf("Non-prime (special case)\n");
        } else {
            div = 1;
            if (in > 3) {
                for (count = 2; count*count <= in; count++) {
                    if ((div = fermat(count, in-1) % in) != 1) {
                        printf("Non-prime");
                        break;
                    }
                }
            }
            if (div == 1)
                printf("Prime\n");
        }
    }
    printf("Done\n");
}


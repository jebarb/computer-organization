#include <stdio.h>

void main() {
    int* a;

    for(int i = 0; i < 3; i++)
        a[i] = i;

    if (a[1] == *(a+1)) printf("1Hello, world.\n");
    if (*a == a[0]) printf("2Hello, world.\n");
    if (&a[2] == a+8) printf("3Hello, world.\n");
    if (*(a+1) == a[1]) printf("4Hello, world.\n");
}

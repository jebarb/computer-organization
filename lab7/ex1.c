#include <stdio.h>
#include <stdlib.h>

#define LEN 1000

int a_to_i(char* str) {
    int n = 0;
    for (int i = 0; str[i+1] != '\0'; ++i)
        n = n*10 + (int)(str[i] - '0');
    return n;
}

int main () {
    char* str;
    int n;

    str = malloc(LEN);

    while(fgets(str, LEN, stdin)) {
        n = a_to_i(str);
        printf("%d\n", n);
        if (n == 0) return 0;
    }
}


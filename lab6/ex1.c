#include <stdio.h>

int main() {

    int r, g, b, gray, max;
    char c;

    scanf("%c", &c);
    scanf("%c", &c);
    printf("%s\n", "P2");
    scanf("%d", &max);
    printf("%d\n", max);
    scanf("%d", &max);
    printf("%d\n", max);
    scanf("%d", &max);
    printf("%d\n", 255);

    while(scanf("%d%d%d", &r, &g, &b) == 3) {
        gray = ((r*30 + g*59 + b*11) * 255) / (100 * max);
        printf("%d\n", gray);
    }

    return 1;
}

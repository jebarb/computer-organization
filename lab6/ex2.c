#include <stdio.h>

int main() {

    int g, w, h, x1, x2, y1, y2, i, x, y, max;

    printf("%s\n", "P2");
    scanf("%d", &x1);
    scanf("%d", &x2);
    scanf("%d", &y1);
    scanf("%d", &y2);
    scanf("%d", &w);
    scanf("%d", &h);
    scanf("%d", &max);
    printf("%d\n", x2-x1+1);
    printf("%d\n", y2-y1+1);
    printf("%d\n", 255);

    while(scanf("%d", &g) == 1) {
        x = i % w;
        y = i / w;
        if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
            printf("%d\n", g);
        i++;
    }

    return 1;
}

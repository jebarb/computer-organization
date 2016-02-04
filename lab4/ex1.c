#include <stdio.h>

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

char str[NUM][LEN];

void swap(int first, int second) {

    char temp;
    int i;
    for (i = 0; str[first][i] != '\0' || str[second][i] != '\0'; i++) {
        temp = str[second][i];
        str[second][i] = str[first][i];
        str[first][i] = temp;
    }
}

int compare(int first, int second, int i) {

    if (str[first][i] == '\0') {
        return 1;
    } else if (str[first][i] == str[second][i]) {
        compare(first, second, ++i);
    } else if (str[first][i] > str[second][i]) {
        swap(first, second);
        return 0;
    }
}

void main() {

    int i,j,sorted;

    printf("Please enter %d strings, one per line:\n", NUM);

    while (i < NUM && fgets(str[i],LEN,stdin)) {
        for (j = 0; j < LEN; j++) {
            if (str[i][j] == '\n')
                str[i][j] = '\0';
        }
        ++i;
    }

    puts("\nHere are the strings in the order you entered:");

    for (i = 0; i < NUM; i++)
        puts(str[i]);

    do {
        sorted = 1;
        for (i = 0; i < NUM - 1; i++) {
            if (!compare(i, i + 1, 0))
                sorted = 0;
        }
    } while (!sorted);

    puts("\nIn alphabetical order, the strings are:");     
    for (i = 0; i < NUM; i++)
        puts(str[i]);

    return;
}

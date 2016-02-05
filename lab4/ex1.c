#include <stdio.h>

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

char str[NUM][LEN];

void swap(int s1, int s2) {
    char temp;
    int i;
    for (i = 0; str[s1][i] != '\0' || str[s2][i] != '\0'; i++) {
        temp = str[s2][i];
        str[s2][i] = str[s1][i];
        str[s1][i] = temp;
    }
}

int compare(int s1, int s2, int i) {
    if (str[s1][i] < str[s2][i] || str[s1][i] == '\0') {
        return 1;
    } else if (str[s1][i] == str[s2][i]) {
        compare(s1, s2, ++i);
    } else if (str[s2][i] == '\0' || str[s1][i] > str[s2][i]) {
        swap(s1, s2);
        return 0;
    }
}

void main() {

    int i,j,sorted;

    printf("Please enter %d strings, one per line:\n", NUM);

    for (i = 0; i < NUM; i++) {
        fgets(str[i],LEN,stdin);
        for (j = 0; j < LEN; j++) {
            if (str[i][j] == '\n')
                str[i][j] = '\0';
        }
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

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
    if (str[s1][i] == '\0' && str[s2][i] == '\0') {
        return 0;
    } else if (str[s1][i] < str[s2][i] || str[s1][i] == '\0') {
        return -1;
    } else if (str[s1][i] == str[s2][i]) {
        compare(s1, s2, ++i);
    } else if (str[s2][i] == '\0' || str[s1][i] > str[s2][i]) {
        return 1;
    }
}

int partition(int lo, int hi) {
    int pivot = lo;
    int i = lo - 1;
    int j = hi + 1;

    while (1) {
        do {
            i++;
        } while (compare(i, pivot, 0) < 0);
        do {
            j--;
        } while (compare(j, pivot, 0) > 0);
        if (i >= j) {
            return j;
        }
        swap(i, j);
    }
}

void quicksort(int lo, int hi) {
    if (lo < hi) {
        int p = partition(lo, hi);
        quicksort(lo, p);
        quicksort(p+1, hi);
    }
}

void main() {

    int i,j,sorted;

    printf("Please enter %d strings, one per line:\n", NUM);

    for (i = 0; i < NUM; i++) {
        fgets(str[i],LEN,stdin);
    }

    puts("\nHere are the strings in the order you entered:");
    for (i = 0; i < NUM; i++)
        printf("%s", str[i]);

    quicksort(0, NUM-1);

    puts("\nIn alphabetical order, the strings are:");     
    for (i = 0; i < NUM; i++)
        printf("%s", str[i]);
}

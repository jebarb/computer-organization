#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

char *str[NUM];

int partition(int lo, int hi) {
    int pivot = lo;
    int i = lo - 1;
    int j = hi + 1;

    while (1) {
        do {
            i++;
        } while (strcmp(str[i],str[pivot]) < 0);
        do {
            j--;
        } while (strcmp(str[j],str[pivot]) > 0);
        if (i >= j) {
            return j;
        }
        char *tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
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

    int i, sorted, size;

    printf("Please enter %d strings, one per line:\n", NUM);

    for (i = 0; i < NUM; i++) {
        char *tmp;
        tmp = malloc(LEN);
        fgets(tmp,LEN,stdin);
        size = strlen(tmp);
        str[i] = malloc(size);
        memcpy(str[i],tmp,size);
        str[i][size-1] = '\0';
    }

    puts("\nHere are the strings in the order you entered:");

    for (i = 0; i < NUM; i++)
        printf("%s\n",str[i]);

    quicksort(0, NUM-1);

    puts("\nIn alphabetical order, the strings are:");     
    for (i = 0; i < NUM; i++) {
        puts(str[i]);
        free(str[i]);
    }
}

#include <stdio.h>
#include <string.h>

#define NUM 25  /* number of strings */
#define LEN 1000  /* max length of each string */

char str[NUM][LEN],tmp[LEN];

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
        strncpy(tmp,str[i],LEN);
        strncpy(str[i],str[j],LEN);
        strncpy(str[j],tmp,LEN);
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
        str[i][strlen(str[i])-1] = '\0';
    }

    puts("\nHere are the strings in the order you entered:");

    for (i = 0; i < NUM; i++)
        puts(str[i]);

    quicksort(0, NUM-1);

    puts("\nIn alphabetical order, the strings are:");     
    for (i = 0; i < NUM; i++)
        puts(str[i]);
}

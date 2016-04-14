#include <stdio.h>
#include <stdlib.h>

int* in;

int partition(int lo, int hi) {
    int pivot = in[lo];
    int i = lo - 1;
    int j = hi + 1;
    while (1) {
        do i++;
        while (in[i] < pivot);
        do j--;
        while (in[j] > pivot);
        if (i >= j) return j;
        int tmp = in[i];
        in[i] = in[j];
        in[j] = tmp;
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
    int i, num;
    scanf("%d", &num);
    in = malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
        scanf("%d", &in[i]);
    quicksort(0, num-1);
    for (i = 0; i < num; i++)
        printf("%d\n", in[i]);
}

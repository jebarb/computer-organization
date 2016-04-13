#include <stdio.h>
#include <stdlib.h>

long long int partition(long long int lo, long long int hi, long long int* in) {
    long long int pivot = in[lo];
    long long int i = lo - 1;
    long long int j = hi + 1;

    while (1) {
        do {
            i++;
        } while (in[i] < pivot);
        do {
            j--;
        } while (in[j] > pivot);
        if (i >= j) {
            return j;
        }
        long long int tmp = in[i];
        in[i] = in[j];
        in[j] = tmp;
    }
}

void quicksort(long long int lo, long long int hi, long long int* in) {
    if (lo < hi) {
        long long int p = partition(lo, hi, in);
        quicksort(lo, p, in);
        quicksort(p+1, hi, in);
    }
}

void main() {

    long long int* in;
    long long int i, num;

    scanf("%d", &num);

    in = malloc(num * sizeof(long long int));

    printf("%lld\n", num);

    for (i = 0; i < num; i++) {
        scanf("%d", &in[i]);
    }

    quicksort(0, num-1, in);

    for (i = 0; i < num; i++) {
        printf("%lld\n", in[i]);
    }
}

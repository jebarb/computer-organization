#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

void main() {

    int i, sorted, size;
    char *str[NUM];

    printf("Please enter %d strings, one per line:\n", NUM);

    for (i = 0; i < NUM; i++) {
        char *tmp;
        fgets(tmp,LEN,stdin);
        size = strlen(tmp);
        str[i] = malloc(size);
        memcpy(str[i],tmp,size);
        str[i][size-1] = '\0';
    }

    puts("\nHere are the strings in the order you entered:");

    for (i = 0; i < NUM; i++)
        printf("%s\n",str[i]);

    do {
        sorted = 1;
        for (i = 0; i < NUM - 1; i++) {
            if (strncmp(str[i],str[i+1],LEN) > 0) {
                sorted = 0;
                char *tmp = str[i];
                str[i] = str[i+1];
                str[i+1] = tmp;
            }
        }
    } while (!sorted);

    puts("\nIn alphabetical order, the strings are:");     
    for (i = 0; i < NUM; i++) {
        puts(str[i]);
        free(str[i]);
    }
}

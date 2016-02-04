#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

void main() {

    int i, j, sorted;
    char* str[NUM];

    printf("Please enter %d strings, one per line:\n", NUM);

    for (i = 0; i < NUM; i++) {
        char* tmp = (char*) malloc(LEN);
        fgets(tmp,LEN,stdin);
        int size = strlen(tmp);
        str[i] = (char*) malloc(size);
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
                char *tmp = (char*) malloc(strlen(str[i])+1);
                memcpy(tmp,str[i],strlen(str[i])+1);
                memcpy(str[i],str[i+1],strlen(str[i+1])+1);
                memcpy(str[i+1],tmp,strlen(tmp)+1);
            }
        }
    } while (!sorted);

    puts("\nIn alphabetical order, the strings are:");     
    for (i = 0; i < NUM; i++) {
        puts(str[i]);
        free(str[i]);
    }
}

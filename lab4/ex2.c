#include <stdio.h>
#include <string.h>

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

void main() {

    int i,j,sorted;
    char str[NUM][LEN],tmp[LEN];

    printf("Please enter %d strings, one per line:\n", NUM);

    for (i = 0; i < NUM; i++) {
        fgets(str[i],LEN,stdin);
        str[i][strlen(str[i])-1] = '\0';
    }

    puts("\nHere are the strings in the order you entered:");

    for (i = 0; i < NUM; i++)
        puts(str[i]);

    do {
        sorted = 1;
        for (i = 0; i < NUM - 1; i++) {
            if (strncmp(str[i],str[i+1],LEN) > 0) {
                sorted = 0;
                strncpy(tmp,str[i],LEN);
                strncpy(str[i],str[i+1],LEN);
                strncpy(str[i+1],tmp,LEN);
            }
        }
    } while (!sorted);

    puts("\nIn alphabetical order, the strings are:");     
    for (i = 0; i < NUM; i++)
        puts(str[i]);
}

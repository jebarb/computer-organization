#include <stdio.h>
#include <string.h>

void bedtimestory(char names[20][15], int current, int number) {
    int i = current;
    if (current == 0) {
        printf("A %s couldn't sleep, so her mother told a story about a little %s,\n", 
                names[current], names[current+1]);
    } else {
        while (--i >= 0) printf("  ");
        printf("who couldn't sleep, so the %s's mother told a story about a little %s,\n", 
                names[current], names[current+1]);
    }
    if (current < number - 1) bedtimestory(names, current+1, number);
    i = current;
    while (i-- >= 0) printf("  ");
    if (current == number - 1) {
        printf("... who fell asleep.\n");
    } else {
        printf("... and then the little %s fell asleep;\n", 
                names[current+1]);
    }
    if (current == 0) {
        printf("... and then the %s fell asleep.\n", names[current]);
    }
}

void main() {
    char names[20][15];
    int n = 0;
    while (1) {
        fgets(names[n], 15, stdin);
        names[n][strlen(names[n])-1] = '\0';
        if (strcmp(names[n], "END\0") == 0) break;
        n++;
    }
    n--;
    bedtimestory(names, 0, n);
}


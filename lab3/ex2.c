/* Example: analysis of text */

#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

void main()
{
    char text[MAX];
    int i,equal;
    equal = 1;

    puts("Type some text (then ENTER):");

    fgets(text,MAX,stdin);

    puts("Your input in reverse is:");

    for (i = strlen(text)-2; i >=0; i--)
    {
        if (putchar(text[i]) != text[strlen(text)-i-2])
            equal = 0;
    }

    printf("\n");

    if (equal == 1) 
        printf("Found a palindrome!\n");

}

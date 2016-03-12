#include <stdio.h>

void main()
{
    int c, i, nwhite, nother;
    int ndigit[10];

    for (i = 0; i < sizeof(ndigit) / sizeof(ndigit[0]); ++i)
        ndigit[i] = 0;

    nwhite = nother = 0;
    while ((c = getchar()) != EOF)
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == '\n' || c == ' ' || c == '\t')
            ++nwhite;
        else
            ++nother;

    printf("digits = ");
    for (i = 0; i < sizeof(ndigit) / sizeof(ndigit[0]); ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}


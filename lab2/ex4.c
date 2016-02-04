#include <stdio.h>
#define AMNT 6

void main()
{
    int i,in[6];

    printf("Enter six integers:\n");
    for (i = 0; i < AMNT; i++) {
        scanf("%d",&in[i]);
    }

    printf("1234567890bb1234567890\n");

    for (i = 0; i < (AMNT / 2); ++i) {
        printf("%10d%12d\n",in[2*i],in[2*i+1]);
    }

}

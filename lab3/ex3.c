/* Example: matrices represented by 2-dimensional arrays */

#include <stdio.h>

void printarray(int m, int n, int arr[m][n])
{
    int i, j, k;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%6d",arr[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int A[3][3], B[3][3], C[3][3];
    int i, j, k;

    printf("Please enter the values for A[0..2][0..2], one row per line:\n");
    for (i = 0; i < 3; i++) 
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&A[i][j]);
        }

    printf("Please enter the values for B[0..2][0..2], one row per line:\n");
    for (i = 0; i < 3; i++) 
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&B[i][j]);
        }

    printf("A=\n");
    printarray(3,3,A);
    printf("B=\n");
    printarray(3,3,B);

    /* multiply C = A.B: */

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for (k =0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    printf("C=A.B=\n");
    printarray(3,3,C);

    /* multiply C = B.A: */

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for (k =0; k < 3; k++)
                C[i][j] += B[i][k] * A[k][j];
        }

    printf("C=B.A=\n");
    printarray(3,3,C);

}

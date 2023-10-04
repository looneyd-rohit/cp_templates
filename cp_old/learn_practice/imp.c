#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

void printSeries(int *arr, int n, int i, ...)
{
    va_list ap;
    va_start(ap, i);
    // printf("i = %d\n",i);
    // printf("\nPrinting the variable length arguments : \n");
    // for(int j=0 ; j<i ; j++)
    // printf("%d\t",va_arg(ap,int));
    // printf("\n\n");
    for (int a = 0; a < n; a++)
    {
        if ((i + 1) < n)
        {
            printSeries(arr, n, i++, *ap, a);
            return;
        }
        else
        {
            printf("\n%d", *(arr + a));
            for (int k = 1; k <= i; k++)
                printf("%d", *(arr + va_arg(ap, int)));
            printf("\n");
        }
    }
    i = 0;
    // va_end(ap);
}

void main()
{
    int n, j;
    // static int i;
    printf("Enter n = ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));
    for (j = 0; j < n; j++)
        scanf("%d", (arr + j));
    printf("array : ");
    for (j = 0; j < n; j++)
        printf("%d    ", *(arr + j));
    printSeries(arr, n, 0, *arr);
    free(arr);
}
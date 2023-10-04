#include <stdlib.h>
#include <stdio.h>

#define MAX 10

int main()
{
    system("cls");
    int array[MAX];
    int i, j, num, temp;

    printf("enter the number of values:\t");
    scanf("%d", &num);
    printf("enter the elements:\n");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("the input array is:\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < (num - i - 1); j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    printf("the sorted array in ascending order is:\n");
    for (i = 0; i < num; i++)
        ;
    {
        printf("%d\t", array[i]);
    }
    system("pause");
}
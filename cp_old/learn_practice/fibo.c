#include <stdio.h>
#include <conio.h>

int main()
{
    system("cls");
    long int n, sum = 0;
    long int a = 0, b = 1;
    float r;
    printf("enter the number of terms ");
    scanf("%ld", &n);
    printf("the series:\n");
    printf("%d\t%d\n", a, b);
    for (int i = 0; i < n - 2; i++)
    {
        sum = a + b;
        r = sum / (float)b;
        printf("%ld\t", sum);
        printf("r = %f\n", r);
        a = b;
        b = sum;
        sum = a + b;
    }
    getch();
    return 0;
}
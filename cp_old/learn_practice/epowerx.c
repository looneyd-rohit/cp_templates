#include <stdio.h>
#include <math.h>

int fact(int a)
{
    if (a == 1 || a == 0)
        return 1;
    else
        return a * fact(a - 1);
}
int main()
{
    int n, i = 0;
    float x, sum = 1;
    printf("Enter x = ");
    scanf("%f", &x);
    printf("Enter no. of terms = ");
    scanf("%d", &n);

    // printf("fact = %d",fact(5));
    do
    {
        sum = sum + (pow(x, i)) / (fact(i));
        i++;
    } while (i < n);
}
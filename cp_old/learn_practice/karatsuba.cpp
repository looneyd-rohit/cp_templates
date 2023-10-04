#include <iostream>
#include <math.h>
using namespace std;

unsigned long long int maxLength(unsigned long long int x, unsigned long long int y)
{
    unsigned long long int l = 0, m = 0;
    while (x || y)
    {
        l++;
        m++;
        x /= 10;
        y /= 10;
    }
    return ((l > m) ? l : m);
}
unsigned long long int karatsuba(unsigned long long int n1, unsigned long long int n2)
{
    if (n1 < 10 || n2 < 10)
        return n1 * n2;
    else
    {
        unsigned long long int len = maxLength(n1, n2);
        unsigned long long int half = len / 2;
        unsigned long long int t = pow(10, half);
        unsigned long long int a = n1 / t;
        unsigned long long int b = n1 % t;
        unsigned long long int c = n2 / t;
        unsigned long long int d = n2 % t;
        unsigned long long int ac = karatsuba(a, c);
        unsigned long long int bd = karatsuba(b, d);
        unsigned long long int ad_bc = karatsuba(a + b, c + d) - ac - bd;
        return (ac * pow(10, 2 * half)) + (ad_bc * pow(10, half)) + bd;
    }
}

int main()
{
    // cout << maxLength(123, 1234) << endl;
    unsigned long long int x, y;
    cout << "Enter x = ";
    cin >> x;
    cout << "Enter y = ";
    cin >> y;
    cout << "\nRESULT = " << karatsuba(x, y) << endl
         << endl;
    return 0;
}
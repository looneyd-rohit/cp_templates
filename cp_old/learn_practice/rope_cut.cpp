#include <bits/stdc++.h>
using namespace std;

int zzz(int n, int a, int b, int c)
{
    if (n < a && n < b && n < c)
    {
        if (n == 0)
            return 0;
        return -1;
    }
    int max = n / a;
    if ((n / b) > (n / c))
    {
        if (max < (n / b))
        {
            if (zzz(n - b, a, b, c) != -1)
                return (1 + zzz(n - b, a, b, c));
            else
                return -1;
        }
    }
    else
    {
        if (max < (n / c))
        {
            if (zzz(n - c, a, b, c) != -1)
                return (1 + zzz(n - c, a, b, c));
            else
                return -1;
        }
    }
    if (zzz(n - c, a, b, c) != -1)
        return (1 + zzz(n - a, a, b, c));
    else
        return -1;
}

int max(int x, int y, int z)
{
    int max = x;
    if (y > z)
    {
        if (max < y)
            return y;
    }
    else
    {
        if (max < z)
            return z;
    }
    return max;
}
int zzz_alt(int n, int a, int b, int c)
{
    if (n <= 0) //base case condition for function stopping
        return n;
    int res = max(zzz_alt(n - a, a, b, c), zzz_alt(n - b, a, b, c), zzz_alt(n - c, a, b, c));

    if (res < 0)
        return -1;
    return (res + 1);
}
int main()
{
    cout << "The number of pieces are = " << zzz_alt(23, 12, 9, 11) << endl;
    return 0;
}
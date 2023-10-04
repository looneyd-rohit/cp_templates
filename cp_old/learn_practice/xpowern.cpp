#include <bits/stdc++.h>
using namespace std;

int xpowern(int x, int n)
{
    if (n == 0)
        return 1;
    else
    {
        if (n % 2 == 0)
        {
            x = x * x;
            return xpowern(x, n / 2);
        }
        else
            return x * xpowern(x, n - 1);
    }
}

int xpowernopt(int x, int n)
{
    int temp = 1;
    while (n)
    {
        if (n & 1)
        {
            temp = temp * x;
        }
        n = n >> 1;
        x = x * x;
    }
    return temp;
}

int main()
{
    cout << xpowern(10, 5) << endl;
    cout << xpowern(4, 6) << endl;
    cout << xpowernopt(10, 5) << endl;
    cout << xpowernopt(4, 6) << endl;
    return 0;
}
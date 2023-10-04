#include <bits/stdc++.h>
using namespace std;

int pow(int x, int n)
{
    if (n == 1)
        return x;
    if (n % 2 == 0)
    {
        return pow(x * x, n / 2);
    }
    else
    {
        return x * pow(x * x, (n - 1) / 2);
    }
}

int main()
{
    cout << pow(5, 6) << endl;
    return 0;
}
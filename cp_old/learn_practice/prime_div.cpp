#include <bits/stdc++.h>
using namespace std;

void prime_div(int n)
{
    if (n == 1)
    {
        cout << "no is neither prime nor composite!!!" << endl;
        return;
    }
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n = n / 3;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
        while (n % (i + 2) == 0)
        {
            cout << i + 2 << " ";
            n = n / (i + 2);
        }
    }
    if (n > 3)
        cout << n << " " << endl;
}

void all_div(int n)
{
    for (int i = 2; i * i <= n; i += 1)
    {
        if (n % i == 0)
        {
            cout << '(' << i << " " << n / i << ')' << endl;
        }
    }
}

int main()
{
    cout << endl;
    prime_div(69);
    cout << endl;
    cout << endl;
    all_div(690);
    cout << endl;
    return 0;
}
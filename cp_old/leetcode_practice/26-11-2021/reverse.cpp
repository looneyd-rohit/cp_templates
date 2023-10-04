#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
    int temp = x;
    int rev = 0;
    double f;
    while (temp)
    {
        if (x > 0)
        {
            f = rev / (double)INT_MAX;
            if (f <= 0.1)
            {
                if ((INT_MAX - rev * 10) - (temp % 10) >= 0)
                {
                    rev = rev * 10 + temp % 10;
                    temp /= 10;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        if (x < 0)
        {
            f = rev / (double)INT_MIN;
            if (f <= 0.1)
            {
                if ((INT_MIN - rev * 10) - (temp % 10) <= 0)
                {
                    rev = rev * 10 + temp % 10;
                    temp /= 10;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
    }
    return rev;
}

int main()
{
    int x;
    cin >> x;
    cout << "reversed= " << reverse(x) << endl;
    // cout << INT_MIN << endl;
    return 0;
}
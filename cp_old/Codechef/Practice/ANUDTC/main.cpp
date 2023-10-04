#include <bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
#define ll long long
#define nsync                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define t()   \
    int t;    \
    cin >> t; \
    while (t--)

int32_t main()
{
    // nsync;
    t()
    {
        int n;
        cin >> n;
        if (360 % n == 0)
        {
            cout << 'y' << " ";
        }
        else
            cout << 'n' << " ";

        if ((360 / n) >= 1)
        {
            cout << 'y' << " ";
        }
        else
            cout << 'n' << " ";

        if ((n * (n + 1) / 2) <= 360)
        {
            cout << 'y' << '\n';
        }
        else
            cout << 'n' << '\n';
    }
    return 0;
}
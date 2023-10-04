#include <bits/stdc++.h>
using namespace std;
#define mod 1e9 + 7
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define fe(i, a, b) for (int i = a; i < b; i++)
#define fr(i, a, b) for (int i = a; i >= b; i--)
#define pb(a) push_back(a)
#define em(x, y) emplace(x, y)
#define emb(x) emplace_back(x)
#define vmax(x, y) *max_element(x, y)
#define ub upper_bound
#define lb lower_bound
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

    nsync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int x;
    float y;
    cin >> x >> y;
    if (x % 5 == 0)
    {
        y = y - x - 0.5;
    }
    cout << fixed << setprecision(2) << y;

    return 0;
}
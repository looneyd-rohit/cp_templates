#include <bits/stdc++.h>
#include <algorithm>
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
    cin.tie(NULL);
#define t()   \
    int t;    \
    cin >> t; \
    while (t--)

int32_t main()

{
    nsync;
    t()
    {
        int n, k, val;
        cin >> n >> k;
        vector<int> a;
        a.reserve(n);
        f(i, n)
        {
            cin >> val;
            a[i] = (k / val);
        }
        f(i, n)
        {
            cin >> val;
            a[i] = (a[i] * val);
        }
        val = a[0];
        f(i, n)
        {
            if (val < a[i])
                val = a[i];
        }
        cout << val << endl;
    }
    return 0;
}
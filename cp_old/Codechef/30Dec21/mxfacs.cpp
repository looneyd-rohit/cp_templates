#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
const int MAXN = 2e5 + 10;
using namespace std;
vector<int> subord(MAXN);
vector<vector<int> >adj(MAXN);
// void dfs(int src, int par)
// {
// 	subord[src] = 1;
// 	for (auto v : adj[src])
// 	{
// 		if (v == par)
// 			continue;
// 		dfs(v, src);
// 		subord[src] += subord[v];
// 	}
// }
void solve()
{
    /*
    Solution Approach:
    taking that prime factor which has the largest power among all,
    since that is the one which will give as many possible divisors as 
    possible. The total count of divisors are = (a+1)*(b+1)*(c+1).....
    So among these if we have to reduce one divisor such that the product[total 
    count of divisors] remains maximum then it should be the maximum one.
    */
	int num;
	cin >> num;
	int maxi = INT_MIN;
	int k;
	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			int cnt = 0;
			while (num % i == 0)
			{num = num / i; cnt++;}
			if (cnt > maxi)
			{
				maxi = cnt;
				k = i;
			}

		}
	}
	if (num > 1)
	{
		if (1 > maxi)
			k = num;
	}
	cout << k << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//seive();
	int tc = 1;
	cin >> tc;
	while (tc--)
	{
		solve();
	}

}
#include <bits/stdc++.h>
using namespace std;
// const int M = 1e9 + 7;
#define int long long
const int s = 1e5 + 1;
const int INF = 1e17;
const int NINF = 1e17 * (-1);
#define ull unsigned long long
#define ll long long
#define lb lower_bound
#define nsync                         \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define t()   \
	int t;    \
	cin >> t; \
	while (t--)

long long compute(string &str, int n, int pos, int tight, vector<vector<vector<long long>>> &dp)
{
	// base case
	if (n == 0)
		return pos != 0;

	// dp check
	if (dp[n][pos][tight] != -1)
		return dp[n][pos][tight];

	bool isEven = (pos % 2 == 1) ? true : false;
	int ub = (tight) ? (str[str.length() - n] - '0') : 9;

	if (isEven)
	{
		long long ans = 0;
		for (int digit = 0; digit <= ub; digit += 2)
		{
			ans += compute(str, n - 1, pos + 1, tight & (digit == ub), dp);
		}
		return dp[n][pos][tight] = ans;
	}
	else
	{
		long long ans = 0;
		if (pos == 0)
		{
			ans += compute(str, n - 1, pos, 0, dp);
		}
		for (int digit = 1; digit <= ub; digit += 2)
		{
			ans += compute(str, n - 1, pos + 1, tight & (digit == ub), dp);
		}
		return ans;
	}
}

bool check(string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if ((i + 1) & 1 == 1)
		{
			if (!(((str[i] - '0') & 1) == 1))
				return false;
		}
		else
		{
			if (!(((str[i] - '0') & 1) == 0))
				return false;
		}
	}
	return true;
}

int32_t main()
{
	nsync;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt", "r", stdin);
	// 	freopen("output.txt", "w", stdout);
	// 	freopen("error.txt", "w", stderr);
	// #endif
	t()
	{
		static int tno = 1;
		string l, r;
		cin >> l >> r;
		int n = l.length(), m = r.length();
		vector<vector<vector<long long>>> dp1(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, -1)));
		vector<vector<vector<long long>>> dp2(m + 1, vector<vector<long long>>(m + 1, vector<long long>(2, -1)));
		long long left = compute(l, l.length(), 0, 1, dp1);
		long long right = compute(r, r.length(), 0, 1, dp2);
		long long ans = right - left;
		if (check(l))
			ans++;
		cout << "Case #" << tno++ << ": " << ans << endl;
	}
	return 0;
}

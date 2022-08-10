// #include<bits/stdc++.h>
// using namespace std;

// intt main(){
//     unsigned intt n;
//     cin>>n;
//     vector<unsigned intt> arr(n);
//     for(intt i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     sort(arr.begin(),arr.end());
//     unsigned intt allX = 0;
//     for(intt j=0; j<n; j++){
//         allX = allX ^ arr[j];
//     }
//     for(intt i=0; i<n; i++){
//         cout<<~allX<<endl;
//         allX = allX ^ arr[n-i-1];
//         arr.pop_back();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define intt long long int
using namespace std;

void solve() {
	// your code goes here
	intt n;
	cin >> n;
	vector<intt> sorted;
	map<intt, intt> mp;
	for (intt i = 1; i <= 32; ++i)
		mp[i] = 0;
	for (intt i = 0; i < n; ++i)
	{
		intt x;
		cin >> x;
		sorted.push_back(x);
		for (intt j = 0; j <= 31; ++j)
		{
			if (x & (1 << j))
				mp[j]++;
		}
	}
	sort(sorted.begin(), sorted.end(), greater<intt>());
	// for (auto x : mp)
	// 	cout << x.first << " " << x.second << endl;
	for (auto x : sorted)
	{
		// cout << x << endl;
        unsigned int k = 0;
		for (auto el : mp)
		{
			if ((el.second) % 2 == 0 || (el.second == 0))
			{
				// cout << el.first << " " << el.second << endl;
				k += (1 << el.first);
			}
		}
		cout <<k << endl;
		for (intt j = 0; j <= 31; ++j)
		{
			if (x & (1 << j))
				mp[j]--;
		}

	}

}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	//seive();
	intt tc = 1;
	//cin >> tc;
	while (tc--)
	{
		solve();
	}

}
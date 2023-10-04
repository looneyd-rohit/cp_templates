#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int M = 1e9 + 7;
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

double nthRootBinarySearch(int n, int num){
	double low = 1, high = num;
	double diff = 1e-6;
	while(low < high - diff){
		double mid = (low) + ((high - low) / 2);
		cout<<low<<" "<<mid<<" "<<high<<endl;
		double mul = 1;
		for(int i=0; i<n; i++) mul *= mid;
		if(mul <= num){
			low = mid;
		}else{
			high = mid;
		}
	}
	return low;
}

int32_t main()
{
	nsync;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	// t()
	// {
		int n, num;
		cin>>n>>num;
		double ans = nthRootBinarySearch(n, num);
		cout<<"The square root of "<<num<<" is "<<ans<<" ."<<endl;
	// }
	return 0;
}

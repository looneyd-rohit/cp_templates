#include <bits/stdc++.h>
using namespace std;
const int M = (int)1e9+7;
#define int long long
const int s = 1e5 + 1;
const int INF = 1e10;
const int NINF = 1e10 * (-1);
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

// int primes[(int)1e6+5], lprimes[(int)1e6+5];
// void sieve(){
// 	for(int i=0; i<=1e6; i++) primes[i] = 1, lprimes[i]=-1;
// 	primes[0]=primes[1]=false;
// 	// lprimes[0]=lprimes[1]=-1;
// 	for(int i=2; i*i<=1e6; i++){
// 		if(primes[i]){
// 			lprimes[i] = i;
// 			for(int j=i*i; j<=1e6; j+=i){
// 				primes[j] = false;
// 				if(lprimes[j]==-1) lprimes[j] = i;
// 				// lprimes[j] = min(lprimes[j], i);
// 			}
// 		}
// 	}
// }

// unordered_set<int> calculateDivisors(int n){
// 	unordered_set<int> divisors;
// 	divisors.insert(1);
// 	divisors.insert(n);
// 	while(n > 1){
// 		int lowprime = lprimes[n];
// 		while(n % lowprime == 0){
// 			divisors.insert(lowprime);
// 			divisors.insert(n/lowprime);
// 			n /= lowprime;
// 		}
// 	}
// 	return divisors;
// }


// vector<int> m, b;

// bool bad(int f1, int f2, int f3) {
//   return (b[f3] - b[f1]) * (m[f1] - m[f2]) >=
//          (b[f2] - b[f1]) * (m[f1] - m[f3]);  
// }

// void add(long long m_, long long b_) {
//   m.push_back(m_); b.push_back(b_); // push in CHT
//   int sz = m.size();
//   // check if it can be kept or not
//   while(sz >= 3 && bad(sz - 3, sz - 2, sz - 1)) {
//     m.erase(m.end() - 2); // remove f2's m
//     b.erase(b.end() - 2); // remove f2's b
//     sz--; // size is decreased by 1
//   }
// }

// int f(int i, int x) { return m[i] * x + b[i]; }
// long long query (long long x) {
// 	int size = m.size();
//   long long last = m[size - 1] * x + b[size - 1];
//   int lo = 0, hi = size - 2;
//   while (lo <= hi) {
//     int mid = (lo + hi) >> 1;
//     long long now = f(mid, x);
//     long long after = f(mid+1, x);
//     if (now > after) lo = mid + 1;
//     else hi = mid - 1; 
//   }
//   return min(last, m[lo] * x + b[lo]);
// }

int dp[(int)(101)][(int)(101)][(int)(101)];

int dp2[(int)(101)];

int findPartition(int sz, vector<int>& scores){
	// base case
	if(sz==0) return 0;

	if(dp2[sz]!=-1) return dp2[sz];

	int ans = scores[sz-1];
	for(int new_sz=1; new_sz<sz; new_sz++){
		ans = max(ans, findPartition(new_sz, scores)+findPartition(sz-new_sz, scores));
	}
	return dp2[sz] = ans;
}

int solve(int i, int j, int extra, vector<pair<char, int>>& groups, vector<int>& scores){
	// base
	if(i > j) return 0;

	// dp check
	if(dp[i][j][extra]!=-1) return dp[i][j][extra];


	int ans = -1e9;
	// try for all length sequence
	int max_sz = groups[i].second+extra;
	ans = max(ans, findPartition(max_sz, scores)+solve(i+1, j, 0, groups, scores));
	for(int k=i+2; k<j; k++){
		if(groups[k].first == groups[i].first){
			ans = max(ans, solve(i+1, k-1, 0, groups, scores)+solve(k, j, extra+groups[i].second, groups, scores));
		}
	}

	return dp[i][j][extra] = ans;
}

 

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto a : nums2)
        if (m.count(a)) {
            res.push_back(a);
            m.erase(a);
        }
    return res;
}


int32_t main()
{
	nsync;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	// sieve();
	
	// t()
	// {
		int n;
		cin>>n;
		vector<double> cost_price(n), sell_price(n);
		for(int i=0; i<n; i++){
			cin>>cost_price[i];
		}
		for(int i=0; i<n; i++){
			cin>>sell_price[i];
		}
		vector<pair<double, int>> diff_price;
		double maxi = -1e9;
		for(int i=0; i<n; i++){
			double percentage = (sell_price[i]-cost_price[i]) / cost_price[i] * 100;
			maxi = max(maxi, percentage);
			diff_price.push_back({percentage, i+1});
		}
		vector<int> result;
		for(int i=0; i<n; i++){
			if(maxi == diff_price[i].first){
				result.push_back(diff_price[i].second);
			}
		}
		for(auto& e: result) cout<<e<<" ";cout<<endl;


	// }
	return 0;
}

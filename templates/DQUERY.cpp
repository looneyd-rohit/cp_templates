#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int s = 1e5 + 1;
#define int long long
#define INF LONG_MAX
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


int BLK = 69;
class query{
public:
	int l;
	int r;
	int i;
	query(){ l = 0, r = 0, i = 0;}
	
	query(int l, int r, int i){
		this->l = l;
		this->r = r;
		this->i = i;
	}
};

bool cmp(query &a, query &b){
	int l = a.l / BLK;
	int r = b.l / BLK;
	
	if(l != r){
		return a.l < b.l;
	}else{
		return a.r < b.r;
	}
}

int32_t main()
{
	nsync;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	// t(){

	// }

	int n;
	cin>>n;
	vector<int> nums(n, 0);
	for(int i=0; i<n; i++){
		cin>>nums[i];
	}
	
	int q;
	cin>>q;
	vector<query> queries;
	int cnt = 0;
	for(int i=0; i<q; i++){
		int l, r;
		cin>>l>>r;
		query q(l, r, i);
		queries.push_back(q);
	}
	BLK = sqrtl(n);
	sort(queries.begin(), queries.end(), cmp);
	unordered_map<int, int> ans;
	unordered_map<int, int> freq;
	int ml = 0, mr = -1;
	cnt = 0;
	for(auto& e:queries){
		int l = e.l, r = e.r, i = e.i;
		l--;
		r--;
		
		while(mr < r){
			mr++;
			freq[nums[mr]]++;
			if(freq[nums[mr]]==1) cnt++;
		}
		while(ml > l){
			ml--;
			freq[nums[ml]]++;
			if(freq[nums[ml]]==1) cnt++;
		}
		while(ml < l){
			freq[nums[ml]]--;
			if(freq[nums[ml]]==0) cnt--;
			ml++;
		}
		while(mr > r){
			freq[nums[mr]]--;
			if(freq[nums[mr]]==0) cnt--;
			mr--;
		}
		
		// cout<<"cnt = "<<cnt<<endl;
		ans[i] = cnt;
		
	}
	for(int i=0; i<q; i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}
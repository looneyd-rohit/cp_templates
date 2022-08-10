#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int s = 1e5+1;
// #define		int 		   long long
#define		INF 		   1e9+69
#define 	ull 		   unsigned long long
#define     ll             long long
#define     lb             lower_bound
#define     nsync          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     t()            int t; cin>>t; while(t--)

vector<int> parent;
vector<int> sizeArr;
set<int> sizes;

void makeSet(int n){
	for(int i=1; i<=n; i++){
		parent[i] = i;
		sizeArr[i] = 1;
		// sizes.insert(1);
	}
}

int findParent(int u){
	if(u == parent[u]) return u;
	return parent[u] = findParent(parent[u]);
}

void merge(int u, int v){
	sizes.erase(sizes.find(sizeArr[u]));
	sizes.erase(sizes.find(sizeArr[v]));
	sizes.insert(sizeArr[u] + sizeArr[v]);
}

void unionSet(int u, int v){
	u = findParent(u);
	v = findParent(v);
	
	parent[v] = u;
	merge(u, v);
	sizeArr[u] += sizeArr[v];
}

int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    // t(){ }
    
    int n;
    cin>>n;

	parent.resize(n+1);
	sizeArr.resize(n+1);
	
	makeSet(n);
	
	int q;
	cin>>q;
	int diff = 0;
	while(q--){
		int a, b;
		cin>>a>>b;
		if(findParent(a) == findParent(b)){
			cout<<diff<<endl;
		}else{
			unionSet(a, b);
			auto right = sizes.lower_bound(sizeArr[findParent(a)]);
			diff = min(diff, *right - sizeArr[findParent(a)]);
			auto left = (right!=sizes.begin()) ? (--right) : (right);
			diff = min(diff, sizeArr[findParent(a)] - *left);
			cout<<diff<<endl;
		}
	}
    
    return 0;
}
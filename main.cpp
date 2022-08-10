#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
const int s = 1e5+1;
#define		INF 		   1e9+69
#define 	ull 		   unsigned long long
#define     ll             long long
#define     lb             lower_bound
#define     nsync          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     t()            int t; cin>>t; while(t--)

class node{
	public:
		int open;
		int close;
		int full;
		node(){
			open=0;
			close=0;
			full=0;
		}
};

node merge(node left, node right){
	node ans;
	int mini = min(left.open, right.close);
	ans.open = left.open + right.open - mini;
	ans.close = left.close + right.close - mini;
	ans.full = left.full + right.full + mini;
	return ans;
}


void build(int index, int low, int high, node segArr[], string& str){
	// base case
	if(low>=high){
		// if range size is 1, then it cannot be valid bracket sequence
		if(low==high){
			if(str[low]=='(') segArr[index].open = 1;
			if(str[low]==')') segArr[index].close = 1;
		}
		return;
	}
	
	int mid = (low) + ((high-low) >> 1);
	
	// left subtree
	int index1 = 2 * index + 1;
	build(index1, low, mid, segArr, str);
	
	// right subtree
	int index2 = 2 * index + 2;
	build(index2, mid + 1, high, segArr, str);
	
	segArr[index] = merge(segArr[index1], segArr[index2]);
}

node query(int index, int low, int high, int l, int h, node segArr[]){
	// no overlap
	if(h < low || l > high){
		return node();
	}
	
	// full overlap
	if(l <= low and high <= h){
		return segArr[index];
	}
	
	
	// partial overlap
	int mid = low + ((high - low) >> 1);
	node left = query(2*index+1, low, mid, l, h, segArr);
	
	node right = query(2*index+2, mid+1, high, l, h, segArr);
	
	return merge(left, right);
}

int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    // t(){
    	
    	
    // }
    
    
    string str = "";
    cin>>str;
    int n = str.length();
    node segArr[4*n+1];
    build(0, 0, n-1, segArr, str);
    int m;
    cin>>m;
    while(m--){
    	int l, h;
    	cin>>l>>h;
    	cout<<2*(query(0, 0, n-1, l-1, h-1, segArr).full)<<endl;
    }
    return 0;
}
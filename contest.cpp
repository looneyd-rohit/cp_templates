#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
#define     ll             long long
#define     lb             lower_bound
#define     nsync          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     t()            int t; cin>>t; while(t--)

vector<int> segArr;
void build(int index, int low, int high, vector<int>& arr){
	// base case
	if(low==high){
		segArr[index] = arr[low];
		return;
	}
	
	int mid = low + ((high - low) >> 1);
	build(2*index+1, low, mid, arr);
	build(2*index+2, mid+1, high, arr);
	segArr[index] = min(segArr[2*index+1], segArr[2*index+2]);
}
int query(int index, int low, int high, int l, int h){
	// no overlap
	if(h < low or high < l) return 1e9;
	
	// complete overlap
	if(l <= low and high <= h) return segArr[index];
	
	// partial overlap
	int mid = low + ((high - low) >> 1);
	int left = query(2*index+1, low, mid, l, h);
	int right = query(2*index+2, mid+1, high, l, h);
	return min(left, right);
}
int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    t(){
    	int n, k;
    	cin>>n>>k;
    	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    	for(int i=0; i<n; i++){
    		int c; cin>>c;
    		pair<int, int> p({c, i});
    		minheap.push(p);
    	}
    	vector<int> arr(n, 0);
    	while(k--){
    		arr[minheap.top().second] = 1e9;
    		minheap.pop();
    	}
    	while(!minheap.empty()){
    		arr[minheap.top().second] = minheap.top().first;
    		minheap.pop();
    	}
    	
    	// for(auto& e:arr) cout<<e<<" ";
    	// 	cout<<endl;
    	
    	segArr.resize(4 * n + 1);
    	build(0, 0, n-1, arr);
    	vector<vector<int>> matrix(n+1, vector<int>(n+1, 1e9));
    	for(int i=1; i<=n; i++){
				matrix[i][i] = 0;
    		for(int j=i+1; j<=n; j++){
    			int mini = query(0, 0, n-1, i-1, j-1);
    			matrix[i][j] = mini;
    			matrix[j][i] = mini;
    		}
    	}
    	
    	
    	// for(int i=1; i<=n; i++){
    	// 	for(int j=1; j<=n; j++){
    	// 		cout<<matrix[i][j]<<" ";
    	// 	}cout<<endl;
    	// }
    	
    	
    	// floyd warshall
    	for(int k=1; k<=n; k++){
    		for(int i=1; i<=n; i++){
    			for(int j=1; j<=n; j++){
    				if(matrix[i][k]==1e9 or matrix[k][j]==1e9) continue;
    				matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
    			}
    		}
    	}
    	
    	int ans = INT_MIN;
    	for(int i=1; i<=n; i++){
    		for(int j=1; j<=n; j++){
    			ans = max(ans, matrix[i][j]);
    		}
    	}
    	cout<<ans<<endl;
    }
    return 0;
}
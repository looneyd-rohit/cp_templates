#include <bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
#define     ll             long long
#define     lb             lower_bound
#define     nsync          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     t()            int t; cin>>t; while(t--)

#define int32_t long long
class STRSQLazy{
private:
	
public:
	vector<int32_t> segArr, lazy;
	STRSQLazy(){
		segArr.resize(1e5+1, 0);
		lazy.resize(1e5+1, 0);
	}
	STRSQLazy(int32_t n){
		segArr.resize(4 * n + 1, 0);
		lazy.resize(4 * n + 1, 0);
	}
	
	void build(int32_t index, int32_t low, int32_t high, vector<int>& arr){
		if(low==high){
			segArr[index] = arr[low];
			return;
		}
		
		int32_t mid = low + ((high - low ) >> 1);
		
		build(2*index+1, low, mid, arr);
		build(2*index+2, mid+1, high, arr);
		segArr[index] = (segArr[2*index+1] + segArr[2*index+2]);
	}
	
	int32_t rangeQuery(int32_t index, int32_t low, int32_t high, int32_t l, int32_t h){
		// if previous updates are pending just complete them
		if(lazy[index]!=0){
			segArr[index] += (high - low + 1) * lazy[index];
			
			// if there exists child nodes then propagate
			// the updates
			if(low!=high){
				lazy[2*index+1] += lazy[index];
				lazy[2*index+2] += lazy[index];
			}
			
			lazy[index] = 0;
		}
		
		// if no overlap
		if(h < low || l > high){ return 0; }
		
		// if complete overlap --> l <= low <= high <= h
		if(l <= low and high <= h){
			return segArr[index];
		}
		
		int32_t mid = low + ((high - low ) >> 1);
		int32_t left = rangeQuery(2*index+1, low, mid, l, h);
		int32_t right = rangeQuery(2*index+2, mid+1, high, l, h);
		return (left+right);
	}
	
	void update(int32_t index, int32_t low, int32_t high, int32_t i, int32_t val){
		// base case
		if(low==high){
			// update at actual position
			segArr[index] = val;
			return;
		}
		
		int32_t mid = low + (high - low) >> 1;
		
		if(i <= mid){
			update(2*index+1, low, mid, i, val);
		}else{
			update(2*index+2, mid+1, high, i, val);
		}
		
		// update the new minimum
		segArr[index] = segArr[2*index+1] + segArr[2*index+2];	
	}
	
	void rangeUpdate(int32_t index, int32_t low, int32_t high, int32_t l, int32_t h, int32_t val){
		// if previous updates are pending just complete them
		if(lazy[index]!=0){
			segArr[index] += (high - low + 1) * lazy[index];
			
			// if there exists child nodes then propagate
			// the updates
			if(low!=high){
				lazy[2*index+1] += lazy[index];
				lazy[2*index+2] += lazy[index];
			}
			
			lazy[index] = 0;
		}
		
		// no overlap
		if(h < low || l > high){ return; }
		
		// complete overlap
		if(l <= low and high <= h){
			segArr[index] += (high - low + 1)*val;
			
			// propagate the update to the child
			if(low!=high){
				lazy[2*index+1] += val;
				lazy[2*index+2] += val;
			}
			return;
		}
		
		// partial overlap
		int32_t mid = low + ((high - low ) >> 1);
		rangeUpdate(2*index+1, low, mid, l, h, val);
		rangeUpdate(2*index+2, mid+1, high, l, h, val);
		segArr[index] = segArr[2*index+1] + segArr[2*index+2];
	}
};

vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
    vector<int32_t> ans;
    int n = nums.size();
    STRSQLazy seg(n);
    seg.build(0, 0, n-1, nums);
    for(int32_t i=0; i<removeQueries.size(); i++){
        int32_t index = removeQueries[i];
        seg.update(0, 0, n-1, index, 0);
        // nums[index] = 0;
        // seg.build(0, 0, n-1, nums);
        int32_t lSum = 0;
        int32_t rSum = 0;
        if(index == 0){
        	// r = seg.rangeQuery()
            rSum = seg.rangeQuery(0, 0, n-1, index+1, n-1);
        }else if(index==n-1){
            lSum = seg.rangeQuery(0, 0, n-1, 0, index-1);
        }else{
            lSum = seg.rangeQuery(0, 0, n-1, 0, index-1);
            rSum = seg.rangeQuery(0, 0, n-1, index+1, n-1);
        }
        int32_t val = (lSum > rSum) ? lSum : rSum;
        ans.push_back(val);
    }
    return ans;
}

int main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    // t(){
    	
    // }
    // char a = 'a';
    // char b = a + 1;
    // cout<<(b)<<endl;
    
    // int n = 3;
    // vector<int> arr(n, 0);
    // STRSQLazy seg(n);
    // seg.build(0, 0, n-1, arr);
    // seg.rangeUpdate(0, 0, n-1, 0, 1, -1);
    // seg.rangeUpdate(0, 0, n-1, 1, 2, 1);
    // seg.rangeUpdate(0, 0, n-1, 0, 2, 1);
    // cout<<seg.rangeQuery(0, 0, n-1, 0, 0)<<endl;
    // cout<<seg.rangeQuery(0, 0, n-1, 1, 1)<<endl;
    // cout<<seg.rangeQuery(0, 0, n-1, 2, 2)<<endl;
    vector<int> nums = {1,2,5,6,1};
    vector<int> q = {0,3,2,4,1};
    vector<int32_t> ans = maximumSegmentSum(nums, q);
    for(auto& e:ans) cout<<e<<" ";
    	cout<<endl;
    return 0;
}
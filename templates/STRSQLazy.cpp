class STRSQLazy{
private:
	
public:
	vector<int> segArr, lazy;
	STRSQLazy(){
		segArr.resize(1e5+1, 0);
		lazy.resize(1e5+1, 0);
	}
	STRSQLazy(int n){
		segArr.resize(4 * n + 1, 0);
		lazy.resize(4 * n + 1, 0);
	}
	
	void build(int index, int low, int high, vector<int>& arr){
		if(low==high){
			segArr[index] = arr[low];
			return;
		}
		
		int mid = low + ((high - low ) >> 1);
		
		build(2*index+1, low, mid, arr);
		build(2*index+2, mid+1, high, arr);
		segArr[index] = segArr[2*index+1] + segArr[2*index+2];
	}
	
	int rangeQuery(int index, int low, int high, int l, int h){
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
		
		int mid = low + ((high - low ) >> 1);
		int left = rangeQuery(2*index+1, low, mid, l, h);
		int right = rangeQuery(2*index+2, mid+1, high, l, h);
		return (left+right);
	}
	
	
	
	void rangeUpdate(int index, int low, int high, int l, int h, int val){
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
		int mid = low + ((high - low ) >> 1);
		rangeUpdate(2*index+1, low, mid, l, h, val);
		rangeUpdate(2*index+2, mid+1, high, l, h, val);
		segArr[index] = segArr[2*index+1] + segArr[2*index+2];
	}
};
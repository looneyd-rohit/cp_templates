class SGTree{
	private:
		vector<int> segArr;
		SGTree(){
			segArr.resize(1e5+1);
		}
		SGTree(int n){
			segArr.resize(4*n+1);
		}
	
	public:
		void build(int index, int low, int high, vector<int>& arr){
			// base case
			if(low==high){
				// if range size is 1, current element is minimum
				segArr[index] = arr[low];
				return;
			}
			
			int mid = (low) + (high-low) >> 1;
			
			// left subtree
			int index1 = 2 * index + 1;
			build(index1, low, mid, arr);
			
			// right subtree
			int index2 = 2 * index + 2;
			build(index2, mid + 1, high, arr);
			
			segArr[index] = min(segArr[index1], segArr[index2]);
		}
		
		int query(int index, int low, int high, int l, int h, vector<int>& arr){
			
			// no overlap
			if(h < low || l > high){
				return INF;
			}
			
			// full overlap
			if(l <= low and high <= h){
				return segArr[index];
			}
			
			
			// partial overlap
			int mid = low + (high - low) >> 1;
			int left = query(2*index+1, low, mid, l, h, arr);
			int right = query(2*index+2, mid+1, high, l, h, arr);
			return min(left, right);
		}
		
		void update(int index, int low, int high, int i, int val, vector<int>& arr){
			// base case
			if(low==high){
				// update at actual position
				segArr[index] = val;
				return;
			}
			
			int mid = low + (high - low) >> 1;
			
			if(i <= mid){
				update(2*index+1, low, mid, i, val, arr);
			}else{
				update(2*index+2, mid+1, high, i, val, arr);
			}
			
			// update the new minimum
			segArr[index] = min(segArr[2*index+1], segArr[2*index+2]);	
		}
};
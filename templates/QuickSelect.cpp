int getPivotIndex(vector<int>& nums, int low, int high){
    int pivot_element = nums[high];
    int pivot_ind = low;
    for(int i=low; i<=high; i++){
        if(nums[i]<pivot_element){
            swap(nums[i], nums[pivot_ind]);
            pivot_ind++;
        }
    }
    swap(nums[high], nums[pivot_ind]);
    return pivot_ind;
}

int getKthElement(vector<int>& nums, int k, int low, int high){
    int n = nums.size();
    int ind = getPivotIndex(nums, low, high);
    if(ind==k) return nums[ind];
    else if(ind>k) return getKthElement(nums, k, low, ind-1);
    else return getKthElement(nums, k, ind+1, high);
    return -1;
}
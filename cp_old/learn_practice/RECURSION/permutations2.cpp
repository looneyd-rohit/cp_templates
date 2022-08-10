#include<bits/stdc++.h>
using namespace std;

void findPermutations(int index, vector<int>&nums, vector<vector<int>>&ans){
    // base case
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }

    // looping through to perform all the swapping operations
    // on first swap we swap i with i in order to ensure that, that particular
    // permutation is carried forward.
    for(int i=index; i<nums.size(); i++){
        // swap operation
        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;

        // recursive call for next round of operations
        findPermutations(index+1,nums,ans);

        // swap again to restore positions
        temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    // approach 2:
    // we go on swapping elements (do not use hash map) in order to get the permutations
    // also previous approach did not require a pointer(or index) variable, but here
    // need it to keep track of the swapping position. Here we also don't use the
    // temp array since we are performing swapping on original array.

    // answer array
    vector<vector<int>> ans;

    findPermutations(0,nums,ans);

    // for(auto i:ans){
    //     for(auto e:i){
    //         cout<<e<<" ";
    //     }cout<<endl;
    // }cout<<endl;

    // return
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    permute(nums);
    return 0;
}
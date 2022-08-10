#include<bits/stdc++.h>
using namespace std;

void findSubsetsWithDup(int index, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans){
    ans.push_back(temp);
    // base case
    if(index>=nums.size()){
        return;
    }
    
    // the subsets should not be duplicate, hence we follow "for" looped pick/not pick method
    for(int i=index; i<nums.size(); i++){
        
        // skipping duplicate start values
        int j,cnt=0;
        for(j=i; j<nums.size();j++){
            if(nums[j]==nums[i])
                cnt++;
            else{
                break;
            }
        }
        
        // pick
        temp.push_back(nums[i]);
        findSubsetsWithDup(i+1,nums,temp,ans);
        temp.pop_back();
        // not pick and proceed
        i = i + cnt - 1;
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
    // temporary array
    vector<int> temp;
    // answer array
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    findSubsetsWithDup(0,nums,temp,ans);
    cout<<ans.size()<<endl;
    for(auto& e:ans){
        for(auto& ee:e){
            cout<<ee<<" ";
        }cout<<endl;
    }cout<<endl;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    cin>>nums[i];
    subsetsWithDup(nums);
    return 0;
}
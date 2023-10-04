/*
Problem Link:
https://leetcode.com/problems/permutations/submissions/
*/

// [ COMPLETE MY APPROACH TO SOLVE THIS PROBLEM ]
// ONLY TOOK HELP ON HOW THIS RECURSION WORKS(RECURSION TREE).

class Solution {
private:
    void findPermutation(vector<int>&nums, map<int,int>&freqMap,vector<int>&temp, vector<vector<int>>&ans){
        
        // base case
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        // looping through all the possible points in the array for the array or string
        for(int i=0; i<nums.size(); i++){
            if(freqMap[nums[i]]==0){
                temp.push_back(nums[i]);
                freqMap[nums[i]] = 1;
                findPermutation(nums,freqMap,temp,ans);
                freqMap[nums[i]] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        // we keep a frequency array/map to keep track of the elements which are collected in a permutation
        map<int,int> freqMap;
        for(auto e:nums){
            freqMap.insert({e,0});
        }
        // temporary array
        vector<int> temp;
        // answer array
        vector<vector<int>> ans;
        
        // calling the function
        findPermutation(nums,freqMap,temp,ans);
        
        // return
        return ans;
    }
};
/*
Problem Link:
https://leetcode.com/problems/combination-sum/
*/

#include<bits/stdc++.h>
using namespace std;

void func(int index, int target, vector<int>& candidates,vector<int>& temp, vector<vector<int>>& ans){
    // base case
    if(target==0 && index<=candidates.size()){
        ans.push_back(temp);
        return;
    }else if(index>candidates.size()){
        return;
    }

    if(target>=candidates[index]){
        temp.push_back(candidates[index]);
        func(index,target-candidates[index],candidates,temp,ans);
        temp.pop_back();
    }

    func(index+1,target,candidates,temp,ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    func(0,target,candidates,temp,ans);
    for(auto& i:ans){
        for(auto& j:i){
            cout<<j<<" ";
        }cout<<endl;
    }cout<<endl;
    return ans;
}

int main(){
    vector<int> c(3);
    c[0] = 2;
    c[1] = 3;
    c[2] = 5;
    combinationSum(c,8);
    return 0;
}
/*
Problem Link:
https://leetcode.com/problems/combination-sum/
*/

#include<bits/stdc++.h>
using namespace std;

// we will use method(or trick) 2, to solve this problem, where we use use 
// loops inside of recursion to move from one call to the next
// (We may also solve this problem taking inspiration from combination sum 1, but
// then we will have to use set to store our answers which will result in additional
// space of log(n) getting multiplied as factor, so try to avoid that method.)

void func(int index, int target, vector<int>& candidates,vector<int>& temp, vector<vector<int>>& ans){
    // base case
    if(target==0){
        sort(temp.begin(),temp.end(),greater<int>());
        ans.push_back(temp);
        return;
    }else if(index>=candidates.size()){
        return;
    }

    // if we take any index we call function recursively for next index whereas
    // if we don't take any index we don't even call further
    for(int i = index; i<candidates.size(); i++){

        if(target>=candidates[i]){
            int j;
            for(j=i; j<candidates.size();){
                if(candidates[j]==candidates[i]){
                    j++;
                }else{
                    j = j-i;
                    break;
                }
            }
            temp.push_back(candidates[i]);
            func(i+1,target-candidates[i],candidates,temp,ans);
            temp.pop_back();
            i = i+j-1;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int> temp;
    vector<vector<int>> ans;
    sort(candidates.begin(),candidates.end());
    func(0,target,candidates,temp,ans);
    // for(auto& i:ans){
    //     sort(i.begin(),i.end(),greater<int>());
    // }
    // for(auto& i:ans){
    //     for(auto& j:i){
    //         cout<<j<<" ";
    //     }cout<<endl;
    // }cout<<endl;
    return ans;
}

int main(){
    vector<int> c(5);
    c[0] = 2;
    c[1] = 5;
    c[2] = 2;
    c[3] = 1;
    c[4] = 2;
    combinationSum2(c,6);
    return 0;
}
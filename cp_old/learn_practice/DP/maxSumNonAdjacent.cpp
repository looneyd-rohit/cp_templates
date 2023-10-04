#include<bits/stdc++.h>
using namespace std;
// findMaxSumNonAdjacent(int,vector) - returns a value of the maximum sum of 
// non adjacent subsequence.
int findMaxSumNonAdjacent(int index, vector<int> &nums){

    // base case
    if(index<0) return 0;

    // pick
    int p = nums[index] + findMaxSumNonAdjacent(index-2,nums);

    // not pick
    int np = 0 + findMaxSumNonAdjacent(index-1,nums);

    // return maximum at last
    return max(p,np);
}

// the optimized version of the above code(using memoization) is as follows:
int findMaxSumNonAdjacentMemoized(int index, vector<int> &nums, vector<int> &dp){
    
    // base case
    if(index<0) return 0;

    // checking if value already exists or not
    if(dp[index]!=INT_MIN) return dp[index];

    // else when value doesn't exist u are ok to proceed
    // pick
    int p = nums[index] + findMaxSumNonAdjacentMemoized(index-2,nums,dp);

    // not pick
    int np = 0 + findMaxSumNonAdjacentMemoized(index-1,nums,dp);

    // at last store the value in the dp array and return simulataneously
    return (dp[index] = max(p,np));
}
// we use the same method as we did for finding all subsequences previously
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    // this below code run is only using recursion
    // return findMaxSumNonAdjacent(nums.size()-1,nums);

    // now we [memoize] this code so that this can faster even consuming some extra space
    // vector<int> dp(nums.size(),INT_MIN);
    // return findMaxSumNonAdjacentMemoized(nums.size()-1,nums,dp);

    // since we are done with memoization let's try tabulation(bottom up approach)
    // vector<int> dp(nums.size(),INT_MIN);
    // dp[0] = nums[0];
    // for(int i=1; i<nums.size(); i++){

    //     // pick
    //     int p=nums[i];
    //     if(i>=2)
    //     p = p + dp[i-2];

    //     // not pick
    //     int np = dp[i-1];

    //     dp[i] = max(p,np);
    // }
    // return dp[nums.size()-1];

    // now let's move on to space optimization
    int cur = nums[0];
    int prev1, prev2;
    prev1 = nums[0];
    prev2=nums[0];
    for(int i=1; i<nums.size(); i++){

        // pick
        int cur1=nums[i];
        if(i>=2)
        cur1 = cur1 + prev2;

        // not pick
        int cur2 = prev1;

        cur = max(cur1,cur2);
        prev2=prev1;
        prev1=cur;
    }
    return cur;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
    cin>>nums[i];
    cout<<maximumNonAdjacentSum(nums)<<endl;
    return 0;
}
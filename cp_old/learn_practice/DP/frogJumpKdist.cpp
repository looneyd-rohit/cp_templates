/*
Problem link:
https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
*/
#include<bits/stdc++.h>
using namespace std;

// firstly we devise a function (recursive) which evaluates for any 'n' => the
// minimum required to go from n to 0 or vice versa. Then we proceed on recursively
// calling the funciton.

// we are required to move from 0-th to (n-1)-th position, so once we reach
// 0-th position from (n-1)-th position we return without further calls.
// here n -> no. of items, so we use (+1) everywhere
int frogJumpKdist(int n,int k, vector<int>&heights){
    // base case
    if(n==1) return 0;

    // looping through all the possible positions where the frog can jump
    // starting from a particular n.
    int cur=0, m = INT_MAX;
    for(int i=1; i<=k; i++){
        if(n>i){
            cur = frogJumpKdist(n-i,k,heights) + abs(heights[n-1] - heights[n-i-1]);
            m = min(m,cur);
        }
    }
    // cout<<"m= "<<m<<endl;
    return m;
}

// once we solved this problem using recursion we are now in position to apply
// memoization and then tabulation and finally space optimization.
int func(int index,int k,vector<int>& heights, vector<int>& dp){
    if(index==0) return 0;

    // check if already exists
    if(dp[index]!=INT_MAX) return dp[index];

    int  cur = 0, m = INT_MAX;
    for(int i=1; i<=k; i++){
        if(index>=i){
            cur = func(index-i,k,heights,dp) + abs(heights[index] - heights[index-i]);
            m = min(m,cur);
        }
    }
    return dp[index] = m;
}
int frogJumpKdistMemoized(int n,int k, vector<int>& heights){
    // memoized
    vector<int> dp(n,INT_MAX);
    // return func(n-1,k,heights,dp);


    // tabulation
    dp[0] = 0;      // energy exhausted from 0 to 0 is 0 only.
    for(int i=1; i<n; i++){
        int cur,m=INT_MAX;
        for(int j=1; j<=k; j++){
            if(i>=j){
                cur = dp[i-j] + abs(heights[i] - heights[i-j]);
                m = min(m,cur);
            }
        }
        dp[i] = m;
    }
    return dp[n-1];

    // since at any stage of this dp we are only involving the previous two terms
    // so we can definitely convert this to a space optimised solution.
}



int main(){
    int n;
    int k;
    cin>>n;
    cin>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    // cout<<frogJumpKdist(n,k,v)<<endl;
    cout<<frogJumpKdistMemoized(n,k,v)<<endl;
    return 0;
}
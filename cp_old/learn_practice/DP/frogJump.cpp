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
int frogJump(int n, vector<int>&heights){
    // base case
    if(n==1) return 0;


    int left = frogJump(n-1,heights) + abs(heights[n-1] - heights[n-2]);

    // when n<=2 (less or equal to 2 elements) there is no need to call for 
    // (n-2) since we need to stop when there is only 1 element in the array.
    int right;
    if(n>2){
        right = frogJump(n-2,heights) + abs(heights[n-1] - heights[n-3]);
    }else{
        right = left;
    }

    return min(left,right);

}

// once we solved this problem using recursion we are now in position to apply
// memoization and then tabulation and finally space optimization.
int func(int index, vector<int>& heights, vector<int>& dp){
    if(index==0) return 0;

    // check if already exists
    if(dp[index]!=INT_MAX) return dp[index];

    int left = func(index-1,heights,dp) + abs(heights[index] - heights[index-1]);

    int right = INT_MAX;
    if(index>1) right = func(index-2,heights,dp) + abs(heights[index] - heights[index-2]);

    return (dp[index] = min(left,right));
}
int frogJumpMemoized(int n, vector<int>& heights){
    // memoized
    vector<int> dp(n,INT_MAX);
    return func(n-1,heights,dp);


    // tabulation
    dp[0] = 0;      // energy exhausted from 0 to 0 is 0 only.
    for(int i=1; i<n; i++){
        int first = dp[i-1] + abs(heights[i] - heights[i-1]);
        int second=first;
        if(i>1){
            second = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(first,second);
    }
    return dp[n-1];

    // since at any stage of this dp we are only involving the previous two terms
    // so we can definitely convert this to a space optimised solution.
}



int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
    cin>>v[i];
    cout<<frogJump(n,v)<<endl;
    cout<<frogJumpMemoized(n,v)<<endl;
    return 0;
}
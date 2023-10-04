#include<bits/stdc++.h>
using namespace std;

int fibonacci(int (&dp)[], int n){
    if(n<0)
    return 0;

    if(n<=1){
        dp[n]=n;
    }

    if(dp[n]==-1){
        dp[n] = fibonacci(dp,n-1) + fibonacci(dp,n-2);
        // return dp[n];
    }else{
        // return dp[n];
    }
    return dp[n];

}

int main(){
    int n;
    cout<<"Enter the value of n= ";
    cin>>n;
    int dp[n+1];
    memset(dp,-1,sizeof(int)*(n+1));
    for(int i=0; i<n+1; i++)
    cout<<dp[i]<<" ";
    cout<<endl;
    
    fibonacci(dp,n);
    cout<<dp[n]<<endl;

    for(int i=0; i<n+1; i++)
    cout<<dp[i]<<" ";
    cout<<endl;

    // space optimized solution
    int prev2 = 0, prev = 1, cur;
    for(int i=2; i<=n; i++){
        cur = prev + prev2;
        prev2 = prev;
        prev = cur;
    }
    cout<<cur<<endl;

    return 0;
}
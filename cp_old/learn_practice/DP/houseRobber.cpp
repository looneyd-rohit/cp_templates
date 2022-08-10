#include<bits/stdc++.h>
using namespace std;

long long int findMaxLoot(int index, int s,vector<int>& valueInHouse){
    // base case
    if(index<s) return 0;

    // pick or not pick method
    // pick:
    long long int temp = valueInHouse[index];
    valueInHouse[index] = -1;
    long long int pick = temp + findMaxLoot(index-2,s,valueInHouse);
    valueInHouse[index] = temp;

    // not pick:
    long long int notPick = 0 + findMaxLoot(index-1,s,valueInHouse);

    // return
    return max(pick,notPick);
}

long long int findMaxLootMemoized(int index,int s, vector<int>& valueInHouse, vector<int>&dp){
    // base case
    if(index<s) return 0;

    // check if already value is present in array
    if(dp[index]!=-1) return dp[index];

    // pick or not pick method
    // pick:
    long long int temp = valueInHouse[index];
    valueInHouse[index] = -1;
    long long int pick = temp + findMaxLootMemoized(index-2,s,valueInHouse,dp);
    valueInHouse[index] = temp;

    // not pick:
    long long int notPick = 0 + findMaxLootMemoized(index-1,s,valueInHouse,dp);

    // return
    return (dp[index] = max(pick,notPick));
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    cout<< max(findMaxLoot(valueInHouse.size()-1,1,valueInHouse),findMaxLoot(valueInHouse.size()-2,0,valueInHouse))<<endl;

    // now we memoize the code
    // dp array
    vector<int> dp1(valueInHouse.size(),-1);
    vector<int> dp2(valueInHouse.size(),-1);
    return max(findMaxLootMemoized(valueInHouse.size()-1,1,valueInHouse,dp1),findMaxLootMemoized(valueInHouse.size()-2,0,valueInHouse,dp2));
}

int main(){
    int n;
    cin>>n;
    vector<int> valueInHouse(n);
    for(int i=0; i<n; i++){
        cin>>valueInHouse[i];
    }
    cout<<houseRobber(valueInHouse)<<endl;
    return 0;
}
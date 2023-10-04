#include<bits/stdc++.h>
using namespace std;

int printAllSubsequences(int index,int sum, int k, int arr[], int n){
    // base case:
    if(index==n){
        if(sum == k){
        // condition satisfied
        return 1;
        }
        // condition not satisfied
        else
        return 0;
    }

    // take the current index

    sum = sum + arr[index];
    int l=printAllSubsequences(index+1,sum,k,arr,n);
    sum = sum - arr[index];


    // not take condition executes only when previous call does not get any result
    int r=printAllSubsequences(index+1,sum,k,arr,n);

    return (l+r);
}
int main(){
    // int arr[]{2,1,5,3,4};
    int arr[]{1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 0, k=3;
    cout<<printAllSubsequences(0,sum,k,arr,size);
    return 0;
}
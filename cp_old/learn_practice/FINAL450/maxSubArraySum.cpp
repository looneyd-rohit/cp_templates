/*
To compute the maximum subarray sum we use the famous Kadane's Algorithm
to reach the solution.
*/

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[],int size){
    int sum=arr[0],max=arr[0];
    for(int i=1; i<size; i++){
        sum = sum + arr[i];
        
        if(sum<arr[i]){
            sum=arr[i];
        }

        if(sum>max){
            max=sum;
        }
    }
    return max;
}

int main(){
    int arr[]{-1,-2,-3,-4};
    int size = sizeof(arr)/sizeof(int);
    cout<<maxSubArraySum(arr,size)<<endl;
    return 0;
}
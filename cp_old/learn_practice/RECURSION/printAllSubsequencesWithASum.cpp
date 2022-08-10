#include<bits/stdc++.h>
using namespace std;

// take subArr as reference as we are pushing and popping to the same array and need to keep track of it
void printAllSubsequences(vector<int>& subArr, int index,int sum, int k, int arr[], int n){
    // base case:
    if(index>=n){
        if(sum == k){
        // print out the subsequence and get lost
        cout<<"{ ";
        for(auto &e:subArr){
            cout<<e<<" ";
        }cout<<'}'<<endl;
        }
        return;
    }

    // take the current index
    subArr.push_back(arr[index]);
    // sum = sum + arr[index];
    printAllSubsequences(subArr,index+1,sum+arr[index],k,arr,n);
    subArr.pop_back();
    // sum = sum - arr[index];

    // not take condition
    printAllSubsequences(subArr,index+1,sum,k,arr,n);
}
int main(){
    // int arr[]{2,1,5,3,4};
    int arr[]{1,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> subArr;
    int sum = 0, k=3;
    printAllSubsequences(subArr,0,sum,k,arr,size);
    return 0;
}
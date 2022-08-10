#include<bits/stdc++.h>
using namespace std;

// take subArr as reference as we are pushing and popping to the same array and need to keep track of it
void printAllSubsequences(vector<int>& subArr, int index, int arr[], int n){
    // base case:
    if(index>=n){
        // print out the subsequence and get lost
        cout<<"{ ";
        for(auto &e:subArr){
            cout<<e<<" ";
        }cout<<'}'<<endl;
        return;
    }

    // take the current index
    subArr.push_back(arr[index]);
    printAllSubsequences(subArr,index+1,arr,n);
    subArr.pop_back();

    // not take condition
    printAllSubsequences(subArr,index+1,arr,n);
}
int main(){
    // int arr[]{2,1,5,3,4};
    int arr[]{3,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    vector<int> subArr;
    printAllSubsequences(subArr,0,arr,size);
    return 0;
}
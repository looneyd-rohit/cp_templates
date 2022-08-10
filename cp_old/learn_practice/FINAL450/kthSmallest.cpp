#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int size, int k){
    priority_queue<int> maxHeap;
    for(int i=0; i<size; i++){
        maxHeap.push(arr[i]);
        if(maxHeap.size()>k){
            maxHeap.pop();
        }
    }
    return maxHeap.top();
}


int main(){
    int arr[]{7,10,4,3,20,15};
    int size = sizeof(arr)/sizeof(int);
    cout<<kthSmallest(arr,size,3)<<endl;
    return 0;
}
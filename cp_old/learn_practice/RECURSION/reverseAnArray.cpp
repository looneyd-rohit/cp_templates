#include<bits/stdc++.h>
using namespace std;

void reverseAnArray(int arr[],int size,int i){
    if(i>size/2)
    return;
    arr[i] = arr[size - i - 1];
    reverseAnArray(arr,size,i+1);
}

int main(){
    int arr[]{2,3,4,7,8,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<size; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    reverseAnArray(arr,size,0);
    for(int i=0; i<size; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
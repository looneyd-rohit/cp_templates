#include<bits/stdc++.h>
using namespace std;

void showArray(int arr[],int size){
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

void moveNegativeLast(int arr[],int size){
    int i=0, j=size-1;
    while(i<=j){
        if(arr[i]>0 && arr[j]>0){
            i++;
        }else if(arr[i]>0 && arr[j]<0){
            i++;
            j--;
        }else if(arr[i]<0 && arr[j]<0){
            j--;
        }else if(arr[i]<0 && arr[j]>0){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
}

int main(){
    int arr[]{-1,2,3,4,-9,7,6,5,-5,-4,3};
    int size = sizeof(arr)/sizeof(int);
    moveNegativeLast(arr,size);
    showArray(arr,size);
    return 0;
}
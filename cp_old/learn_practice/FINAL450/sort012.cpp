#include<bits/stdc++.h>
using namespace std;

void swap(int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sort012(int a[], int n)
{
    // code here

    // 3pointer approach
    int i=-1, j=0, k=n-1;
    while(j<=k){
        // if smaller than 1 then do swapping once and then increment i
        if(a[j]==0){
            swap(a+i+1,a+j);
            i++;
        }
        // if equal to 1 then move on
        else if(a[j]==1){
            j++;
        }
        // if greater than 1 then swap with last element k as the greater always
        // sits at the last
        else if(a[j]==2){
            swap(a+j,a+k);
            k--;
        }
    }
}


int main(){
    int arr[]{0,2,1,2,0};
    int size = sizeof(arr)/sizeof(int);
    sort012(arr,size);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    return 0;
}
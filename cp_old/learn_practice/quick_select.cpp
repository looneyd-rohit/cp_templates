#include<bits/stdc++.h>
using namespace std;

int p_finder(int *arr, int left, int right)
{
    int i = left - 1, j;
    int pivot = arr[right];
    for (j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    i++;
    {
        int temp = arr[i];
        arr[i] = arr[right];
        arr[right] = temp;
    }
    return i;
}

int quickSelect(int *arr,int right, int k){
    if(right>=k){
        int par = p_finder(arr,0,right);
        return quickSelect(arr,right-1,k);
    }
    if(right==0){
        return arr[0];
    }
}

int main(){
    int arr[]{1,3,6,7,2,9,8,4};
    int size = sizeof(arr)/sizeof(int);
    cout<<quickSelect(arr,size-1,3)<<endl;
    return 0;
}
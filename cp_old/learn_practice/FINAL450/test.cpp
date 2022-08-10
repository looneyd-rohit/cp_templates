// // #include<bits/stdc++.h>
// // using namespace std;

// // long getMaxProfit(vector<int> prices) {
// // 		// Code here
// // 		using namespace std;
// // 		long buy = prices[0];
// //         long sell = 0, ac = 0;
// // 		long prev=0;
// // 		for(long i=1; i<prices.size(); i++){
// // 			if(prices[i]>buy){
// // 				sell=prices[i];
// //                 ac = ac + sell - buy;
// //                 buy=sell;
// // 			}
// // 			else if(prices[i]<=buy){
// // 				buy = prices[i];
// // 			}
// // 		}
// // 		return ac;
// // 	}


// // int main(){
// //     vector<int> prices = {9,1,3,2,4,7,9};
// //     cout<<getMaxProfit(prices)<<endl;
// //     return 0;
// // }


// #include<bits/stdc++.h>
// using namespace std;


// void mergeArrays(int arr1[], int arr2[], int n, int m) {
// 	    // code here
// 	    // int gap = ceil((float)(n+m)/(float)2);
// 		int gap = (n+m+1)/2;
// 	    while(gap){
	        
// 	        for(int i=0,j; (i+gap)<(n+m); i++){
// 	            if((i+gap)<n){
	                
// 	                if(arr1[i]>arr1[i+gap]){
// 	                    int temp = arr1[i];
// 	                    arr1[i]=arr1[i+gap];
// 	                    arr1[i+gap]=temp;
// 	                }
	                
// 	            }else if((i+gap)>=n && i<n){
	                
// 	                j = i+gap-n;
// 	                if(arr1[i]>arr2[j]){
// 	                    int temp = arr1[i];
// 	                    arr1[i]=arr2[j];
// 	                    arr2[j]=temp;
// 	                }
	                
// 	            }else if(i>=n){
	                
// 	                j=i-n;
// 	                if(arr2[j]>arr2[j+gap]){
// 	                    int temp = arr2[j];
// 	                    arr2[j]=arr2[j+gap];
// 	                    arr2[j+gap]=temp;
// 	                }
	                
// 	            }
// 	        }
// 	        if(gap==1)
// 			break;
	        
// 	        gap = (gap+1)/2;
	        
// 	    }
	    
// 	}


// int main(){
// 	int arr1[]{1,3,5,7};
// 	int arr2[]{0,2,6,8,9};
// 	int n = sizeof(arr1)/sizeof(int);
// 	int m = sizeof(arr2)/sizeof(int);

// 	mergeArrays(arr1,arr2,n,m);

// 	for(int i=0; i<n; i++)
// 	cout<<arr1[i]<<" ";
// 	cout<<endl;
	
// 	for(int i=0; i<m; i++)
// 	cout<<arr2[i]<<" ";
// 	cout<<endl;

// 	return 0;
// }



#include<bits/stdc++.h>
using namespace std;
int maxSteps(int arr[], int h, int ctr){
	cout<<"ctr= "<<ctr<<endl;
	if(h==0)
	return ctr;
	int dist=h-1;
	for(int i=h-1; i>=0; i++){
		if((i+arr[i])>=h)
		dist=i;
	}
	h=dist;
	ctr++;
	return maxSteps(arr,h,ctr);
}
int main(){
	int arr[]{1,5,4,3,2,1,1};
	int size=sizeof(arr)/sizeof(int);
	int steps=maxSteps(arr,size-1,0);
	cout<<"maxSteps= "<<steps<<endl;
	return 0;
}
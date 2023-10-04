// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
    
private:
    void findSubsetSum(int index,int sum, vector<int>&arr, vector<int>&ds){
        // base case
        if(index<0){
            ds.push_back(sum);
            return;
        }
        
        // pick/not pick method:
        // pick
        findSubsetSum(index-1,sum+arr[index],arr,ds);
        
        // not pick
        findSubsetSum(index-1,sum+0,arr,ds);
        
        // return after calls are completed
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        
        // vector to store our resultant sum array
        vector<int> ds;
        findSubsetSum(N-1,0,arr,ds);
        return ds;
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
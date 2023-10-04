#include<bits/stdc++.h>
using namespace std;

int noOfSwaps(vector<int>arrA, vector<int>arrB){
    vector<pair<int,int>> arr1, arr2;
    // n
    for(int i=0; i<arrA.size(); i++){
        arr1.push_back({arrA[i],i});
    }
    // n
    for(int i=0; i<arrB.size(); i++){
        arr2.push_back({arrB[i],i});
    }

    // sorting:
    // nlog(n)
    sort(arr1.begin(),arr1.end());
    // nlog(n)
    sort(arr2.begin(),arr2.end());

    // graph construction
    // n
    for(int i=0; i<arrA.size(); i++){
        arr2[i].first = arr1[i].second;
    }

    // we only need arr2 now (arr2 is our desired graph)
    int swaps = 0;
    f// now do dfs/bfs and count the length of all the cycles and subsequently
    // subtract 1 from each.
    return swaps;
}

int main(){
    vector<int> arrA = {2,9,1,6,15,7,8,4};
    vector<int> arrB = {7,15,4,1,9,2,6,8};

    cout<<"swaps = "<<noOfSwaps(arrA,arrB)<<endl;
    return 0;
}
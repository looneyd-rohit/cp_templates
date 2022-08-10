/*
 * Problem Link:
 * https://leetcode.com/problems/global-and-local-inversions/
 * 
*/

#include <bits/stdc++.h>
using namespace std;
#define     mod            1e9+7
#define     ll             long long
#define     f(i,n)         for( int i=0;i<n;i++)
#define     fe(i,a,b)      for( int i=a;i<b;i++)
#define     fr(i,a,b)      for( int i=a;i>=b;i--)
#define	 v(type)		std::vector<type>
#define     pb(a)          push_back(a)
#define     em(x,y)        emplace(x,y)
#define     emb(x)         emplace_back(x)
#define     vmax(x,y)      *max_element(x,y)
#define     ub             upper_bound
#define     lb             lower_bound
#define     nsync          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     t()            int t; cin>>t; while(t--)




int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    t(){
    int n;
    cin>>n;
    vector<int> arr(n);
    // vector<int> temp(n);
    map<int,int> temp;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        temp.insert({arr[i],i});
    }

    // main logic
    int li=0;
    for(int i=0; i<n-1; i++){
        if(arr[i]>arr[i+1])
        li++;
    }

    sort(arr.begin(),arr.end());

    int gi = 0;
    for(int i=0; i<n; i++){
        if(temp[arr[i]]<=i){
            gi = gi + (arr[i]-1);
        }
        else if(temp[arr[i]]>i){
            gi = gi + (arr[i]-1) + abs(temp[arr[i]]-i);
        }
    }
    cout<<gi<<endl;
    if(li==gi)
    cout<<true<<endl;
    else
    cout<<false<<endl;
    }
    return 0;
}




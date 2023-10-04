#include <bits/stdc++.h>
using namespace std;
#define     mod            1e9+7
#define     ll             long long
#define     f(i,n)         for( int i=0;i<n;i++)
#define     fe(i,a,b)      for( int i=a;i<b;i++)
#define     fr(i,a,b)      for( int i=a;i>=b;i--)
#define  v(type)        std::vector<type>
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
        // int n;
        // cin>>n;
        // int arr[n];
        // f(i,n){
        //     cin>>arr[i];
        // }
        // // sort(arr,arr+n);
        // // cout<<(arr[n-1] - arr[0])*arr[n-2]<<'\n';
        // int max = 0;
        // int min = 0;
        // fe(i,1,n){
        //     if(arr[i]>arr[max])
        //         max = i;
        // }
        // fe(i,1,n){
        //     if(arr[i]<arr[min] && i!=max)
        //         min = i;
        // }
        // int value=INT_MIN;
        // fe(i,0,n){
        //     if(i!=max && i!=min){
                
        //     int temp=(arr[max]-arr[min])*arr[i];
        //     if(value<=temp )
        //         value = temp;
        //     }
        // }
        // cout<<value<<'\n';

        int n;
        string s;
        cin>>n;
        cin>>s;
        int cnt0=0, cnt1=0;
        f(i,n){
            if(s[i] == '0')
                cnt0++;
            else
                cnt1++;
        }
        int min = (cnt0>cnt1)?cnt1:cnt0;
        if(n<4)
            cout<<0;
        else if(min>1)
            cout<<min-1;
        else
            cout<<0;
        cout<<'\n';

    }
    return 0;
}
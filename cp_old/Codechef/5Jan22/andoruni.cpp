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
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int> calBit(30,0);
    for(int i=0; i<n; i++){
        for(int j=0; j<30; j++){
            calBit[j] += ((arr[i] & (1<<j))>0)?1:0;
        }
    }
    int ans = 0;
    for(int j=0; j<30; j++){
        if(calBit[j]>=2){
            ans = ans | (1<<j);
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
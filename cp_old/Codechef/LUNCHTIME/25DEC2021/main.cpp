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
        int n;
        int k;
        cin>>n>>k;
        string s;
        cin>>s;
        int start=0, cnst= k/2;
        if(k%2==1){
            cout<<s[cnst];
            start = 1;
            while((cnst-start)>=0 && (cnst+start)<k){
            cout<<s[cnst+start];
            cout<<s[cnst-start];
            start++;
        }
        }
        else{
        while((cnst-start-1)>=0 && (cnst+start)<k){
            cout<<s[cnst+start];
            start++;
            cout<<s[cnst-start];
        }
        }

        // int i = cnst+start;
        while(k<n){
            cout<<s[k];
            k++;
        }
        cout<<'\n';
    }
    return 0;
}
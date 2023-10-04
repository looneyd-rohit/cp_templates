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


int calculate(int x, int m){
    if(x==1)
    return 1;

}

int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    t(){
        long long int m,x;
        cin>>m>>x;
        vector<int> ans(x+1);
        m = m-1;
        if(m==1){
            for(int i=1; i<=x; i++){
                ans[i] = 1;
            }
        }
        else if(m%2==0){
            for(int i=1; i<=x; i++){
                if(i<=m)
                ans[i] = i;
                else{
                    ans[i] = m;
                }
            }
        }else{
            for(int i=1; i<=x; i++){
                if(i<m){
                    ans[i] = 1;
                }else{
                    ans[i] = 2;
                }
            }
        }

        // output
        for(int i=1; i<=x; i++){
            cout<<ans[i]<<' ';
        }cout<<endl;
        
    }
    return 0;
}
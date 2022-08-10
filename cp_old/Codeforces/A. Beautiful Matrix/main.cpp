#include <bits/stdc++.h>
using namespace std;
#define     mod            1e9+7
#define     ll             long long
#define     f(i,n)         for( int i=0;i<n;i++)
#define     fe(i,a,b)      for( int i=a;i<b;i++)
#define     fr(i,a,b)      for( int i=a;i>=b;i--)
#define     v(type)        std::vector<type>
#define     pb(a)          push_back(a)
#define     em(x,y)        emplace(x,y)
#define     emb(x)         emplace_back(x)
#define     ub             upper_bound
#define     lb             lower_bound
#define     nsync          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     t()            int t; cin>>t; while(t--)
#define N 5
int32_t main()
{

    nsync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int a[N][N];
    int i, j, i_pos, j_pos;
    for( i=0; i<N; i++)
        for(j=0; j<N; j++){
            cin>>a[i][j];
            if(a[i][j]==1){
                i_pos=i;
                j_pos=j;
            }
        }
    cout<<abs(i_pos-2)+abs(j_pos-2)<<endl;
    return 0;
}
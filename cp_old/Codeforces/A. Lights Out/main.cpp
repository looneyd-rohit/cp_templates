#include <bits/stdc++.h>
using namespace std;
#define     mod            1e9+7
#define     ll             long long
#define     f(i,n)         for(i=0;i<n;i++)
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


int32_t main()
{

    nsync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int i, j;
    int a[3][3],sum;
    f(i,3){
        f(j,3){
        cin>>a[i][j];
        a[i][j] = a[i][j]%2;
        }
    }
    f(i,3){
        f(j,3){
            sum = 0;
            fe(k,0,3){
                fe(l,0,3)
                if(abs(k -i)<=1 && abs(l-j)<=1)
                    sum+=a[k][l];
            }
            if(sum%2==1)
                cout<<0;
            else
                cout<<1;
            }
            cout<<endl;
        }
    return 0;
}
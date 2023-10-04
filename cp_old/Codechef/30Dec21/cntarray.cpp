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


unsigned long long int factorial(unsigned long long int n){
    unsigned long long int temp = 1;
    if(n<=1)
    return 1;
    fe(i,1,n+1){
        temp = temp*i;
    }
    return temp;
}

int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
    #endif
    t(){
    int n,m,count=0;
    cin>>n>>m;
    vector<int> b(n);
    fe(i,0,n){
        cin>>b[i];
        if(b[i]<=m)
        count++;
    }
    unsigned long long int st = factorial(m);
    st = st - (count * (factorial(m-1)));
    st = st + ((count-1)*(factorial(m-count)));
    st = st/factorial(m-n);
    st = st % ((unsigned long long int)1e9 + 7);
    cout<<st<<endl;
    }
    return 0;
}
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


bool is_unique(int n){
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    for(int i=0; i<s.length();i++){
        for(int j=i+1; j<s.length();j++)
        if(s[j]==s[i])
            return false;
    }
    return true;
}

int32_t main()
{

    nsync;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int n;
    cin>>n;
    n++;
    while(is_unique(n)!=true){
        n++;
    }
    cout<<n<<endl;
    return 0;
}
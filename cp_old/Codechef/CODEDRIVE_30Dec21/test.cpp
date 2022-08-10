#include <bits/stdc++.h>
using namespace std;
#define     mod            1e9+7
#define     ll             long long
#define     ull            unsigned long long
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


int checkarr(ull int p){
    int count=0;
    while(p){
        if(p%10==4 || p%10==7){
            count++;
        }
        p=p/10;
    }
    return count;
}
int32_t main()
{

    nsync;
#ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // freopen("error.txt", "w", stderr);
#endif
       t(){
       	int n,k;
       	cin>>n>>k;
       	string s;
       	cin>>s;
       	int i,j;
       	// vector<int> storage(k,0);
           int prev=0,next=0,count = 0;
       	for(i=0;i<n-k+1; i++)
       		// storage[0] = storage[0]^((int)s[i] - 48);
            prev = prev^((int)s[i] - 48);
        if(prev ==1 )
        count++;
       	for(j=1; j<k && i<n; j++, i++){
       		// storage[j] = (storage[j-1])^((int)s[i] - 48)^((int)s[j-1] - 48);
            next = prev^((int)s[i] - 48)^((int)s[j-1] - 48);
            if(next ==1 )
            count++;

       	}
           cout<<count<<endl;


    }
    return 0;
}
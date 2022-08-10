#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define     mod             1e9+7
#define     MOD             998244353
#define     ll              long long
#define     mp              make_pair
#define     F               first
#define     S               second
#define     pb              emplace_back
#define     pf              emplace_front
#define     all(p)          p.begin(), p.end()
#define     rep(i,a,b)      for( i=a;i<b;++i)
#define     repr(i,a,b)     for( i=a;i>=b;i--)
#define     up              upper_bound
#define     lb              lower_bound
#define     t()             int test;cin>>test;while(test--)
#define     setbits(x)      __builtin_popcountll(x)
#define     si              set<int>
#define     ii              pair<int,int>
#define     que_max         priority_queue <int>
#define     que_min         priority_queue <int, vi, greater<int> >
#define     isOn(S, j)      (S & (1 << j))
#define     setBit(S, j)    (S |= (1 << j))
#define     clearBit(S, j)  (S &= ~(1 << j))
#define     toggleBit(S, j) (S ^= (1 << j))
#define     lowBit(S)       (S & (-S))
#define     setAll(S, n)    (S = (1 << n) - 1)
#define     isPowerOfTwo(S) (!(S & (S - 1)))
#define     nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define     turnOffLastBit(S) ((S) & (S - 1))
#define     turnOnLastZero(S) ((S) | (S + 1))
#define     turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define     turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            "\n"
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif

int N=1e5;    

 
int32_t main()
 
{  
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output 2.txt", "w", stdout);
    #endif

    IOS;

   t()
   {
     int n,x,i;
     cin>>n;
     x=100,i=9;
     while(n--)
     {
       trace(n,x,i);
        x++;
        i--;
     }
   }
    

   
}
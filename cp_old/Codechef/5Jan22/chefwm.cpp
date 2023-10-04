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

int seive(int num){
    int temp = num;
    int count = 0;
    if(temp%2==0){
        count++;
        while(temp%2==0)
        temp = temp>>1;
        
    }
    if(temp%3==0){
        count++;
        while(temp%3==0)
        temp = temp/3;

    }
    for(int i=5; i*i<=temp; i+=6){
        if(temp%i == 0){
            count++;
            while(temp%i==0)
            temp = temp/i;
        }
        if(temp%(i+2) == 0){
            count++;
            while(temp%(i+2)==0)
            temp = temp/(i+2);
        }
    }
    return count;
}


int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    t(){
    int n,m,temp;
    cin>>n>>m;
    int countN = seive(n);
    int countM = seive(m);
    if(m==1){
        cout<<0<<endl;
        continue;
    }
    if(countN==0||countM==0){
        cout<<1<<endl;
        continue;
    }
    int ans = (countM>countN)?countM:countN;
    while(ans){
        if(n%ans ==0){
            cout<<ans<<endl;
            break;
        }
        ans--;
    }
    }
    return 0;
}
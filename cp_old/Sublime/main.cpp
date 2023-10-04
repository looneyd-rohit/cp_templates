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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
       t(){
       	unsigned long long int n, flag=1;
       	cin>>n;
   		if(n%2==0){
   			cout<<2;
   			flag=0;
   		}
   		else if(n%3==0){
   			cout<<3;
   			flag=0;
   		}
   		else{
   			for(unsigned long long int i=5; i*i<n; i+=6){
   			if(n%(i) == 0){
   				cout<<i;
   				flag=0;
   				break;
	   			}
   			else if(n%(i+2)==0){
   				cout<<i+2;
   				flag=0;
   				break;
	   			}
	   			flag++;
			}	
       	}
       	if(flag)
       		cout<<n;
       	cout<<endl;

    }
    return 0;
}
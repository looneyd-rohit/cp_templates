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


unsigned long long int counter(const string &s){
    unsigned long long int cnt=0;
    int i=0;
    while(s[i]!='\0'){
        for(int j=i+1;j<s.length(); j++){
            if(s[i]=='1' && s[j]=='0')
            cnt++;
        }
        i++;
    }
    return cnt;
}

int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    t(){
    int n;
    cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    string c=a;
    int bIndex = 0;
    int lastIndex = -1;
    // cout<<endl;
    // cout<<counter("01010101");
    // cout<<endl;
    while(bIndex<b.length()){
        string tempStr;
        unsigned long long int cnt = INT_MAX;
        unsigned long long int temp = cnt;
        int atWhichIndexMin=lastIndex+1;

        for(int i=lastIndex+1; i<=a.length(); i++){
            cnt = min(cnt,counter(a.substr(0,i) + b[bIndex] + a.substr(i,a.length()-i)));
            // cout<<"cnt="<<cnt<<endl;
            if(temp!=cnt){
                lastIndex=i;
            }
            temp = cnt;
        }
        tempStr = a.substr(0,lastIndex) + b[bIndex] + a.substr(lastIndex,a.length()-lastIndex);
        a = tempStr;
        // lastIndex = atWhichIndexMin;
        // cout<<a<<endl;
        bIndex++;
    }
    // cout<<a<<endl;
    cout<<counter(a)<<endl;
    }
    return 0;
}
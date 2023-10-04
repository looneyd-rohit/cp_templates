#include <bits/stdc++.h>
using namespace std;
#define     mod            1e9+7
#define     ll             long long
#define     f(i,n)         for( int i=0;i<n;i++)
#define     fe(i,a,b)      for( int i=a;i<b;i++)
#define     fr(i,a,b)      for( int i=a;i>=b;i--)
#define	    v(type)		    std::vector<type>
#define     pb(a)          push_back(a)
#define     em(x,y)        emplace(x,y)
#define     emb(x)         emplace_back(x)
#define     vmax(x,y)      *max_element(x,y)
#define     ub             upper_bound
#define     lb             lower_bound
#define     nsync          ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define     t()            int t; cin>>t; while(t--)




int32_t main(){
    nsync;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    // t(){
    
    // }

    int arr[]  {1,0,-1,0,-2,2};
    int size = sizeof(arr)/sizeof(int);
    set<vector<int>> s;
    vector<int> v;
    for(int i=0; i<size; i++)
    v.pb(arr[i]);
    int target = 0;

    // actual code
    sort(v.begin(),v.end());
    for(int i=0; i<size-3; i++){
        if(i==0 || (i>0 && v[i]!=v[i-1])){

        for(int j=i+1; j<size-2; j++){
            if(j==0 || (j>0 && v[j]!=v[j-1])){

                // actual loop for 2 pointer sum
            int left = j+1, right = size-1;
            int sum = target - v[i] - v[j];
            while(left<right){

                int req = (v[left] + v[right]);
                if(req == sum){
                    vector<int> aux;
                    aux.pb(v[i]);
                    aux.pb(v[j]);
                    aux.pb(v[left]);
                    aux.pb(v[right]);
                    sort(aux.begin(),aux.end());
                    s.insert(aux);

                    // even more optimising the code
                    while(left<right && v[left]==v[left+1])left++;
                    while(left<right && v[right]==v[right-1])right--;

                    left++;
                    right--;
                }else if(req<sum)
                left++;
                else
                right--;
            }

            }
        }
        }
    }

    for(auto i=s.begin(); i!=s.end(); i++){
        for(auto j=(*i).begin(); j!=(*i).end(); j++){
            cout<<*j<<" ";
        }cout<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = 0;
    for(int i=0; i<n; i++){
        cnt = n - i;
        for(int j=0; j<n; j++){
            cout<<cnt%(n) + 1<<" ";
            cnt = (cnt+1)%(n);
        }
        cout<<endl;
    }
    return 0;
}
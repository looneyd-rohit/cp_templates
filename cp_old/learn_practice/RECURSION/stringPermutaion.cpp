#include<bits/stdc++.h>
using namespace std;

bool findPermutation(int index,string&op, vector<string>&ans){
    // base case
    if(index==op.length()){
        ans.push_back(op);
        return false;
    }

    // loop to swap
    for(int i=index; i<op.length(); i++){
        // swap
        char temp = op[i];
        op[i] = op[index];
        op[index] = temp;

        // recursive call
        if(findPermutation(index+1,op,ans)){
            return true;
        }

        // swap again
        temp = op[i];
        op[i] = op[index];
        op[index] = temp;
    }
    return false;
}

string getPermutation(int n, int k) {
    string op;
    for(int i=1; i<=n; i++){
        op = op + (char)(i+48);
    }
    vector<string> ans;
    findPermutation(0,op,ans);
    sort(ans.begin(),ans.end());
    // cout<<ans[k-1]<<endl;
    return ans[k-1];
}
int main(){
    getPermutation(3,5);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s, int i){
    if(i>s.length()/2)
    return true;

    if(s[i]==s[s.length()-i-1])
    return checkPalindrome(s,i+1);
    else
    return false;
}

int main(){
    string str = "malayalam";
    cout<<checkPalindrome(str,0)<<endl;
    return 0;
}
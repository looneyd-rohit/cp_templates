#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n)
{
    // if(n==1)
    //     return true;
    // int t = 1,i=0;
    // while(t<n){
    //     i++;
    //     t<<i;
    //     if(t<=n)
    //         return true;
    // }
    // return false;
    int t = n & (n - 1);
    if (t == 0)
        return true;
    return false;
}
int main()
{
    cout << isPowerOfTwo(16) << endl;
    return 0;
}
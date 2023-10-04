#include <bits/stdc++.h>
using namespace std;

int countSet(int n)
{
    int c = 0;
    while (n)
    {
        // if (n & 1)
        //     c++;
        c += (n & 1);
        n = n >> 1;
    }
    return c;
}
int countSetBK(int n)
{
    int c = 0;
    while (n)
    {
        n = (n & (n - 1));
        c++;
    }
    return c;
}
int main()
{
    cout << countSet(13) << endl;
    cout << countSet(101) << endl;
    cout << countSet(32) << endl;
    cout << countSet(2) << endl;
    cout << "- - - - - - - - - - - - - - - - - - - -" << endl;
    cout << countSetBK(13) << endl;
    cout << countSetBK(101) << endl;
    cout << countSetBK(32) << endl;
    cout << countSetBK(2) << endl;
    return 0;
}
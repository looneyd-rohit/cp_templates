#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
    static int c = 0;
    if (n != 0 && c == n)
        return;
    c++;
    cout << c << " ";
    fun(n);
}

int main()
{
    fun(5);
    return 0;
}
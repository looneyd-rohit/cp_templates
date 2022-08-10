#include <bits/stdc++.h>
using namespace std;

int tailFact(int n, int p)
{
    if (n == 0 || n == 1)
        return p;
    p *= n;
    return tailFact(n - 1, p);
}

int main()
{
    cout << tailFact(5, 1) << endl;
    return 0;
}
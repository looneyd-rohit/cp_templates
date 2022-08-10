#include <bits/stdc++.h>
using namespace std;

int hcf(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return hcf(b, a % b);
    }
}
int main()
{
    int a, b;
    cout << "enter two numbers = ";
    cin >> a >> b;
    cout << "HCF = " << hcf(a, b) << endl;
    return 0;
}
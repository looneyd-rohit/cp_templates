#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, temp, alt;
    cin >> n;
    int a[n + 1];
    for (i = 0; i < n + 1; i++)
        a[i] = 1;
    for (i = 2; i < n + 1; i++)
    {
        if (a[i])
        {
            cout << i << " ";
            alt = i;
            temp = (alt)*i;
            while (temp <= n)
            {
                a[temp] = 0;
                alt++;
                temp = (alt + 1) * i;
            }
        }
    }
    cout<<"\n\n";
    for (i = 0; i < n + 1; i++)
        cout<<a[i]<<" ";

    return 0;
}
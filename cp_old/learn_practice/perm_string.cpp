#include <bits/stdc++.h>
using namespace std;

void permString(string s)
{
    int len = s.length();
    int i, j;
    int max = pow(2, len);
    for (i = 0; i < max; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (i & (1 << j))
                cout << s[j];
        }
        cout << "\n";
    }
}

int main()
{
    permString("ROH");
    return 0;
}
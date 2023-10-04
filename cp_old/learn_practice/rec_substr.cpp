#include <bits/stdc++.h>
using namespace std;

void recSubstr(string s, int l)
{
    if (l >= pow(2, s.length()))
        return;
    int temp = l;
    ;
    for (int i = 0; l != 0; i++)
    {
        if ((l & (1 << i)) != 0)
        {
            cout << s[i] << " ";
            l = (l & (l - 1));
        }
    }
    cout << endl;
    recSubstr(s, temp + 1);
}

int main()
{
    recSubstr("abc", 0);
    return 0;
}
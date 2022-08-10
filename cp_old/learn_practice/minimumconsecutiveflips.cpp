// The idea of this question is to find the minumum no. of flips required to
// change the binary string (0's and 1's) to a string containing same terms.
// The algorithm to solve the question is based on the fact that the no. of
// different groups of 0's or 1's varies only by 1 or 0, which means that either the
// difference between groups of 0's and 1's is leading or lagging 1 or they are equal.
// Hence, we derive a simple approach to minimize the no. of flips: We start
// flipping from the second group of elements and continue flipping for that group
// for the rest of the string. This will give us a minimized flip result.

#include <bits/stdc++.h>
using namespace std;

void minimumconsecutiveflips(string s)
{
    system("cls");
    char temp = s[0];
    int i, j;
    for (i = 1, j = 1; s[i] != '\0'; i++)
    {
        if (s[i] == temp)
        {
            j++;
        }
        else
        {
            break;
        }
    }
    if (j == s.length())
    {
        cout << "No need of flipping" << endl;
        return;
    }
    cout << "We are going to flip the alternate groups of " << s[j] << "'s" << endl;
    int len = 0;
    for (i = j; s[i] != '\0'; i++)
    {
        if (s[i] == s[j])
        {
            len++;
        }
        if (len == 1)
        {
            cout << "From " << i << " ";
        }
        if (s[i] == s[j] && s[i + 1] != s[j])
        {
            cout << "to " << i << endl;
            len = 0;
        }
    }
}
int main()
{
    string s = "10000000";
    minimumconsecutiveflips(s);
    return 0;
}
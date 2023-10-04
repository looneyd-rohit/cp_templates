/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int max_finder(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    int i, j;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int pd, cd, max_prev = 2, max = 2;
    i = 2;
    pd = a[1] - a[0];
    while (i < n)
    {
        if (pd == a[i] - a[i - 1])
        {
            max_prev++;
        }
        else
        {
            pd = a[i] - a[i - 1];
            max_prev = 2;
        }
        max = max_finder(max_prev, max);
        i++;
    }
    cout << "max length = " << max << endl;
    return 0;
}
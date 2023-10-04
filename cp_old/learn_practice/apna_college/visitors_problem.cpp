#include <iostream>
using namespace std;

int main()
{
    int n, i, j, flag, max, c = 0;
    cout << "Enter the number of numbers = " << endl;
    cin >> n;
    int vis[n];
    cout << "Enter the number of visitors for N-consecutive days" << endl;
    for (i = 0; i < n; i++)
        cin >> vis[i];
    /* Detetming the condition */
    max = vis[0];
    c = 0;
    for (i = 0; i < n; i++)
    {
        if (vis[i] > max)
            max = vis[i];
        if (((vis[i] > vis[i + 1]) || (i == n - 1)) && (max == vis[i]))
            c++;
    }

    cout << "Number of record breaking days = " << c << endl;
    if (c == 0)
    {
        cout << "No matching values found!!!" << endl;
    }
    return 0;
}
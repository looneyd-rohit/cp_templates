/*
Given N ranges, we need to find the element appearing max times combined in all
the ranges.
*/

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void maxelementinranges(int (&l)[N], int (&r)[N])
{
    vector<int> v(1000);
    int i, max = 0;
    // cout << v->capacity();
    for (i = 0; i < 1000; i++)
        v.push_back(0);
    for (i = 0; i < N; i++)
    {
        v[l[i]]++;
        v[r[i] + 1]--;
    }
    for (i = 1; i < 1000; i++)
    {
        v[i] = v[i] + v[i - 1];
        if (v[max] < v[i])
        {
            max = i;
        }
        // cout << "v[" << i << "] = " << v[i] << endl;
    }
    cout << "The maximum occuring element is " << max << " and has frequency " << v[max] << endl;
}

int main()
{
    int l[]{1, 2, 3};
    int r[]{3, 5, 7};
    maxelementinranges(l, r);
    return 0;
}
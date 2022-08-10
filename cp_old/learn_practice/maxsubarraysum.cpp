#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void maxsubarraysum(int (&arr)[N])
{
    int sum = 0, maxsum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = (arr[i] > (arr[i] + sum)) ? (arr[i]) : (arr[i] + sum);
        maxsum = (maxsum > sum) ? (maxsum) : (sum);
        // cout << "sum= " << sum << endl;
    }
    cout << "maxsum= " << maxsum << endl;
}

int main()
{
    int arr[]{-5, 1, -2, 3, 1, -2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxsubarraysum(arr);
    return 0;
}
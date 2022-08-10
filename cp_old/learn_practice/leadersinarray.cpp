#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void leadersinarray(int (&arr)[N])
{
    int max = INT_MIN;
    for (int i = N - 1; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            cout << arr[i] << ' ';
        }
    }
    cout << endl;
}
int main()
{
    int arr[]{7, 10, 4, 10, 6, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    leadersinarray(arr);
    return 0;
}
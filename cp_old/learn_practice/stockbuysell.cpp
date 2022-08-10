#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void stockbuysell(int (&arr)[N])
{
    int sum = 0;
    for (int i = 1; i < N; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            sum += arr[i] - arr[i - 1];
        }
    }
    cout << "profit= " << sum << endl;
}

int main()
{
    int arr[]{1, 5, 3, 8, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    stockbuysell(arr);
    return 0;
}
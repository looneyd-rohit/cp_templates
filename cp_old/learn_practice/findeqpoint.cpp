/*
A equilibrium point is a point in an array such that the sum of the elements
before it in the array is equal to the sum of the elements after it in the
array.
*/

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void prefixsum_func(int (&arr)[N])
{
    int i, sum = 0;
    for (i = 0; i < N - 1; i++)
        arr[i + 1] += arr[i];

    for (i = 0; i < N; i++)
    {
        if (i > 0)
        {
            if (arr[i - 1] == arr[N - 1] - arr[i])
                cout << "Point " << i << " with value " << arr[i] - arr[i - 1] << " is an equilibrium point." << endl;
            else
                cout << "Point " << i << " with value " << arr[i] - arr[i - 1] << " is not an equilibrium point." << endl;
        }
        else
        {
            if (arr[N - 1] == 0)
            {
                cout << "Point " << i << " with value " << arr[i] << " is an equilibrium point." << endl;
            }
            else
                cout << "Point " << i << " with value " << arr[i] << " is not an equilibrium point." << endl;
        }
    }
}

int main()
{
    int arr[]{3, 4, 8, -9, 20, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    prefixsum_func(arr);
    return 0;
}
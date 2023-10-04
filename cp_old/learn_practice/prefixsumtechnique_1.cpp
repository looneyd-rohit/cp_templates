/*
We are given an array of numbers, also we are making call to a function such that
it finds the sum of elements between two indices in the array including those
two indices.
Now, we need to do this in O(1) time complexity for each call of the function,
whereas we are allowed to perform any preprocessing we need in the array in 
O(N) time.
*/

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void computesum(int (&arr)[N], int l, int r)
{
    int n_sum = 0;
    if (l > 0)
    {
        n_sum = arr[r] - arr[l - 1];
    }
    else
    {
        n_sum = arr[r];
    }
    cout << "sum between " << l << " and " << r << " = " << n_sum << endl;
}

template <size_t N>
void prefixsum_func(int (&arr)[N])
{
    int i, sum = 0;
    for (i = 0; i < N - 1; i++)
        arr[i + 1] += arr[i];
    computesum(arr, 0, 2);
    computesum(arr, 1, 3);
    computesum(arr, 2, 6);
}

int main()
{
    int arr[]{2, 8, 3, 9, 6, 5, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    prefixsum_func(arr);
    return 0;
}
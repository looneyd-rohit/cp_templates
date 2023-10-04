/*
Given an array of [POSITIVE] integers (unsorted) and given a positive integer k,
we need to find if there exists a subarray within that array so that the sum of
the elements of that subarray equals k.

Algorithm:
We take a variable and go on adding the elements of the array sequentially to
untill we reach a point where the variable value exceeds k. Now we start removing
elements from the begining of the array untill we get the required sum.
*/

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
bool matchsuminsubarray(int (&arr)[N], int val)
{
    int start = 0, end = 0, sum = 0;
    for (; start <= end;)
    {
        if (sum < val && end < N)
        {
            sum += arr[end];
            end++;
            // cout << "sum= " << sum << endl;
        }
        else if (sum > val && start < N)
        {
            sum -= arr[start];
            start++;
            // cout << "sum= " << sum << endl;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[]{4, 6, 34, 2, 1, 12, 67, 99, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter the value= ";
    cin >> k;
    if (matchsuminsubarray(arr, k))
    {
        cout << "a subarray exists whose sum matches the above entered value" << endl;
    }
    else
    {
        cout << "a subarray doesn't exist whose sum matches the above entered value" << endl;
    }
    return 0;
}
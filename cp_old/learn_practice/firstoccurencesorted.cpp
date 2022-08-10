/*
We are required to find the first occurence of an element in a sorted array in
log(n) time complexity.
*/

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
int firstoccurencesorted(int (&arr)[N], int l, int r, int e)
{
    if (l > r)
        return -1;
    int mid = (l + r) / 2;
    if (arr[mid] == e)
    {
        if (mid > 0 && arr[mid - 1] == e)
        {
            return firstoccurencesorted(arr, l, mid - 1, e);
        }
        else
        {
            return mid;
        }
    }
    else if (arr[mid] > e)
    {
        return firstoccurencesorted(arr, l, mid - 1, e);
    }
    else
    {
        return firstoccurencesorted(arr, mid + 1, r, e);
    }
}

int main()
{
    int arr[]{5, 10, 10, 11, 15, 20, 20, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = firstoccurencesorted(arr, 0, size - 1, 20);
    if (index != -1)
    {
        cout << "The element exists at position " << index << " in the array." << endl;
    }
    else
    {
        cout << "The element does not exist in the array." << endl;
    }
    return 0;
}
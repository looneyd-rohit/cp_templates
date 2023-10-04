#include <bits/stdc++.h>
using namespace std;
template <typename T>
void swap(T *x, T *y)
{
    T temp = *x;
    *x = *y;
    *y = temp;
    return;
}

template <size_t N>
void dnfsort(int (&arr)[N])
{
    int low = 0, high = N - 1, mid = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr + low, arr + mid);
            low++;
        }
        if (arr[mid] == 1)
        {
            mid++;
        }
        if (arr[mid] == 2)
        {
            swap(arr + mid, arr + high);
            high--;
        }
    }
}

int main()
{
    // int arr[]{1, 0, 0, 2, 1, 1, 1, 0, 2, 0, 1, 2};
    int arr[] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    dnfsort(arr);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
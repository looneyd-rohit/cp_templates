#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void merge(int (&arr)[N], int left, int right)
{
    int i, temp;
    int gap = ceil((float)(right - left + 1) / (float)2), times = ceil((float)log(right - left + 1) / (float)log(2));
    while (times--)
    {
        if (gap > 0)
            for (i = left; i + gap <= right; i++)
            {
                if (arr[i] > arr[i + gap])
                {
                    temp = arr[i];
                    arr[i] = arr[i + gap];
                    arr[i + gap] = temp;
                }
            }
        gap = ceil((float)gap / (float)2);
    }
}

template <size_t N>
void merge_sort(int (&arr)[N], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

int main()
{
    int arr[]{1, 34, 2, 5, 4, 33, 45, 22, 95, 0, 6, 3, 8, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1);
    // merge(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
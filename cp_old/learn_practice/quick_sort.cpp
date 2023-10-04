#include <bits/stdc++.h>
using namespace std;

template <size_t N>
int p_finder(int (&arr)[N], int left, int right)
{
    int i = left - 1, j;
    int pivot = arr[right];
    for (j = left; j < right; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    i++;
    {
        int temp = arr[i];
        arr[i] = arr[right];
        arr[right] = temp;
    }
    return i;
}

template <size_t N>
void quick_sort(int (&arr)[N], int left, int right)
{
    if (left < right)
    {
        int p = p_finder(arr, left, right);
        quick_sort(arr, left, p - 1);
        quick_sort(arr, p + 1, right);
    }
}

int main()
{
    // int arr[]{1, 34, 2, 5, 4, 33, 45, 22, 95, 0, 6, 3, 8, 10, 30};
    int arr[]{10,16,8,12,15,6,5,3,9,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
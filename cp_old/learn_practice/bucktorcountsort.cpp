#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void bucket_count_sort(int (&arr)[N])
{
    int max = arr[0], i, j;
    for (i = 1; i < N; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int sec_arr[max + 1];
    memset(sec_arr, 0, sizeof(sec_arr));
    for (i = 0; i < N; i++)
        sec_arr[arr[i]]++;

    for (i = 0, j = 0; i < max + 1; i++)
    {
        for (int c = 0; j < N && c < sec_arr[i]; j++, c++)
        {
            arr[j] = i;
        }
    }
}

int main()
{
    int arr[]{1, 34, 2, 5, 4, 33, 45, 22, 95, 0, 6, 3, 8, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    bucket_count_sort(arr);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
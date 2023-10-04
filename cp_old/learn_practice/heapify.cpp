#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int arr[], int index, int size)
{
    // because we take array index from 1
    // if (index == 0)
    //     return;

    int left = index * 2;
    int right = index * 2 + 1;
    int nextIndex = index;
    if (left < size)
    {
        if (arr[left] > arr[index])
            nextIndex = left;
    }
    if (right < size)
    {
        if (arr[right] > arr[nextIndex])
            nextIndex = right;
    }
    if (nextIndex != index)
    {
        swap(arr + nextIndex, arr + index);
        heapify(arr, nextIndex, size);
    }
}
void showArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
    int arr[]{0, 10, 20, 15, 12, 40, 25, 18};
    int size = sizeof(arr) / sizeof(int);
    cout << "old array:" << endl;
    showArray(arr, size);
    // heapify(arr, 1, size);
    // heapify(arr, 1, size);
    cout << "in progress:" << endl;
    for (int i = 1; i < size; i++)
    {
        heapify(arr, size - i, size);
        showArray(arr, size);
    }
    cout << "new array:" << endl;
    showArray(arr, size);

    return 0;
}
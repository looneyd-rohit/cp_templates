#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void sortArr(int arr[], int size)
{
    int left = 0, mid = 0, right = size - 1;
    while (mid <= right)
    {

        if (arr[mid] == 0)
        {
            swap(arr + left, arr + mid);
            left++;
            mid++;
        }

        else if (arr[mid] == 1)
        {
            mid++;
        }
        else if (arr[mid] == 2)
        {
            swap(arr + mid, arr + right);
            right--;
        }
    }
}

int main()
{
    system("cls");
    int arr[] = {0, 2, 2, 1, 0, 1, 1, 0, 2};
    int size = sizeof(arr) / sizeof(int);
    sortArr(arr, size);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void reverse(int (&arr)[N], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
template <size_t N>
void leftshiftarraybyd(int (&arr)[N], int d)
{
    reverse(arr, 0, d - 1);
    reverse(arr, d, N - 1);
    reverse(arr, 0, N - 1);
}

int main()
{
    system("cls");
    int arr[]{1, 2, 4, 5, 2, 1, 5, 3, 9, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter d= ";
    int d;
    cin >> d;
    leftshiftarraybyd(arr, d);
    for (int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int josephus(int *arr, int len, int k, int pos)
{
    // int len = sizeof(arr) / sizeof(int);
    if (len == 1)
    {
        cout << "position index = " << pos << endl;
        return arr[pos];
    }
    for (int i = (pos + (k - 1) % len) % len; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
    pos = (pos + (k - 1) % len) % len;
    len--;
    pos = pos % len;
    return josephus(arr, len, k, pos);
}

int main()
{
    int n, k;
    cout << "Enter n = ";
    cin >> n;
    cout << "Enter k = ";
    cin >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = i;
    int val = josephus(arr, n, k, 0);
    cout << "value = " << val << endl;
    return 0;
}
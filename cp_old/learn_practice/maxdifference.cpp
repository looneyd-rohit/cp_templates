#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void maxdifference(int (&arr)[N])
{
    int diff = arr[1] - arr[0];
    int i, min = arr[0];
    for (i = 1; i < N; i++)
    {
        diff = (diff > arr[i] - min) ? (diff) : (arr[i] - min);
        min = (min > arr[i]) ? (arr[i]) : (min);
    }
    cout << "max difference= " << diff << endl;
}

int main()
{
    int arr[]{1, 34, 2, 5, 4, 33, 45, 22, 95, 0, 6, 3, 8, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxdifference(arr);
    return 0;
}
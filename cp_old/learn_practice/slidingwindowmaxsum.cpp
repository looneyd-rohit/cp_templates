#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void slidingwindowmaxsum(int (&arr)[N], int k)
{
    if (k > N)
    {
        cout << "Window size too large to compute result!!!" << endl;
        return;
    }
    int sum = 0, temp = 0;
    int i;
    for (i = 0; i < k; i++)
        sum += arr[i];
    temp = sum;
    for (i = 0; i < N - k; i++)
    {
        temp = temp + arr[i + k] - arr[i];
        sum = (sum > temp) ? (sum) : temp;
    }
    cout << "Maximum sum= " << sum << endl;
}

int main()
{
    int arr[]{-5, 1, -2, 3, 1, -2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Enter window size= ";
    cin >> k;
    slidingwindowmaxsum(arr, k);
    return 0;
}
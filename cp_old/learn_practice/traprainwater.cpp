#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void traprainwater(int (&arr)[N])
{
    int i = 0, j, sum = 0;
    while (i < N)
    {
        int j = i + 1;
        while (arr[j] < arr[i] && j < N)
            j++;
        if (j == N)
            break;
        else
        {
            int temp = i + 1;
            while (temp < j)
            {
                sum = sum - arr[temp] + arr[i];
                temp++;
            }
        }
        i = j;
    }
    cout << "trapped water= " << sum << endl;
}

int main()
{
    int arr[]{3, 0, 1, 2, 5, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    traprainwater(arr);
    return 0;
}
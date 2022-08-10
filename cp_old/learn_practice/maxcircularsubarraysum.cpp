#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void maxcircularsubarraysum(int (&arr)[N])
{
    int sum1 = 0, maxsum1 = 0;
    int sum2 = 0, maxsum2 = 0;
    int totalsum = 0;
    for (int i = 0; i < N; i++)
    {
        totalsum += arr[i];

        sum1 = (arr[i] > (arr[i] + sum1)) ? (arr[i]) : (arr[i] + sum1);
        maxsum1 = (maxsum1 > sum1) ? (maxsum1) : (sum1);

        sum2 = (arr[i] > (arr[i] + sum2)) ? (arr[i] + sum2) : (arr[i]);
        maxsum2 = (maxsum2 > sum2) ? (sum2) : (maxsum2);
        // cout << "sum1= " << sum1 << endl;
    }
    totalsum = totalsum - (maxsum2);
    int final = (totalsum > maxsum1) ? (totalsum) : (maxsum1);
    cout << "maxcircularsum= " << final;
    cout << endl;
}

int main()
{
    int arr[]{5, -2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxcircularsubarraysum(arr);
    return 0;
}
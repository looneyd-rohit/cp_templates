#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void frequenciesarray(int (&arr)[N])
{
    int m = arr[0], count = 1, i;
    for (i = 1; i < N; i++)
    {
        if (arr[i] == m)
        {
            count++;
        }
        else
        {
            cout << "count of " << arr[i - 1] << " = " << count << endl;
            m = arr[i];
            count = 1;
        }
    }
    cout << "count of " << arr[i - 1] << " = " << count << endl;
}
int main()
{
    int arr[]{10, 10, 10, 20, 30, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    frequenciesarray(arr);
    return 0;
}
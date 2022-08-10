#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void maxconsecutiveones(int (&arr)[N])
{
    int count = 0, temp = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 1)
        {
            temp++;
            count = (temp > count) ? (temp) : (count);
        }
        else
        {
            temp = 0;
        }
    }
    cout << "maxconsecutiveones= " << count << endl;
}

int main()
{
    int arr[]{0, 1, 1, 0, 1, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxconsecutiveones(arr);
    return 0;
}
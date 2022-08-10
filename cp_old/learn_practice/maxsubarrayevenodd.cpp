#include <bits/stdc++.h>
using namespace std;

template <size_t N>
void maxsubarrayevenodd(int (&arr)[N])
{
    int i, len = 1, final = 1;
    for (i = 0; i < N - 1; i++)
    {
        if ((arr[i] % 2) ^ (arr[i + 1] % 2) == 1)
        {
            len++;
            final = (final > len) ? (final) : (len);
        }
        else
        {
            len = 1;
        }
    }
    cout << "maxlengthsubarray= " << final << endl;
}

int main()
{
    int arr[]{5, 10, 20, 6, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    maxsubarrayevenodd(arr);
    return 0;
}
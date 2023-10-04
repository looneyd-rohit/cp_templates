#include <bits/stdc++.h>
using namespace std;
template <size_t N>
void remove_duplicates(int (&arr)[N])
{
    int i, j;
    for (i = 1, j = 0; i < N; i++)
    {
        if (arr[i] != arr[j])
        {
            j++;
            arr[j] = arr[i];
        }
    }
    for (i = 0; i <= j; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    int arr[] = {1, 1, 2, 3, 4, 4, 4, 4, 5};
    remove_duplicates(arr);
    return 0;
}
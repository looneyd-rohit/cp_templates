#include <iostream>
using namespace std;

int max_finder(int arr[], int pos)
{
    int max = arr[0], i;
    for (i = 0; i <= pos; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    for (i = 0; i < n; i++)
    {
        cout << max_finder(arr, i) << " ";
    }
    return 0;
}
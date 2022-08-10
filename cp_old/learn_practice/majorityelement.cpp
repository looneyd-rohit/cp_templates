// An element is called a majority element in an array if the element occurs atleast
// (N/2 + 1) times in that array.

#include <bits/stdc++.h>
using namespace std;

// Using Moore's Voting Algorithm
template <size_t N>
void majorityelement(int (&arr)[N])
{
    int element, votes = 0;
    for (int i = 0; i < N; i++)
    {
        if (votes == 0)
        {
            element = arr[i];
            votes = 1;
        }
        else
        {
            if (element == arr[i])
                votes++;
            else
                votes--;
        }
    }
    votes = 0;
    for (int i = 0; i < N; i++)
    {
        if (element == arr[i])
            votes++;
    }
    if (votes > N / 2)
    {
        cout << "majorityelement= " << element << endl;
    }
    else
    {
        cout << "no majorityelement" << endl;
    }
}
int main()
{
    int arr[]{8, 8, 6, 6, 6, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    majorityelement(arr);
    return 0;
}
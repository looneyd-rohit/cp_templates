// n queens uses backtracking approach to reach the goal.
// for a n*n grid we go through all the cells and check if there is any
// column occupied or not, if any diagonal attack is possible or not from the
// previous elements. The main point to keep in mind is that every row will
// consist of only one element.

#include <bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int i, int j, int dim)
{

    // checking column
    for (int k = 0; k < i; k++)
    {
        if (arr[k][j] == 1)
            return false;
    }

    // checking left diagonal
    for (int row = i, col = j; row >= 0 && col >= 0; row--, col--)
    {
        if (arr[row][col] == 1)
            return false;
    }

    // checking right diagonal
    for (int row = i, col = j; row >= 0 && col < dim; row--, col++)
    {
        if (arr[row][col] == 1)
            return false;
    }

    return true;
}

bool nQueenSolver(int **arr, int row, int dim)
{

    if (row >= dim)
        return true;

    for (int col = 0; col < dim; col++)
    {
        if (isSafe(arr, row, col, dim))
        {
            arr[row][col] = 1;

            if (nQueenSolver(arr, row + 1, dim))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = (new int *[n]);
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
            arr[i][j] = 0;
    }
    nQueenSolver(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
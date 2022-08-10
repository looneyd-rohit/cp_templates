#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[][9], int i, int j, int key)
{
    if (i >= 9 || j >= 9)
        return false;

    // int key = arr[i][j];

    // checking distinct in a row
    for (int s = 0; s < 9; s++)
    {
        if (s == j)
        {
            // cout << "match j" << endl;
            continue;
        }
        if (arr[i][s] == key)
            return false;
    }

    // checking distinct in a column
    for (int s = 0; s < 9; s++)
    {
        if (s == i)
        {
            // cout << "match i" << endl;
            continue;
        }
        if (arr[s][j] == key)
        {
            return false;
        }
    }

    // checking distinct in a grid
    int grid_i = (i / 3) * 3;
    int grid_j = (j / 3) * 3;
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            if ((grid_i + k) == i && (grid_j + l) == j)
                continue;
            if (arr[grid_i + k][grid_j + l] == key)
            {
                return false;
            }
        }
    }

    return true; // true if the no. satisfies sudoku criteria
}

bool sudokuSolver(int (*arr)[9], int i, int j)
{
    // static int count = 0;
    // count++;
    // cout << count << endl;

    // terminating condition
    if (i >= 9 && j >= 9)
    {
        return true;
    }

    // if (j == 9)
    // {
    //     return sudokuSolver(arr, i + 1, 0);
    // }

    if (arr[i][j] != 0)
    {
        return sudokuSolver(arr, i, j + 1);
    }

    for (int s = 1; s <= 9; s++)
    {
        // initialising the array position with a value and checking further
        if (isPossible(arr, i, j, s))
        {
            // int temp = arr[i][j];
            arr[i][j] = s;
            if ((j + 1) >= 9)
            {
                if (sudokuSolver(arr, i + 1, 0))
                {
                    return true;
                }
            }
            else
            {
                if (sudokuSolver(arr, i, j + 1))
                {
                    return true;
                }
            }
            // arr[i][j] = 0;
        }
    }
    return false;
}
void showArray(int arr[9][9])
{
    cout << "OUTPUT array:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int arr[9][9];
    cout << "Enter your array:" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cin >> arr[i][j];
    }
    // showArray(arr);
    sudokuSolver(arr, 0, 0);
    // sudokuSolver(arr, 0, 0);
    showArray(arr);
    return 0;
}
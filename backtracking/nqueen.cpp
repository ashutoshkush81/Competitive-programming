#include <bits/stdc++.h>
using namespace std;
const int a = 12;

void print(int board[][a], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool possible(int board[][a], int n, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }
    for (int i = (row - 1), j = col+1; (i >= 0) and (j < n); i--, j++)
    {
        if (board[i][j])
            return false;
    }

    for (int i = (row - 1), j = (col - 1); (i >= 0) and (j >= 0); i--, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool backtracking(int board[][a], int n, int row)
{
    if (row == n)
    {
        print(board, n);
        return true;
    }

    bool res = false;
    for (int i = 0; i < n; i++)
    {
        if (possible(board, n, row, i))
        {
            board[row][i] = 1;
            res = backtracking(board, n, row + 1) || res;
            board[row][i] = 0;
        }
    }
    return res;
}

void solve(int board[][a], int n)
{
    if (backtracking(board, n, 0) == false)
    {
        cout << "NO SOLUTION POSSIBLE\n";
    }
}

int main()
{
    int n;
    cin >> n;
    int board[n][a];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }
    solve(board, n);
}
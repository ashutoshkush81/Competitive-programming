#include <bits/stdc++.h>
using namespace std;
const int si = 9;
//sudoku solver using the backtracing
void print(int board[][si])
{
    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j < si; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool findlocation(int board[][si], int &row, int &col)
{
    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j < si; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool issafe(int board[][si], int row, int col, int num)
{
    //checking in row
    for (int i = 0; i < si; i++)
    {
        if (board[i][col] == num)
        {
            return false;
        }
    }
    //checking in column
    for (int i = 0; i < si; i++)
    {
        if (board[row][i] == num)
        {
            return false;
        }
    }

    //checking in the corresponding small matrix of size 3*3
    int a = row - row % 3;
    int b = col - col % 3;
    for (int i = a; i < a + 3; i++)
    {
        for (int j = b; j < b + 3; j++)
        {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

void solve(int board[][si])
{
    int row, col;
    if (!findlocation(board, row, col))
    {
        print(board);
        return;
    }

    bool flag = false;
    for (int i = 1; i <= si; i++)
    {
        if (issafe(board, row, col, i))
        {
            flag = true;
            board[row][col] = i;
            solve(board);
            board[row][col] = 0;
        }
    }
    if (!flag)
        return;
}

int main()
{
    //for the empty place put 0.
    int board[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }
    cout<<endl;

    solve(board);
}
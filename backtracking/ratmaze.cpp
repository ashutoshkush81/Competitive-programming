#include <bits/stdc++.h>
using namespace std;
const int a = 15;

void print(int** move, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << move[i][j] << " ";
        }
        // cout<<"\n";
    }
    cout << endl;
}

void allpossiblemove(int board[][a], int** move, int n, int row, int col)
{
    if ((row == (n - 1)) and ((col) == (n - 1)) and (board[row][col]))
    {
        move[row][col] = 1;
        print(move, n);
        move[row][col]=0;
        return ;
    }

    if ((row >= n) || (col >= n) or (row < 0) or (col < 0) or (board[row][col]==0) or (move[row][col]==1))
    {
        return;
    }
    move[row][col] = 1;
    allpossiblemove(board, move, n, row + 1, col);
    allpossiblemove(board, move, n, row, col + 1);
    allpossiblemove(board, move, n, row - 1, col);
    allpossiblemove(board, move, n, row, col - 1);
    move[row][col] = 0;
}

void ratinmaze(int board[][a],int n)
{
    int** move = new int*[n];
    for(int i=0;i<n;i++)
    {
        move[i] = new int[n];
    }

    allpossiblemove(board,move,n,0,0);
}

int main()
{
    int n;
    cin >> n;
    int board[n][a];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    ratinmaze(board,n);
}
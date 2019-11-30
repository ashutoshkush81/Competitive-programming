#include <bits/stdc++.h>
using namespace std;
const int si = 8;
void print(int board[][si])
{
    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j < si; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout<<endl;
}

bool checkm1(int board[][si], int row, int col)
{
    if ((row - 2) >= 0 and (col - 1) >= 0 and board[row - 2][col - 1] == -1)
        return true;
    else
    {
        return false;
    }
}

bool checkm2(int board[][si], int row, int col)
{
    if ((row - 2) >= 0 and (col + 1) < si and board[row - 2][col + 1] == -1)
        return true;
    else
    {
        return false;
    }
}

bool checkm3(int board[][si], int row, int col)
{
    if ((row - 1) >= 0 and (col - 2) >= 0 and board[row - 1][col - 2] == -1)
        return true;
    else
    {
        return false;
    }
}

bool checkm4(int board[][si], int row, int col)
{
    if ((row - 1) >= 0 and (col + 2) < si and board[row - 1][col + 2] == -1)
        return true;
    else
    {
        return false;
    }
}

bool checkm5(int board[][si], int row, int col)
{
    if ((row + 1) < si and (col - 2) >= 0 and board[row + 1][col - 2] == -1)
        return true;
    else
    {
        return false;
    }
}

bool checkm6(int board[][si], int row, int col)
{
    if ((row + 1) < si and (col + 2) < si and board[row + 1][col + 2] == -1)
        return true;
    else
    {
        return false;
    }
}

bool checkm7(int board[][si], int row, int col)
{
    if ((row + 2) < si and (col - 1) >= 0 and board[row + 2][col - 1] == -1)
        return true;
    else
    {
        return false;
    }
}

bool checkmsi(int board[][si], int row, int col)
{
    if ((row + 2) < si and (col + 1) < si and board[row + 2][col + 1] == -1)
        return true;
    else
    {
        return false;
    }
}

void checkallmove(int board[][si],int row,int col,bool *allmove)
{
    if(checkm1(board,row,col))
    allmove[0]=true;
    if(checkm2(board,row,col))
    allmove[1]=true;
    if(checkm3(board,row,col))
    allmove[2]=true;
    if(checkm4(board,row,col))
    allmove[3]=true;
    if(checkm5(board,row,col))
    allmove[4]=true;
    if(checkm6(board,row,col))
    allmove[5]=true;
    if(checkm7(board,row,col))
    allmove[6]=true;
    if(checkmsi(board,row,col))
    allmove[7]=true;


}

void check(int board[][si], int num, int row, int col)
{
    if (num == si*si-1)
    {
        board[row][col] = si*si-1;
        print(board);
        return;
    }

    board[row][col] = num;
    bool allmove[si]={false};
    checkallmove(board,row,col,allmove);
    for(int i=0;i<8;i++)
    {
        if(allmove[i])
        {
            if(i==0)
            {
                check(board,num+1,row-2,col-1);
            }
            if(i==1)
            {
                check(board,num+1,row-2,col+1);
            }
            if(i==2)
            {
                check(board,num+1,row-1,col-2);
            }
            if(i==3)
            {
                check(board,num+1,row-1,col+2);
            }
            if(i==4)
            {
                check(board,num+1,row+1,col-2);
            }
            if(i==5)
            {
                check(board,num+1,row+1,col+2);
            }
            if(i==6)
            {
                check(board,num+1,row+2,col-1);
            }
            if(i==7)
            {
                check(board,num+1,row+2,col+1);
            }

        }
    }
    board[row][col]=-1;

    
}

int main()
{
    int board[si][si];
    for (int i = 0; i < si; i++)
    {
        for (int j = 0; j < si; j++)
        {
            board[i][j] = -1;
        }
    }
    check(board, 0, 0, 0);
}
#include <bits/stdc++.h>
using namespace std;
const int si = 10;


void print(char board[][si])
{
    for(int i=0;i<si;i++)
    {
        for(int j=0;j<si;j++)
        cout<<board[i][j];
        cout<<endl;
    }
    cout<<endl;
}

bool possiblehori(char board[][si],string v,int row,int col)
{
    for(int i=col;i<col+v.size();i++)
    {
        if(i==10)
        return false;
        else if(board[row][i]=='+')
        return false;
        else if(board[row][i]!='-')
        {
            if(board[row][i]!=v[i-col])
            return false;
        }
    }
    return true;
}


bool possiblever(char board[][si],string v,int row,int col)
{
    for(int i=row;i<row+v.size();i++)
    {
        if(i==10)
        return false;
        else if(board[i][col]=='+')
        return false;
        else if(board[i][col]!='-')
        {
            if(board[i][col]!=v[i-row])
            return false;
        }
    }
    return true;
}

void sethori(char board[][si],string str,bool *helper,int row,int col)
{
    for(int i=col;i<str.size();i++)
    {
        if(board[row][i]=='-')
        {
            board[row][i]=str[i-col];
            helper[i-col]=true;
        }
    }
}

void resethori(char board[][si],string str,bool *helper,int row,int col)
{
    for(int i=col;i<str.size();i++)
    {
        if(helper[i-col]==true)
        {
            board[row][i]='-';
        }
    }
}

void setver(char board[][si],string str,bool *helper,int row,int col)
{
    for(int i=row;i<str.size();i++)
    {
        if(board[i][col]=='-')
        {
            board[i][col]=str[i-row];
            helper[i-row]=true;
        }
    }
}

void resetver(char board[][si],string str,bool *helper,int row,int col)
{
    for(int i=row;i<str.size();i++)
    {
        if(helper[i-row]==true)
        {
            board[i][col]='-'; 
        }
    }
}


void solve(char board[][si],vector<string>v,int index)
{
    cout<<index<<endl;
    if(index==v.size())
    {
        // for(int i=0;i<si;i++)
        // {
        //     for(int j=0;j<si;j++)
        //     {
        //         if(board[i][j]=='-')
        //         return;
        //     }
        // }
        print(board);
        return ;
    }
    
    for(int i=0;i<si;i++)
    {
        for(int j=0;j<si;j++)
        {
            if(board[i][j]=='-' || board[i][j]==v[index][0])
            {
                if(possiblehori(board,v[index],i,j))
                {
                    bool helper[v[index].size()]={false};
                    sethori(board,v[index],helper,i,j);
                    solve(board,v,index+1);
                    resethori(board,v[index],helper,i,j);
                }

                if(possiblever(board,v[index],i,j))
                {
                    bool helper[v[index].size()]={false};
                    setver(board,v[index],helper,i,j);
                    solve(board,v,index+1);
                    resetver(board,v[index],helper,i,j);
                }

            }
        }
    }
}
int main()
{
    char board[10][10];
    for (int i = 0; i < 10; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = str[j];
        }
    }

    string str;
    vector<string> v;
    cin >> str;
    int strsize = str.size();
    string next = "";
    for (int i = 0; i < strsize; i++)
    {
        if (str[i] == ';')
        {
            v.push_back(next);
            next = "";
        }
        else if (i == strsize - 1)
        {
            next = next + str[i];
            v.push_back(next);
        }
        else
        {
            next = next + str[i];
        }
    }
    // cout<<v.size()<<endl;
    solve(board,v,0);
    // for(int i=0;i<10;i++)
    // {
    //     for(int j=0;j<10;j++)
    //     {
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
}
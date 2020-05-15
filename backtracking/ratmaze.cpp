// #include <bits/stdc++.h>
// using namespace std;
// const int a = 15;

// void print(int** move, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << move[i][j] << " ";
//         }
//         // cout<<"\n";
//     }
//     cout << endl;
// }

// void allpossiblemove(int board[][a], int** move, int n, int row, int col)
// {
//     if ((row == (n - 1)) and ((col) == (n - 1)) and (board[row][col]))
//     {
//         move[row][col] = 1;
//         print(move, n);
//         move[row][col]=0;
//         return ;
//     }

//     if ((row >= n) || (col >= n) or (row < 0) or (col < 0) or (board[row][col]==0) or (move[row][col]==1))
//     {
//         return;
//     }
//     move[row][col] = 1;
//     allpossiblemove(board, move, n, row + 1, col);
//     allpossiblemove(board, move, n, row, col + 1);
//     allpossiblemove(board, move, n, row - 1, col);
//     allpossiblemove(board, move, n, row, col - 1);
//     move[row][col] = 0;
// }

// void ratinmaze(int board[][a],int n)
// {
//     int** move = new int*[n];
//     for(int i=0;i<n;i++)
//     {
//         move[i] = new int[n];
//     }

//     allpossiblemove(board,move,n,0,0);
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int board[n][a];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             cin >> board[i][j];
//     }

//     ratinmaze(board,n);
// }

#include<bits/stdc++.h>
using namespace std;
const int a = 15;
#define pi pair<int,int>
bool flag = false;

void printsolution(int solution[][a],int n){
    flag = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
    cout << "--------------------------------------------------\n";
    return ;
}

bool issafe(int board[][a], int solution[][a],pi pos, int n , int move[],int i,int j){
    if(abs(move[i])+abs(move[j])!=1){
        return false;
    }
    if(pos.first+move[i]>=n or pos.first+move[i]<0){
        return false;
    }
    if(pos.second+move[j]>=n or pos.second+move[j]<0){
        return false;
    }
    if(board[pos.first + move[i]][pos.second+move[j]]==0){
        return false;
    }
    if(solution[pos.first + move[i]][pos.second + move[j]]==1){
        return false;
    }
    return true;
}

void solve(int board[][a],int solution[][a],pi pos,int n){
    if(pos.first==(n-1) and pos.second==(n-1) && board[pos.first][pos.second]==1){
        solution[pos.first][pos.second] = 1;
        printsolution(solution,n);
    }
    int move[]={-1,0,1};
    solution[pos.first][pos.second]=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(issafe(board,solution,pos,n,move,i,j)){
                solve(board,solution,{pos.first+move[i],pos.second+move[j]},n);
            }
        }
    }
    solution[pos.first][pos.second]=0;
}

void ratinmaze(int board[][a],int n){
    int solution[n][a];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            solution[i][j] = 0;
        }
    } 

    solve(board,solution,{0,0},n);
    if(!flag){
        cout <<"No solution found!"<<endl;
    }
}

int main(){
    int n;
    cin >> n;
    int board[n][a];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
    ratinmaze(board,n);
    return 0;
}
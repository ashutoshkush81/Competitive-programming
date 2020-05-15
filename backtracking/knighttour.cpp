#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
int const si = 8;

void print(int board[][si]){
    cout << "One of the possible move \n";
    for(int i=0;i<si;i++){
        for(int j=0;j<si;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool possible(pi start,int move[],int i,int j,int board[][si]){
    if(abs(move[i]) + abs(move[j])!=3){
        return false;
    }
    if(start.first + move[i]>=8 or start.first + move[i]<0 or start.second + move[j]>=8 or start.second + move[j]<0){
        return false;
    }
    else if(board[start.first + move[i]][start.second + move[j]]!=-1){
        return false;
    }
    else{
        return true;
    }
}

void solve(pi start , int board[][si],int move[],int totalmove){
    if(totalmove==64){
        board[start.first][start.second] = totalmove;
        print(board);
        exit(0);
    }
    board[start.first][start.second]=totalmove;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(possible(start,move,i,j,board)){
                solve({start.first + move[i],start.second + move[j]},board,move,totalmove+1);
            }
        }
    }
    board[start.first][start.second]=-1;

}

int main(){
    int board[si][si];
    for(int i=0;i<si;i++){
        for(int j=0;j<si;j++){
            board[i][j] = -1;
        }
    }
    int move[]={-2,-1,1,2};
    pi start = {0,0};
    solve(start,board,move,1);
}
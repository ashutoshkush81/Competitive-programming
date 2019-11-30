// A and B playing a game in which a certain number of coins are placed on a table. Each Player picks at least a and atmost
//b coins in his turns unless there is less than 'a'  coins left in which case the player has to pick all those left.
//The ideas behind is if n ( no of coins ) multiple of (a+b) then player B win otherwise A wins.
//https://www.hackerearth.com/problem/algorithm/determine-the-winner-june-circuits-2019-f4713f29/
//submitted sucessfully on hackerearth on given link which comes in june circuits 2019 question no 2
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n,k;
        cin>>n>>k;
        if(n%(k+1))
        {
            cout<<"Arpa\n";
        }
        else
        {
            cout<<"Dishant\n";
        } 
    }
    return 0;
}
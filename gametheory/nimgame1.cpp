//https://www.geeksforgeeks.org/game-of-n-stones-where-each-player-can-remove-1-3-or-4/
#include<bits/stdc++.h>
using namespace std;

int mex(set<int>s)
{
    int ans = 0;
    while(s.find(ans)!=s.end())
    ans++;
    return ans;
}

int grundy(int n, int *dp)
{
    if(n==0)
    return 0;
    if(dp[n]!=-1)
    return dp[n];
    set<int>s;
    s.insert(grundy(n-1,dp));
    s.insert(grundy(n-3,dp));
    s.insert(grundy(n-4,dp));
    int ans = mex(s);
    dp[n]=ans;
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dp[1]=1;
    dp[2]=0;
    dp[3]=1;
    dp[4]=2;
    int ans = grundy(n,dp);
    cout<<ans<<endl;
    if(ans!=0)
    cout<<"First player win\n";
    else
    {
        cout<<"Second player win\n";
    }
    
    return 0;
}
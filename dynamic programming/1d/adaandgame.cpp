//https://www.spoj.com/problems/ADAGAME/
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define newmod 10000
#define f(i,a,n) for(lli i = a; i < n; i++)
#define fb(i,a,n) for(lli i=n-1;i>=a;i--)

#define p64 pair<lli,lli>
#define v64 vector<lli>
#define p32 pair<int,int>
#define v32 vector<int>
#define vp64 vector<pair<lli , lli >>
#define vp32 vector<pair<int , int>>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x,y) memset(x,y,sizeof(x))

int solve(int n,int m,int *dp,int count)
{
    if(count>=m)
    {
        return n%newmod;
    }
    if(dp[count]!=-1)
    {
        return dp[count];
    }

    if(count%2==0)
    {
        int maxi = INT_MIN ;
        for(int i=0;i<4;i++)
        {
            n = (n + int(pow(10,i)));
            maxi = max(maxi,solve(n,m,dp,count+1)%newmod);// solve((n+pow(10,i))%newmod);
        }
        return dp[count] = maxi ;
    }
    else
    {
        int maxi = INT_MAX ;
        for(int i=0;i<4;i++)
        {
            n = (n + int(pow(10,i)));
            maxi = min(maxi,solve(n,m,dp,count+1)%newmod);// solve((n+pow(10,i))%newmod);
        }
        return dp[count] = maxi ;
    }
    
    
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
cin>>t;
while(t--){
    string str;
    cin>>str;
    int n = 0;
    for(int i=3;i>=0;i--)
    {
        n+=(str[i]-'0')*pow(10,3-i);
    }

    int m;
    cin>>m;
    int dp[m];
    for(int i=0;i<m;i++)
    {
        dp[i] = -1;
    }

    int ans = solve(n,m,dp,0);
    // cout<<ans<<" ";

    if(ans>n)
    cout<<"Ada\n";
    else
    {
        cout<<"Vinit\n";
    }
    
}
return 0;
}
/*Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible
 with nodes valued from 1 to N.*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
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


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
//cin>>t;
while(t--){
    // IS EQUAL TO 2NCN/(N+1)
    lli n;
    cin>>n;
    lli dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            if(dp[j]!=0 and dp[i-j-1]!=0)
            dp[i]+=(dp[j]*dp[i-j-1])%MOD;
            else if(dp[i-j-1]==0)
            {
                dp[i]+=dp[j];
                
            }
            else
            {
                dp[i]+=dp[i-j-1];
            }
            dp[i]%=MOD;
        }

    }
    // f(i,0,n+1)
    // cout<<dp[i]<<" ";
    cout<<dp[n]<<endl;

    
}
return 0;
}
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
cin>>t;
while(t--){
    int test,n,k;
    cin>>test>>n>>k;
    int dp[n+10][k+10][2];

    //basic test case ;
    memset(dp,0,sizeof(dp));
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;


    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] ;
            if((j-1)>=0)
            dp[i][j][1] +=dp[i-1][j-1][1];
        }
    }
    int ans = dp[n][k][0] + dp[n][k][1] ;
    cout<<test<<" "<<ans<<endl;
    
}
return 0;
}
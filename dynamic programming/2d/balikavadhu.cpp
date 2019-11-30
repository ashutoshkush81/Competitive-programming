//https://www.spoj.com/problems/BVAAN/cstart=30
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

int dp[110][110][110];

int solve(string str,string str1,int n,int m,int k)
{
    if(k==0)
    {
        return 0;
    }
    if((n==0 || m==0) and k>0)
    {
        return INT_MIN;
    }

    if(dp[n][m][k]!=-1)
    {
        return dp[n][m][k];
    }

    if(str[n-1]==str1[m-1])
    {
        return dp[n][m][k]=max(str[n-1] + solve(str,str1,n-1,m-1,k-1) , solve(str,str1,n-1,m-1,k));
    }
    else
    {
        return dp[n][m][k] = max(solve(str,str1,n-1,m,k) , solve(str,str1,n,m-1,k));    
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
    string str1;

    cin>>str>>str1;
    int n,m,k;
    n = str.size();
    m = str1.size();
    cin>>k;

    // mem(dp,-1);
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            for(int l=0;l<=k+1;l++)
            {
                dp[i][j][l] = -1;
            }
        }
    }
    int ans = solve(str,str1,n,m,k);
    if(ans<0)
    cout<<0<<endl;
    else
    {
        cout<<ans<<endl;
    }
    

}
return 0;
}
//https://www.spoj.com/problems/PARTY/cstart=20
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

int dp[1001][1001];
int total = 0;
p32 solve(p32 arr[],int n,int k)
{
    if(n<=0 or k==0)
    {
        p32 a;
        a = mp(k,0);
        return a;
    }

    if(k<0)
    {
        p32 a;
        a = mp(k,INT_MIN);
        return a;
    }

    if(dp[n][k]!=-1)
    {
        p32 a;
        a = mp(k,dp[n][k]);
    }

    if(k>=arr[n].ff)
    {
        dp[n][k] = max(solve(arr,n-1,k-arr[n].ff).ss+arr[n].ss , solve(arr,n-1,k).ss);
        p32 a;
        a = mp(k,dp[n][k]);
    }
    else
    {
        dp[n][k] = solve(arr,n-1,k).ss;
        p32 a ;
        a = mp(k,dp[n][k]);
    }
    // return 
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
//cin>>t;
while(t){

    int n,k;
    cin>>k>>n;
    if(n==0 and k==0)
    break;
    else
    {
        p32 arr[n+1];
        mem(dp,-1);
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[i]=mp(a,b);
        }

        p32 ans = solve(arr,n,k);
        cout<<ans.ff<<" "<<ans.ss<<endl;

    }
    
}
return 0;
}
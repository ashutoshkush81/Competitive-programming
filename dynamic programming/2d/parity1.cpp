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
while(t){
    int k,n;
    cin>>k>>n;
    if(k==0 and n==0)
    break;
    else
    {
        p32 arr[n+1];
        for(int i=1;i<=n;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[i] = mp(a,b);
        }
        int dp[n+1][k+1];
        int maximumweight = 0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(i==0 || j==0)
                dp[i][j] = 0;
                else
                {
                    
                }
            }
        }
    }
    
}
return 0;
}
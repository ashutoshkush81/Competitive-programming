//https://www.geeksforgeeks.org/count-number-increasing-subsequences-size-k/
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

int dp[105][105];


int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
//cin>>t;
while(t--){
    int n;
    cin>>n;
    int arr[n];
    int k;
    cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        dp[i][1]= 1;
        for(int j=i-1;j>0;j--)
        {
            if(arr[j]<=arr[i])
            {
                for(int l = 1;l<=k;l++)
                {
                    dp[i][l]+=dp[j][l-1];
                }
            }
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        ans +=dp[i][k];
    }
    cout<<ans<<endl;


}
return 0;
}

/*
9 4
12 8 11 13 10 15 14 16 20

5 3
2 6 4 5 7
*/
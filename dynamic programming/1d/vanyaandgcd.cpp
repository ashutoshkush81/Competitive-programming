//https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/vanya-and-gcd-array/
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
    lli n;
    cin>>n;
    lli arr[n];
    for(lli i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    lli dp[n][101];
    lli total = 0;
    for(int i=0;i<n;i++)
    {
        for(lli j=0;j<=100;j++)
        dp[i][j]=0;
        // dp[i][arr[i]]=1;
        if(arr[i]==1)
        total++;
    }

    // f(i,0,n)
    // {
    //     f(j,0,101)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    for(lli i=1;i<n;i++)
    {
        for(lli j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i])
            {
                dp[i][__gcd(arr[j],arr[i])]++;
                for(lli k=1;k<=100;k++)
                {
                    dp[i][__gcd(k,arr[i])] += dp[j][k];
                }
                
            }
        }
    }

    // for(int i=0;i<n;i++)
    // {
    //     for(int j=1;j<=3;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }

    // lli total = 0;
    for(lli i=0;i<n;i++)
    {
        total +=dp[i][1];
        total%=MOD;
    }
    cout<<total<<endl;

}
return 0;
}
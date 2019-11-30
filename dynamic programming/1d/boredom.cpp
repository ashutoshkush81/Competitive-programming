//https://codeforces.com/problemset/problem/455/A
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
    lli count[100005];
    for(int i=0;i<100005;i++)
    {
        count[i]=0;
    }
    lli arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        count[arr[i]]++;
    }
    lli dp[100005][2];
    dp[0][0]=0;
    dp[1][0]=count[1];
    dp[1][1]=0;
    for(int i=2;i<100005;i++)
    {
        dp[i][0]=max(dp[i-2][0]+i*count[i],max(dp[i-2][1],dp[i-1][1]+i*count[i]));
        dp[i][1]=max(dp[i-1][0],max(dp[i-1][1],dp[i-2][0]));
    }
    cout<<max(dp[100004][0],dp[100004][1]); 
}
return 0;
}
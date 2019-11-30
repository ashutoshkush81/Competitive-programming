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
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
// #endif
int t = 1;
cin>>t;
while(t--){
    lli n;
    cin>>n;
    lli arr[n];
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    //largest increasing subsequence
    lli dp[n];
    f(i,0,n)
    dp[i]=1;
    // f(i,0,n)
    // cout<<dp[i]<<" ";
    f(i,1,n)
    {
        fb(j,0,i)
        {
            if(arr[i]>arr[j] and dp[i]<dp[j]+1)
            dp[i]=dp[j]+1;
        }
    }
    // f(i,0,n)
    // cout<<dp[i]<<" ";
    lli revdp[n];
    f(i,0,n)
    revdp[i]=1;
    fb(i,0,n-1)
    {
        f(j,i+1,n)
        {
            if(arr[i]>arr[j] and revdp[i]<revdp[j]+1)
            revdp[i]=revdp[j]+1;
        }
    }
    // f(i,0,n)
    // cout<<revdp[i]<<" ";

    lli ans = 0;
    f(i,0,n)
    {
        ans = max(ans,dp[i]+revdp[i]);
    }
    cout<<ans-1<<endl;

}
return 0;
}
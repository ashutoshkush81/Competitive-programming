//https://www.hackerrank.com/challenges/angry-children-2/problem
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
    lli n,k;
    cin>>n>>k;
    lli arr[n];
    f(i,0,n)
    cin>>arr[i];
    sort(arr,arr+n);
    lli cumsum[n+1];
    cumsum[0]=0;
    f(i,1,n+1)
    cumsum[i]=cumsum[i-1]+arr[i-1];
    lli ans = LONG_MAX;
    lli target = 0 ;
    f(i,0,n)
    {
        if(i<(k))
        {
            target += i*arr[i] - cumsum[i];
        }
        else
        {
            ans = min(ans,target);
            target +=(k-1)*arr[i] + (k-1)*arr[i-k] - 2*(cumsum[i]-cumsum[i-k+1]);
        }
        // cout<<target<<" ";
    }
    ans = min(ans,target);
    cout<<ans<<endl;

}
return 0;
}
/*A thief wants to loot houses. He knows the amount of money in each house.
 He cannot loot two consecutive houses. 
 Find the maximum amount of money he can loot*/

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

int rec(int arr[],int dp[],int n,int pos)
{
    if(pos>=n)
    return 0;
    if(dp[pos]!=-1)
    return dp[pos];
    else
    {
        return dp[pos]=max(rec(arr,dp,n,pos+2)+arr[pos],rec(arr,dp,n,pos+1));
        
    }
    
}

int getMaxMoney(int arr[], int n)
{
    int dp[n];
    f(i,0,n)
    dp[i]=-1;
    int ans = rec(arr,dp,n,0);
    return ans;
}

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
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int ans = getMaxMoney( arr,  n);
    cout<<ans<<endl;
}
return 0;
}
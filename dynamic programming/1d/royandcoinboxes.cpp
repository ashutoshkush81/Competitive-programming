//https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/
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
    int n;
    cin>>n;
    int arr[n+2];
    mem(arr,0);
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b+1]--;
    }
    for(int i=1;i<n+2;i++)
    {
        arr[i]+=arr[i-1];
    }
    sort(arr+1,arr+n+1);
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        int pos = lower_bound(arr+1,arr+n+1,a) - arr;
        // cout<<pos<<endl;
        pos = n+1 - pos;
        cout<<pos<<endl;
    }

}
return 0;
}
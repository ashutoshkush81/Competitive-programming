//https://www.geeksforgeeks.org/meet-in-the-middle/
//Given a set of n integers where n <= 40. Each of them is at most 10^12,
// determine the maximum sum subset having sum less than or equal S where S <= 10^18.
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

lli alpha[200005];
lli bete[200005];
lli total ;

void calsum(lli *arr,lli start,lli end ,lli sum, lli *x)
{
    if(start>=end)
    {
        x[total++]=sum;
        return ;
    }
    calsum(arr,start+1,end,sum+arr[start],x);
    calsum(arr,start+1,end,sum,x);
}

lli meetinmiddle(lli n,lli sum,lli *arr)
{
    total = 0;
    calsum(arr,0,n/2,0,alpha);
    total = 0;
    calsum(arr,n/2,n,0,bete);
    lli size_alpha = (1<<n/2);
    lli size_bete = (1<<(n-n/2));
    // f(i,0,size_alpha)
    // cout<<alpha[i]<<" ";
    // cout<<endl;
    // f(i,0,size_bete)
    // cout<<bete[i]<<" ";
    // cout<<endl;
    sort(bete,bete+size_bete);
    lli ans = 0;
    f(i,0,size_alpha)
    {
        if(alpha[i]>sum)
        continue;
        else
        {
            lli rem = sum - alpha[i];
            ans = max(ans,alpha[i]+ *(upper_bound(bete,bete+size_bete,rem)-1));
        }
    }
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
    lli n;
    lli s;
    cin>>n;
    cin>>s;
    lli arr[n];
    for(lli i=0;i<n;i++){
        cin>>arr[i];
    }
    lli ans = meetinmiddle(n,s,arr);
    cout<<ans<<endl;
}
return 0;
}
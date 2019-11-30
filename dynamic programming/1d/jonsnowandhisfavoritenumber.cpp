//https://codeforces.com/problemset/problem/768/C
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
    int n,k,x;
    cin>>n>>k>>x;
    int arr[1024];
    mem(arr,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr[a]++;
    }

    for(int i=0;i<k;i++)
    {
        int newarr[1024];
        for(int i=0;i<1024;i++)
        {
            newarr[i] = 0;
        }
        int temp = 0;
        for(int j=0;j<1024;j++)
        {
            if(temp%2==0) //even no. so we need take the odd no
            {
                int num = j^x;
                newarr[num]+=(arr[j]+1)/2;
                newarr[j]+=(arr[j]-(arr[j]+1)/2);
                temp +=arr[j];
            }
            else
            {
                int num = j^x;
                newarr[num]+=(arr[j])/2;
                newarr[j]+=arr[j]-arr[j]/2;
                temp+=arr[j];
            }
            
        }
        for(int i=0;i<1024;i++)
        {
            arr[i]=newarr[i];
        }
    }

    int mini = 0;
    int maxi = 1023;

    for(int i=0;i<1024;i++)
    {
        if(arr[i]!=0)
        {
            mini = i;
            break;
        }
    }
    for(int i=1023;i>=0;i--)
    {
        if(arr[i]!=0)
        {
            maxi = i;
            break;
        }
    }
    cout<<maxi<<" "<<mini<<endl;

}
return 0;
}
//https://codeforces.com/problemset/problem/777/C
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i, a, n) for (lli i = a; i < n; i++)
#define fb(i, a, n) for (lli i = n - 1; i >= a; i--)

#define p64 pair<lli, lli>
#define v64 vector<lli>
#define p32 pair<int, int>
#define v32 vector<int>
#define vp64 vector<pair<lli, lli>>
#define vp32 vector<pair<int, int>>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x, y) memset(x, y, sizeof(x))
#define N 5001


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        lli arr[n][m];
        f(i,0,n)
        f(j,0,m)
        cin>>arr[i][j];
        lli count[n];
        f(i,0,n) count[i]=i+1;
        // f(i,0,n) cout<<count[i]<<" ";
        // cout<<endl;
        for(int i=0;i<m;i++)
        {
            int temp = 0;
            lli temp1 = 1;
            for(int j=1;j<n;j++)
            {
                if(arr[j][i]>=arr[j-1][i])
                temp1++;
                else
                {
                    count[temp]=max(count[temp],temp1);
                    temp = j;
                    temp1 = j+1;
                } 
                // cout<<count[j]<<" ";
            }
            // cout<<endl;
            count[temp]=max(count[temp],temp1);
        }
        f(i,1,n)
        count[i]=max(count[i-1],count[i]);
        // f(i,0,n)
        // cout<<count[i]<<" ";
        // cout<<endl;
        int k;
        cin>>k;
        while(k--)
        {
            int a,b;
            cin>>a>>b;
            if(a==b)
            {
                cout<<"Yes"<<endl;
                continue;
            }
            if(a==n)
            {
                cout<<"Yes"<<endl;
                continue;
            }
            if(count[a-1]>=b)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
            
        }
    }
    return 0;
}
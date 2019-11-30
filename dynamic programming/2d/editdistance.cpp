//https://practice.geeksforgeeks.org/problems/edit-distance/0
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

int dp[1000+1][1000+1];
int editdistance(string str1,string str2,int n,int m)
{
    int ans = 0;
    if(n==0)
        return dp[n][m]=m;
    if(m==0)
        return dp[n][m]=n;
    if(dp[n][m]!=-1)
        return dp[n][m];
    if(str1[n-1]==str2[m-1])
        return dp[n][m]=editdistance(str1,str2,n-1,m-1);
    
    else
    {
        ans =1+min(editdistance(str1,str2,n-1,m),min(editdistance(str1,str2,n,m-1),editdistance(str1,str2,n-1,m-1)));
    }
    return dp[n][m]=ans;
    
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
cin>>t;
while(t--){
    int n,m;
    cin>>n>>m;
    string str;
    string str1;
    cin>>str>>str1;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        dp[i][j]=-1;
    }
    int ans = editdistance(str,str1,n,m);
    cout<<ans<<endl;

}
return 0;
}
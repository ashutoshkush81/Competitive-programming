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
unordered_map<lli,bool>um;
um[0]=true;
um[1]=true;
vector<lli>fibo;
fibo.pb(0);
fibo.pb(1);
lli temp = 1;
int count = 2;
while(temp<=10e10)
{
    temp = fibo[count-1]+fibo[count-2];
    um[temp]=true;
    count++;
    fibo.pb(temp);
}
int t = 1;
cin>>t;
while(t--){
    lli n;
    cin>>n;
    if(um[n])
    {
        cout<<"IsFibo"<<endl;
    }
    else
    {
        cout<<"IsNotFibo"<<endl;
    }
    
    
}
return 0;
}
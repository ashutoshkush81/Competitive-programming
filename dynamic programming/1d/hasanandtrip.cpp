#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define mod 1000000007
 
#define p(x) cout<<x<<" ";
#define p2(x,y) cout<<x<<" "<<y<<" "
#define p3(x,y,z) cout<<x<<" "<<y<<" "<<z<<" "
#define F(i,a,b) for(ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
 
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
#define pi pair<ll,ll>
#define ppi pair<ll,pi>
#define pb push_back
#define all(v) v.begin(), v.end() 

double dist(ppi a,ppi b){
    return sqrt((a.ss.ss-b.ss.ss)*(a.ss.ss-b.ss.ss)+(a.ss.ff-b.ss.ff)*(a.ss.ff-b.ss.ff));
}

int main()
{

ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
cout<<fixed<<setprecision(6);

#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
  
    ll t=1;
    //cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        ppi p[n+2];
        F(i,0,n-1){
            int a,b,c;
            cin>>a>>b>>c;
            p[i].ff=c;
            p[i].ss.ff=a;
            p[i].ss.ss=b;
        }
        double happiness[n+5];
        F(i,0,n-1)
            happiness[i]=p[i].ff*1.0;
        F(i,1,n-1)
            happiness[i]=p[i].ff+happiness[0]-dist(p[i],p[0]);
        F(i,1,n-1){
            RF(j,i-1,1){
                if(p[i].ff+happiness[j]-dist(p[i],p[j])>happiness[i]){
                    happiness[i]=p[i].ff+happiness[j]-dist(p[i],p[j]);
                }
            }
        }
        cout<<happiness[n-1];
    }
        
}
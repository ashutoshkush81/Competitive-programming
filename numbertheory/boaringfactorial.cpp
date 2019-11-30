#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli moduloexpension(lli a,lli b,lli c)
{
    if(b==0)
    return 1;
    if(b%2==0)
    {
        return ((moduloexpension(a,b/2,c)%c)*(moduloexpension(a,b/2,c)%c))%c;

    }
    else
    {
        return ((((moduloexpension(a,b/2,c)%c)*(moduloexpension(a,b/2,c)%c))%c)*a);
        
    }
    
}
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n,p;
        cin>>n>>p;
        //using wilson theorme
        //we know that  if n>p the ans will be zero.
        if(n>=p)
        {
            cout<<"0"<<endl;
        }
        else
        {
            lli ans = 1;
            for(lli i=n+1;i<p;i++)
            {
                ans*=moduloexpension(i,p-2,p);
                ans%=p;
            }
            ans = p-ans;
            cout<<ans<<endl;
        }
        
    }
    return 0;
}

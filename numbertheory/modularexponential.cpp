#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli power(lli n,lli a,lli b)
{
    if(a==0)
    {
        return 1;
    }
    if(a%2==0)
    {
        lli ans = power(n,a/2,b)%b;
        ans = (ans*ans)%b;
        return ans;
    }
    else
    {
        lli ans = power(n,a/2,b)%b;
        ans = (ans*ans)%b;
        ans = ((n%b)*(ans))%b;
        return ans;
    }
    
}
int main()
{
    lli n,a,b;
    cin>>n>>a>>b;
    lli ans = power(n,a,b);
    cout<<ans<<endl;
}
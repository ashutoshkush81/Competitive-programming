#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli gcd(lli a,lli b)
{
    if(b==0 )
    return a;
    return gcd(b,a%b);
}

int main()
{
    lli a,b;
    cin>>a>>b;
    lli ans = gcd(a,b);
    lli ans1 = __gcd(a,b);
    cout<<ans<<" "<<ans1<<endl;

}
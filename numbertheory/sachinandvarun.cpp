//https://codingninjas.in/app/classroom/me/696/content/12082/offering/101178/problem/1728
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
lli gcd(lli a,lli b)
{
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}
void extended_gcd(lli a,lli b,lli *x,lli *y)
{
    if(b==0)
    {
        *x = 1;
        *y = 0;
        return ;
    }
    lli x1,y1;
    extended_gcd(b,a%b,&x1,&y1);
    *x = y1;
    *y = x1 - (a/b)*y1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli a,b,d;
        cin>>a>>b>>d;
        if(d==0)
        {
            cout<<1<<endl;
            continue;
        }
        
        lli x,y;
        a /=gcd(a,b);
        b /=gcd(a,b);
        extended_gcd(b,a,&x,&y);
        //inverse(b)=x;
        x = (x+a)%a;
        lli y1 = ((d%a)*(x%a))%a;
        y1 = (y1+a)%a;
        if(y1*b>d)
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            lli n = ((d/b)-y1)/a;
            cout<<n+1<<endl;
        }
        
    }
}

#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}

void extended_gcd(int a,int b,int *x,int *y)
{
    if(b==0)
    {
        *x = 1;
        *y = 0;
        return ;
    }

    int x1,y1;
    extended_gcd(b,a%b,&x1,&y1);
    *x = y1;
    *y = x1- (a/b)*y1;
}
int main()
{
    int n,m;
    //finding modulo multiplicative inverse of n modulo m
    //using extended euclid algorithm to find the inverse(n)
    cin>>n>>m;
    if(gcd(n,m)!=1)
    {
        cout<<"Modulo multiplicative inverse don't exit\n";
    }
    int x,y;
    extended_gcd(n,m,&x,&y);
    x = (x+m)%m;
    cout<<x<<endl;


}
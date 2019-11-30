#include<bits/stdc++.h>
using namespace std;
void extended_gcd(int a,int b, int *x,int *y)
{
    if(b==0)
    {
        *x = 1;
        *y = 0;
        return ;
    }
    int x1,y1;
    extended_gcd(b,b%a,&x1,&y1);
    *x = y1;
    *y = x1 -(a/b)*y1;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int x,y;
    extended_gcd(a,b,&x,&y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
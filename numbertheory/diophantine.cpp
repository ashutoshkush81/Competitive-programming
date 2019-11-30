#include<bits/stdc++.h>
using namespace std;
//Given three integers a, b, c representing a linear equation of the form : ax + by = c. 
//Determine if the equation has a solution such that x and y are both integral values.
//solution exits only when gcd(a,b)%c==0
int gcd(int a,int b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
    
}
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(c%gcd(a,b)==0)
    {
        cout<<"Possible\n";
    }
    else
    {
        cout<<"Not possible\n";
    }
    
}
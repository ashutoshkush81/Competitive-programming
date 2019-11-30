#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
lli power(lli a,lli b)
{
    if(b==0)
    return 1;
    if(b%2==0)
    {
        return ((power(a,b/2)%MOD)*(power(a,b/2)%MOD))%MOD;
    }
    else
    {
        return (((power(a,b/2)%MOD)*(power(a,b/2)%MOD)*a%MOD)%MOD);
    }
    
}
void multiply(lli matrix[][2],lli M[][2])
{
    lli a = ((matrix[0][0]*M[0][0])%MOD + (matrix[0][1]*M[1][0])%MOD)%MOD;
    lli b = ((matrix[0][0]*M[0][1])%MOD + (matrix[0][1]*M[1][1])%MOD)%MOD;
    lli c = ((matrix[1][0]*M[0][0])%MOD + (matrix[1][1]*M[1][0])%MOD)%MOD;
    lli d = ((matrix[1][0]*M[0][1])%MOD + (matrix[1][1]*M[1][1])%MOD)%MOD;

    matrix[0][0]=a;
    matrix[0][1]=b;
    matrix[1][0]=c;
    matrix[1][1]=d;
}

void power1(lli matrix[][2],lli m)
{
    if(m==0 || m==1)
    return ;

    power1(matrix,m/2);
    multiply(matrix,matrix);
    lli M[][2]={{1,1},{1,0}};
    if(m%2!=0)
    {
        multiply(matrix,M);
    }

}
lli fib(lli n)
{
    lli matrix[2][2]={{1,1},{1,0}};
    power1(matrix,n-1);
    return matrix[0][0];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli a,b,c;
        cin>>a>>b>>c;
        lli ans1=fib(c+1);
        lli ans2=fib(c);
        cout<<ans1<<" "<<ans2<<endl;
        lli ans3=power(a,ans2);
        lli ans4=power(b,ans1);
        lli ans5=(ans3*ans4)%MOD;
        cout<<ans5<<endl;
        cout<<ans3<<" "<<ans4<<endl;
        
    }
    return 0;
}
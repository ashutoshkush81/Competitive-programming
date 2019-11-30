#include<bits/stdc++.h>
using namespace std;

bool prime[1000005];

void convert(int factor)
{
    for(int i=2*factor;i<1000005;i+=factor)
    {
        prime[i]=false;
    }
}

void primeall()
{
    prime[0]=false;
    prime[0]=false;
    for(int i=2;i<1000005;i++)
    {
        prime[i]=true;
    }

    for(int i=2;i<1000005;i++)
    {
        if(prime[i])
        {
            convert(i);
        }
    }
}
int main()
{
    int count[1000005];
    for(int i=0;i<1000005;i++)
    count[i]=0;
    primeall();
    for(int i=2;i<1000005;i++)
    {
        if(prime[i])
        {
            int total = i;
            while(total<1000005)
            {
                count[total]++;
                total+=i;
            }

        }
    }
    
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        int ans = 0;
        for(int i=a;i<=b;i++)
        {
            if(count[i]==n)
            ans++;
        }
        cout<<ans<<endl;
    }
}
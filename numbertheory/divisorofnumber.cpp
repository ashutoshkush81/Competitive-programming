//calculating total number of divisor 
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli n;
    cin>>n;
    vector<lli>v;//for storing all value of divisor
    for(lli i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i*i!=n)
            {
                v.push_back(i);
                v.push_back(n/i);
            }
            else
            {
                v.push_back(i);
            }
            
        }
    }
    cout<<v.size()<<endl;
    
}
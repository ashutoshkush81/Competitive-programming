#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    lli n;
    cin>>n;
    //need to calculate the prime factor of number
    vector< pair<lli,lli> >v;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            lli total = 0;
            while(n%i==0)
            {
                n=n/i;
                total++;
            }
            v.push_back(make_pair(i,total));
        }
    }
    if(n!=1)
    {
        v.push_back(make_pair(n,1));
    }
    for(int i=0;i<v.size();i++)
    {
        if(i!=0)
        {
            cout<<" * "<<v[i].first<<"^"<<v[i].second;
        }
        else
        {
            cout<<v[i].first<<"^"<<v[i].second;
        }
        
    }
    cout<<endl;
    return 0;

}
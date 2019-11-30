#include<bits/stdc++.h>
using namespace std;
#define lli long long int
bool primeno[100005];
vector<lli>primeall;
void seive()
{
    for(int i=2;i<100005;i++)
    primeno[i]=true;
    primeno[0]=false;
    primeno[1]=false;
    for(int i=2;i<100005;i++)
    {
        if(primeno[i])
        {
            for(int j=2*i;j<100005;j+=i)
            primeno[j]=false;
        }
    }
    for(int i=2;i<100005;i++)
    {
        if(primeno[i])
        primeall.push_back(i);
    }
}
int main()
{
    seive();
    int m = primeall.size();
    // cout<<m<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        lli l,r;
        cin>>l>>r;
        bool arr[r-l+1];
        for(int i=0;i<r-l+1;i++)
        arr[i]=true;
        for(int i=0;i<m;i++)
        {
            // cout<<primeall[i]<<endl;
            if(primeall[i]>r)
            break;
            lli start ;
            start = (l/primeall[i])*primeall[i];
            if(start<l)
            start+=primeall[i];
            for(lli j=start;j<=r;j+=primeall[i])
            arr[j-l]=false;
            if(start == primeall[i])
            arr[start-l]=true;

        }
        for(int i=0;i<r-l+1;i++)
        {
            if(arr[i])
            cout<<i+l<<endl;
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli  l,r;
        cin>>l>>r;
        bool arr[r-l+1];
        memset(arr,true,sizeof(arr));
        for(lli i=l;i<=r;i++)
        {
            lli num = i;
            vector<lli>primefactor;
            if(arr[i-l]==true)
            {
                for(lli j=2;j*j<=num;j++)
                {
                    if(num%j==0)
                    {
                        primefactor.push_back(j);
                        while(num%j==0)
                        {
                            num /=j;
                        }
                    }
                }
            }
            if(num!=1)
            primefactor.push_back(num);
            if(primefactor.size()!=1)
            arr[i-l]=false;
            else if(primefactor[0]!=i)
            arr[i-l]=false;
            for(int j=0;j<primefactor.size();j++)
            {
                for(lli k=2*i;k<=r;k+=primefactor[j])
                {
                    arr[k-l]=false;
                }
            }
        }
        for(int i=0;i<r-l+1;i++)
        {
            if(arr[i])
            cout<<i+l<<endl;
        }

    }
}
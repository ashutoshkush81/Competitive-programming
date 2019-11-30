#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        lli maximum = INT_MIN;
        lli arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            maximum=max(maximum,arr[i]);
        }
        lli count[maximum+1];
        for(int i=0;i<=maximum;i++)
        count[i]=0;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            count[arr[i]]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(count[arr[i]]!=0)
            {
                for(int j=2*arr[i];j<=maximum;j+=arr[i])
                {
                    if(count[j]!=0)
                    {
                        count[j]+=count[arr[i]];
                    }
                }
            }
        }
        lli total = 0;
        for(int i=0;i<n;i++)
        {
            total+=count[arr[i]];
            total%=MOD;
        }
        total%=MOD;
        cout<<total<<endl;
        

    }
}
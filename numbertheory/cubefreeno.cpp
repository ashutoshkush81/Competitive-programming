#include<bits/stdc++.h>
using namespace std;
pair<bool,int>cubefree[1000005];
bool prime[1000005];

void convert(int factor)
{
    for(int i=factor*2;i<=1000004;i=i+factor)
    {
        prime[i]=true;
    }
}

void allprime()
{
    for(int i=0;i<=1000004;i++)
    {
        if(i==0 or i==1)
        {
            prime[i]=false;
        }
        else
        {
            prime[i]=true;
        }  
    }
    for(int i=2;i<=1000004;i++)
    {
        if(prime[i])
        {
            convert(i);
        }
    }
}

int main()
{
    cubefree[0]=make_pair(false,0);
    cubefree[1]=make_pair(true,1);
    // allprime();  
    for(int i=1;i<=1000004;i++)
    {
        cubefree[i].first=true;
    } 

    for(int i=2;i*i*i<=1000004;i++)
    {
        if(cubefree[i].first)
        {
            int total = i*i*i;
            int k = 1;
            while(total*k<=1000004)
            {
                cubefree[total*k].first=false;
                k++;
            }
        }
    } 
    for(int i=1;i<=1000004;i++)
    {
        cubefree[i].second = cubefree[i-1].second + cubefree[i].first;
    }
    // for(int i=2;i<30;i++)
    // {
    //     cout<<cubefree[i].first<<" ";
    // }

    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int a;
        cin>>a;
        if(cubefree[a].first)
        {
            cout<<"Case "<<i<<": "<<cubefree[a].second<<endl;
        }
        else
        cout<<"Case "<<i<<": Not Cube Free\n";
    }
    return 0;
}
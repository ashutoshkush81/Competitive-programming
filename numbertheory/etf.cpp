//Euler's totient fuction
#include<bits/stdc++.h>
using namespace std;
#define lli  long long int
pair<bool,lli>etfcount[1000005];
int main()
{
    for(int i=0;i<1000005;i++)
    {
        if(i==0 or i==1)
        {
            etfcount[i].first= false;
            etfcount[i].second=i;
        }
        else
        {
            etfcount[i].first = true;
            etfcount[i].second = i;
        }  
    }


    for(int i=2;i<1000005;i++)
    {
        if(etfcount[i].first)
        {
            for(int j=i;j<1000005;j+=i){
                etfcount[j].first = false;
                etfcount[j].second /=i;
                etfcount[j].second *=(i-1);
            }
            
        }
    }
    for(int i=1;i<10;i++)
    cout<<etfcount[i].second<<" ";
    cout<<endl;

}
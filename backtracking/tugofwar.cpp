#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    int totalsum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        totalsum+=arr[i];
    }
    int size1 = n/2;
    int another[n/2];
    int another1[n-n/2];
    int min_diff = INT_MAX;
    do{
        int anothertotal =0;
        for(int i=0;i<n/2;i++)
        {
            anothertotal+=arr[i];
        }
        int anothertotal1 = totalsum - anothertotal;
        if(abs(anothertotal1-anothertotal)<min_diff)
        {
            min_diff = abs(anothertotal1-anothertotal);
            for(int i=0;i<n/2;i++)
            {
                another[i]= arr[i];
            }
            for(int i=n/2;i<n;i++)
            {
                another1[i-n/2]=arr[i];
            }
        }
    }while(next_permutation(arr,arr+n));

    cout<<min_diff<<endl;
    for(int i=0;i<n/2;i++)
    {
        cout<<another[i]<<" ";
    }
    cout<<endl;
    
    for(int i=0;i<n-n/2;i++)
    {
        cout<<another1[i]<<" ";
    }
    cout<<endl;

    
}
//https://www.geeksforgeeks.org/game-replacing-array-elements/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        s.insert(a);
    }
    int m = s.size();
    if(m%2==0)
    {
        cout<<"first player win\n";
    }
    else
    {
        cout<<"Second player win\n";
    }

    return 0;
    
}
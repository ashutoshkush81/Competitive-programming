//https://www.geeksforgeeks.org/game-theory-choice-area/
#include<bits/stdc++.h>
using namespace std;
int movement(int a,int b,pair<int,int>*area,int pos)
{
    if(a<0 or b<0)
    return -1;
    int ans = 1+max(movement(a+area[pos].first,b+area[pos].second,area,(pos+1)%3),movement(a+area[pos].first,b+area[pos].second,area,(pos+2)%3));
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b; //power of 'a' and 'b' resp.
    pair<int,int>area[3];
    for(int i=0;i<3;i++)
    {
        int c,d;
        cin>>c>>d;
        area[i]=make_pair(c,d);
    }

    int total = movement(a,b,area,0);
    cout<<total<<endl;
}
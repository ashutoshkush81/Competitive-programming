//https://classroom.codingninjas.in/app/classroom/me/696/content/10443/offering/81306/problem/1878
//Range Minimum Query
//Given an array A of size N, there are two types of queries on this array.
//1) q l r: In this query you need to print the minimum in the sub-array A[l:r].
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define fb(i,a,n) for(lli i=n-1;i>=a;i--)

#define p64 pair<lli,lli>
#define v64 vector<lli>
#define p32 pair<int,int>
#define v32 vector<int>
#define vp64 vector<pair<lli , lli >>
#define vp32 vector<pair<int , int>>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x,y) memset(x,y,sizeof(x))

lli arr[1000005];
lli tree[4000040];

void Treebuild(lli Treenode,lli st,lli ed)
{
    if(st==ed)
    {
        tree[Treenode] = arr[st];
        return ;
    }

    lli mid = st + (ed-st)/2;
    Treebuild(Treenode*2+1 , st, mid);
    Treebuild(Treenode*2+2,mid+1,ed);
    tree[Treenode] = min(tree[Treenode*2+1] , tree[Treenode*2+2]);
}

void update(lli Treenode,lli st,lli ed,lli value,lli idx)
{
    lli mid = st + (ed-st)/2;
    if(st==ed)
    {
        arr[st] = value;
        tree[Treenode] = value;
        return ;
    }

    if(idx>mid)
    {
        update(Treenode*2+2,mid+1,ed,value,idx);
    }
    else
    {
        update(Treenode*2+1,st,mid,value,idx);
    }
    tree[Treenode] = min(tree[Treenode*2+1] , tree[Treenode*2+2]);
    
}

lli query(lli Treenode,lli st,lli ed,lli lf,lli rt)
{
    //completely outside
    if(st>rt or ed<lf)
    return INT_MAX;
    //completely inside
    if(st>=lf and ed<=rt)
    {
        return tree[Treenode];
    }

    lli mid = st + (ed-st)/2;
    lli ans1 = query(Treenode*2 + 1, st,mid,lf,rt);
    lli ans2 = query(Treenode*2 + 2, mid+ 1 , ed, lf, rt);
    return min(ans1,ans2);
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
//cin>>t;
while(t--){
    lli n,q;
    cin>>n>>q;

    f(i,0,n)
    {
        cin>>arr[i];
    }
    Treebuild(0,0,n-1);

    f(i,0,q)
    {
        char c ;
        cin>>c ;
        if(c=='q')
        {
            lli a,b;
            cin>>a>>b;
            lli ans = query(0,0,n-1,a-1,b-1);
            cout<<ans<<endl;
        }
        else
        {
            lli a,b;
            cin>>a>>b;
            update(0,0,n-1,b,a-1);
        }
        
    }

}
return 0;
}
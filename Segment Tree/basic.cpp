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


//Segmentree Template .......................................
lli tree[400020];
lli arr[100004];
//tree of size would be 4n......

void Treebuild(lli st,lli ed,lli Treenode)
{
    if(st==ed)
    {
        tree[Treenode] = arr[st];
        return ;
    }
    lli mid = st + (ed-st)/2;
    Treebuild(st,mid,Treenode*2+1);
    Treebuild(mid+1,ed,Treenode*2+2);
    tree[Treenode] = tree[Treenode*2+1] + tree[Treenode*2 + 2];
}

void Treeupdate(lli st,lli ed,lli Treenode, lli idx,lli value)
{
    if(st==ed)
    {
        arr[idx] = value ;
        tree[Treenode] = value;
        return ;
    }
    lli mid = st + (ed-st)/2;
    if(idx>mid){
        Treeupdate(mid+1,ed,Treenode*2+2,idx,value);
    }
    else
    {
        Treeupdate(st,mid,Treenode*2+1,idx,value);
    }

    tree[Treenode] = tree[Treenode*2+1] + tree[Treenode*2+2];
}

lli Treequery(lli Treenode,lli st,lli ed,lli lf,lli rt)
{
    //completely outside
    // cout<<st<<" "<<ed<<" "<<lf<<" "<<rt<<endl;
    if(st>rt or ed<lf)
    {
        return 0;
    }
    //completely inside
    
    if(st>=lf and ed<=rt)
    {
        return tree[Treenode];
    }

    //partially inside partially outside

    lli mid = st + (ed-st)/2;
    lli ans1 = Treequery(Treenode*2+1,st,mid,lf,rt);
    lli ans2 = Treequery(Treenode*2+2,mid+1,ed,lf,rt);
    return ans1 + ans2;
    

}

//segmentree ...........................................................................



int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
//cin>>t;
while(t--){
    lli n;
    cin>>n;
    for(int i=0;i<n;i++ )
    {
        cin>>arr[i];
    }
    Treebuild(0,n-1,0);
    Treeupdate(0,n-1,0,2,10);
    for(int i=0;i<(2*n-1);i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    lli q;
    cin>>q;
    while(q--)
    {
        lli a,b;
        cin>>a>>b;
        cout<<Treequery(0,0,n-1,a-1,b-1)<<endl;
    }

    
}
return 0;
}
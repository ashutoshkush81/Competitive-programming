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

set<char> tree[400020];
char arr[100004];
//tree of size would be 4n......

void build(lli st,lli ed,lli Treenode)
{
    if(st==ed)
    {
        tree[Treenode].insert(arr[st]);
        return ;
    }
    lli mid = st + (ed-st)/2;
    build(st,mid,Treenode*2+1);
    build(mid+1,ed,Treenode*2+2);
    for(auto i:tree[Treenode*2+1])
    {
        tree[Treenode].insert(i);
    }
    for(auto i:tree[Treenode*2+2])
    {
        tree[Treenode].insert(i);
    }
   
}

void update(lli tn,lli st,lli ed,lli idx,char c)
{
    if(st==ed)
    {
        arr[idx] = c ;
        tree[tn].erase();
        tree[tn].insert(c);
        return ;
    }
    lli mid = st + (ed-st)/2;
    if(idx>mid){
        update(tn*2+2,mid+1,ed,idx,c);
    }
    else
    {
        update(tn*2+1,st,mid,idx,c);
    }
    for(auto i:tree[tn*2+1])
    {
        tree[tn].insert(i);
    }
    for(auto i:tree[tn*2+2])
    {
        tree[tn].insert(i);
    }
}

set<char> query()

   

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
//cin>>t;
while(t--){
    string str;
    cin>>str;
    lli n = str.size();
    f(i,0,n)
    {
        arr[i] = str[i];
    }

    build(0,0,n-1);
    lli q;
    cin>>q;
    while(q--)
    {
        lli a;
        cin>>a;
        if(a==2)
        {
            lli b,c;
            cin>>b>>c;
            if(b>c)
            swap(b,c);
            set<lli>s = query(0,0,n-1,b-1,c-1);
            cout<<s.size()<<endl;
        }
        else
        {
            lli b;
            cin>>b;
            char c;
            cin>>c;
            update(0,0,n-1,b-1,c);
        }
    }
    
}
return 0;
}
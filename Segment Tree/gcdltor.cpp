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

unordered_set<char> tree[800020];
char arr[200004];
//tree of size would be 4n......

void build(lli st,lli ed,lli tn)
{
    if(st==ed)
    {
        tree[tn].insert(arr[st]);
        // cout<<arr[st]<<endl;
        return ;
    }
    lli mid = (st+ed)/2;
    build(st,mid,tn*2+1);
    build(mid+1,ed,tn*2+2);
    for(auto& j:tree[tn*2+1])
    {
        tree[tn].insert(j);
    }
    for(auto& j:tree[tn*2+2])
    {
        tree[tn].insert(j);
    }
   
}

void update(lli tn,lli st,lli ed,lli idx,char c)
{
    if(st==ed)
    {
        arr[idx] = c ;
        tree[tn].clear();
        tree[tn].insert(c);
        return ;
    }
    lli mid = (st+ed)/2;
    if(idx>mid){
        update(tn*2+2,mid+1,ed,idx,c);
    }
    else
    {
        update(tn*2+1,st,mid,idx,c);
    }

    
    tree[tn].clear();
    for(auto& k:tree[tn*2+1])
    {
        tree[tn].insert(k);
    }
    for(auto& k:tree[tn*2+2])
    {
        tree[tn].insert(k);
    }
}

unordered_set<char> qr(lli tn,lli st,lli ed,lli lt,lli rt)
{
    if(st > rt or ed < lt)
    {
        unordered_set<char>c;
        return c;
    }
    if(st>=lt and ed <=rt)
    {
        return tree[tn];
    }

    lli mid = (st + ed)/2;
    unordered_set<char>c1 = qr(tn*2+1,st,mid,lt,rt);
    unordered_set<char>c2 = qr(tn*2+2,mid+1,ed,lt ,rt);
    unordered_set<char>c3;
    for(auto&i:c1)
    {
        c3.insert(i);
    }
    for(auto&i:c2)
    {
        c3.insert(i);
    }
    return c3;


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
    string str;
    cin>>str;
    lli n = str.size();
    f(i,0,n)
    {
        arr[i] = str[i];
    }
    

    build(0,n-1,0);

    // for(int i=0;i<10;i++)
    // {
    //     for(auto&j:tree[i])
    //     cout<<j<<" ";
    //     cout<<endl;
    // }
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

            unordered_set<char>m = qr(0,0,n-1,b-1,c-1);
            cout<<m.size()<<endl;
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
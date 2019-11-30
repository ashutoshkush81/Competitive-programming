//https://www.spoj.com/problems/KGSS/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i, a, n) for (lli i = a; i < n; i++)
#define fb(i, a, n) for (lli i = n - 1; i >= a; i--)

#define p64 pair<lli, lli>
#define v64 vector<lli>
#define p32 pair<int, int>
#define v32 vector<int>
#define vp64 vector<pair<lli, lli>>
#define vp32 vector<pair<int, int>>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x, y) memset(x, y, sizeof(x))

struct node
{
    lli a;
    lli b;
};
node tree[400020];
lli arr[100005];

void build(lli tn, lli st, lli ed)
{
    if (st == ed)
    {
        // cout<<st<<" "<<ed<<endl;
        tree[tn].a = arr[st];
        tree[tn].b = 0;
        // cout << tn << " " << arr[st] << " " << tree[tn].a << " " << tree[tn].b << endl;
        return;
    }
    else
    {
        lli mid = (st + ed) / 2;
        build(tn * 2 + 1, st, mid);
        build(tn * 2 + 2, mid + 1, ed);

        lli temp[4];
        temp[0] = tree[tn * 2 + 1].a;
        temp[1] = tree[tn * 2 + 1].b;
        temp[2] = tree[tn * 2 + 2].a;
        temp[3] = tree[tn * 2 + 2].b;
        sort(temp, temp + 4);
        tree[tn].a = temp[3];
        tree[tn].b = temp[2];
    }
}

void update(lli tn, lli st, lli ed, lli idx, lli value)
{
    if(st==ed)
    {
        tree[tn].a = value;
        arr[st] = value;
        return ;
    }
    lli mid = (st+ed)/2;
    if(idx>mid)
    {
        update(tn*2+2,mid+1,ed,idx,value);
    }
    else
    update(tn*2+1,st,mid,idx,value);
    lli temp[4];
    temp[0] = tree[tn * 2 + 1].a;
    temp[1] = tree[tn * 2 + 1].b;
    temp[2] = tree[tn * 2 + 2].a;
    temp[3] = tree[tn * 2 + 2].b;
    sort(temp, temp + 4);
    tree[tn].a = temp[3];
    tree[tn].b = temp[2];


}

node query(lli tn, lli st, lli ed, lli lt, lli rt)
{
    //completely outside
    // cout<<st<<" "<<ed<<" "<<lt<<" "<<rt<<endl;
    if (st > rt or ed < lt)
    {
        node temp ;
        temp.a = 0;
        temp.b = 0;
        return temp;
    }
    //completely inside
    if (st >= lt and ed <= rt)
    {
        return tree[tn];
    }
    //partially

    lli mid = (st + ed) / 2;
    node ans1 = query(tn * 2 + 1, st, mid, lt, rt);
    node ans2 = query(tn * 2 + 2, mid + 1, ed, lt, rt);
    lli temp[4];
    temp[0] = ans1.a;
    temp[1] = ans1.b;
    temp[2] = ans2.a;
    temp[3] = ans2.b;
    node newtemp ;
    sort(temp, temp + 4);
    newtemp.a = temp[3];
    newtemp.b = temp[2];
    return newtemp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    //cin>>t;
    while (t--)
    {
        lli n;
        cin >> n;
        f(i, 0, n) cin >> arr[i];
        build(0, 0, n - 1);
        
        
        lli q;
        cin >> q;
        while (q--)
        {
            char c;
            lli a, b;
            cin >> c >> a >> b;
            if (c == 'Q')
            {
                node temp =query(0, 0, n - 1, a - 1, b - 1);
                cout<<temp.a+temp.b<<endl;
            }
            else
            {
                update(0, 0, n - 1, a - 1, b);
                // for(int i=0;i<13;i++)
                // {
                //     cout<<tree[i].a<<" "<<tree[i].b<<endl;
                // }
                
            }
        }
    }
    return 0;
}
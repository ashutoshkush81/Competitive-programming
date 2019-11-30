//cp algorithm content
// In addition of finding the maximum, we also have to find the number of occurrences of the maximum.
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

pair<lli, lli> tree[400020];
lli arr[100005];

void build(lli tn, lli st, lli ed)
{
    if (st == ed)
    {
        tree[tn].ff = arr[st];
        tree[tn].ss = 1;
        return;
    }

    lli mid = (st + ed) / 2;
    build(tn * 2 + 1, st, mid);
    build(tn * 2 + 2, mid + 1, ed);
    tree[tn].ff = max(tree[tn * 2 + 1].ff, tree[tn * 2 + 2 + 2].ff);
    if (tree[tn * 2 + 1].ff > tree[tn * 2 + 2].ff)
    {
        tree[tn].ss = tree[tn * 2 + 1].ss;
    }
    else if (tree[tn * 2 + 1].ff < tree[tn * 2 + 2].ff)
    {
        tree[tn].ss = tree[tn * 2 + 2].ss;
    }
    else
        tree[tn].ss = tree[tn * 2 + 1].ss + tree[2 * tn + 2].ss;
}

void update(lli tn, lli st, lli ed, lli idx, lli value)
{
    if (st == ed)
    {
        arr[idx] = value;
        tree[tn] = mp(value, 1);
    }
    else
    {
        lli mid = (st + ed) / 2;
        if (idx > mid)
        {
            update(tn * 2 + 2, mid + 1, ed, idx, value);
        }
        else
            update(tn * 2 + 1, st, mid, idx, value);

        tree[tn].ff = max(tree[tn * 2 + 1].ff, tree[tn * 2 + 2 + 2].ff);
        if (tree[tn * 2 + 1].ff > tree[tn * 2 + 2].ff)
        {
            tree[tn].ss = tree[tn * 2 + 1].ss;
        }
        else if (tree[tn * 2 + 1].ff < tree[tn * 2 + 2].ff)
        {
            tree[tn].ss = tree[tn * 2 + 2].ss;
        }
        else
            tree[tn].ss = tree[tn * 2 + 1].ss + tree[2 * tn + 2].ss;
    }
}

pair<lli, lli> query(lli tn, lli st, lli ed, lli lt, lli rt)
{
    //completely outside
    if (st > rt or ed < lt)
    {
        pair<lli, lli> v;
        v = mp(0, 0);
        return v;
    }

    //completely inside
    if (st >= lt and ed <= rt)
    {
        return tree[tn];
    }

    //partially inside partially outside

    lli mid = (st + ed) / 2;
    p64 ans1 = query(tn * 2 + 1, st, mid, lt, rt);
    p64 ans2 = query(tn * 2 + 2, mid + 1, ed, lt, rt);
    tree[tn].ff = max(tree[tn * 2 + 1].ff, tree[tn * 2 + 2 + 2].ff);
    if (tree[tn * 2 + 1].ff > tree[tn * 2 + 2].ff)
    {
        tree[tn].ss = tree[tn * 2 + 1].ss;
    }
    else
    {
        tree[tn].ss = tree[tn * 2 + 2].ss;
    }
    return tree[tn];
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
        lli arr[n];
        f(i, 0, n) cin >> arr[i];
        build(0, 0, n - 1);
        lli q;
        cin >> q;
        while (q--)
        {
            char c;
            cin >> c;
            lli a, b;
            cin >> a >> b;
            if (c == 'q')
            {
                p64 ans = query(0, 0, n - 1, a - 1, b - 1);
                cout << ans.ff << " " << ans.ss << endl;
            }
            else
            {
                update(0, 0, n - 1, a - 1, b);
            }
        }
    }
    return 0;
}
//https : //codeforces.com/contest/888/problem/E
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

lli x[2000005], y[2000005];
lli total;

void cumsum(lli *arr, lli start, lli end, lli k, lli *newarr, lli sum)
{
    if (start >= end)
    {
        newarr[total++] = (sum % k);
        return;
    }
    cumsum(arr, start + 1, end, k, newarr, sum + arr[start]);
    cumsum(arr, start + 1, end, k, newarr, sum);
}

lli midinmiddle(lli n, lli k, lli *arr)
{
    total = 0;
    cumsum(arr, 0, n / 2, k, x, 0);
    total = 0;
    cumsum(arr, n / 2, n, k, y, 0);
    lli size_x = (1 << n / 2);
    lli size_y = (1 << (n - n / 2));
    lli maxi = 0;
    f(i, 0, size_x)
        maxi = max(maxi, x[i]);
    f(i, 0, size_y)
        maxi = max(maxi, y[i]);

    sort(y, y + size_y);
    f(i, 0, size_x)
    {
        lli rem = k - 1 - x[i];
        maxi = max(maxi, x[i] + *((upper_bound(y, y + size_y, rem) - 1)));
    }
    return maxi;
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
        lli k;
        cin >> k;
        lli arr[n];
        for (lli i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        lli ans = midinmiddle(n, k, arr);
        cout << ans << endl;
    }
    return 0;
}
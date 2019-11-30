/*Given an integer N, find and return the count of minimum numbers,
 sum of whose squares is equal to N*/
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
        int n;
        cin >> n;
        int dp[n + 1];
        for (int i = 0; i <= n; i++)
            dp[i] = i;

        for (int i = 4; i <= n; i++)
        {
            for (int j = 0; j <= sqrt(i); j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
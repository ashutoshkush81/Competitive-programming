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

int findMaxSquareWithAllZeros(int **arr, int row, int col)
{

    int n = row;
    int m = col;

    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 or j == 0)
            {
                if (arr[i][j] == 0)
                    dp[i][j] = 1;
            }

            else
            {
                if(arr[i][j]==0)
                {
                    dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans = max(ans,dp[i][j]);

        }
    }
    return ans;
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
        int n, m;
        cin >> n >> m;
        int **arr = new int *[n];
        for (int i = 0; i < m; ++i)
            arr[i] = new int[m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        int ans = findMaxSquareWithAllZeros(arr, n, m);

        cout << ans << endl;
    }
    return 0;
}
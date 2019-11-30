//2.The games starts with a number n and the player tomove divides the number n with 2,3, or 6 and then takes the floor.
//If the interger becomes 0, it is removed . The last player to move wins. Which player wns the game?
#include <bits/stdc++.h>
using namespace std;
int mex(set<int> s)
{
    int ans = 0;
    while (s.find(ans) != s.end())
        ans++;
    return ans;
}
int grundy(int *dp, int n)
{
    if (n == 0)
    {
        dp[0] = 0;
        return 0;
    }
    else if (dp[n] != -1)
        return dp[n];
    set<int> s;
    s.insert(grundy(dp, n / 2));
    s.insert(grundy(dp, n / 3));
    s.insert(grundy(dp, n / 6));
    dp[n] = mex(s);
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int dp[n + 1];
    memset(dp, -1, sizeof(dp));
    int ans = grundy(dp, n);
    cout << ans << endl;
    if (ans != 0)
        cout << "A wins\n";
    else
    {
        cout << "B wins\n";
    }
    return 0;
}
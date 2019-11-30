//1.The game starts with a pile of n stones , and the player to move maytake any positive number of stones upto 3 only
//The last player to move wins. Which player wins the game ? (extended version of nim - game)
#include <bits/stdc++.h>
using namespace std;
int mex(int a, int b, int c)
{
    set<int> s;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    int m = 0;
    int t = 4;
    while (s.find(m) != s.end())
        m++;
    return m;
}
int findgrundy(int *dp, int n)
{
    if (n == 0)
    {
        dp[0] = 0;
        return 0;
    }
    else if (n == 1)
    {
        dp[1] = 1;
        return 1;
    }
    else if (n == 2)
    {
        dp[2] = 2;
    }
    else if (dp[n] != -1)
        return dp[n];

    dp[n - 1] = findgrundy(dp, n - 1);
    dp[n - 2] = findgrundy(dp, n - 2);
    dp[n - 3] = findgrundy(dp, n - 3);
    dp[n] = mex(dp[n - 1], dp[n - 2], dp[n - 3]);
    return dp[n];
}
void grundy(int *dp, int m)
{
    int ans = findgrundy(dp, m - 1);
}
int main()
{
    int n; //number of piles
    cin >> n;
    int arr[n];
    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maximum = max(arr[i], maximum);
    }
    int dp[maximum + 1];
    memset(dp, -1, sizeof(dp));
    grundy(dp, maximum + 1);
    for (int i = 0; i < maximum + 1; i++)
    {
        cout << dp[i] << " ";
    }
    //now calculate the xor of grundy of each number
    int total = 0;
    // for(int i=0;i<n;i++)
    // {
    //     total^=dp[arr[i]+1];
    // }
    if (total != 0)
        cout << "First player wins\n";
    else
    {
        cout << "Second player wins\n";
    }
    return 0;
}
/*
LOCKER - Magic of the locker 
Vertu, the clever businessman, sells the ropes to his customers at the rate of 1 rupee per meter. He can only sell an integer length of a rope to a customer. Also, he has a magic locker which functions this way:
    Suppose the locker has 'x' rupees. Now if 'y' rupees more are put into this locker, it multiplies them and total money in the locker now is 'x*y'.
This morning, Vertu starts his bussiness with 'n' meters of rope. He puts 1 rupee in the locker as to have good luck.
Find the maximum money he can earn today considering that he sold all of his rope at the end of the day.

NOTE: Vertu has to put all rupees into the locker as soon as he gets it, and can get rupees from locker only at the end of the day.

Input  and Output
The first line contains t, the number of test cases. t lines follow, each containing one positive integer n. For each of these integers, print the required answer modulo(109+7).
Constraints

t<10^5

0<n<10^12

Example
Input:
2
4
5
Output:
4
6
*/

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
long long binpow(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli temp = n / 3;
        while ((n - temp * 3) % 2 != 0 and temp > 0)
        {
            temp--;
        }
        // cout << temp << endl;
        lli ans = binpow(3, temp, MOD);
        ans *= binpow(2, (n - temp * 3) / 2, MOD);
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}

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
int const matrixsize = 2;
void multiply(lli matrix[][matrixsize], lli M[][matrixsize])
{
    lli a = (matrix[0][0] * M[0][0]) % MOD + (matrix[0][1] * M[1][0]) % MOD;
    lli b = (matrix[0][0] * M[0][1]) % MOD + (matrix[0][1] * M[1][1]) % MOD;
    lli c = (matrix[1][0] * M[0][0]) % MOD + (matrix[1][1] * M[1][0]) % MOD;
    lli d = (matrix[1][0] * M[0][1]) % MOD + (matrix[1][1] * M[1][1]) % MOD;

    matrix[0][0] = a % MOD;
    matrix[0][1] = b % MOD;
    matrix[1][0] = c % MOD;
    matrix[1][1] = d % MOD;
}

void power(lli matrix[][matrixsize], lli n)
{
    if (n == 0 || n == 1)
        return;
    power(matrix, n / 2);

    multiply(matrix, matrix);
    lli M[2][2] = {{1, 1}, {1, 0}};
    if (n % 2 != 0)
        multiply(matrix, M);
}

lli fib(lli matrix[][matrixsize], lli n)
{
    if (n == 0)
        return 1;

    power(matrix, n);
    return matrix[0][0];
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
        cin>>n;
        if(n==0)
        {
            cout<<0<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<2<<endl;
            continue;
        }
        lli matrix[2][2] = {{1, 1}, {1, 0}};
        lli ans = fib(matrix, n+2 )%MOD;
        cout<<ans<<endl;
    }
    return 0;
}
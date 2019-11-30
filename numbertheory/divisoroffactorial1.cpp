#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
void convert(bool *prime, lli factor, lli n)
{
    for (lli i = 2 * factor; i <= n; i = i + factor)
    {
        prime[i] = false;
    }
}
void totalprime(bool *prime, lli n)
{
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            convert(prime, i, n);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        bool prime[n + 1] = {false};
        for (lli i = 2; i <= n; i++)
            prime[i] = true;
        //calculate prime upto n
        totalprime(prime, n);
        //calculate k for each prime number
        lli count[n + 1] = {0};
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                float a = log10(n);
                // cout<<a<<endl;
                float b = log10(i);
                // cout<<b<<endl;
                int k = a / b;
                for (int j = 1; j <= k; j++)
                {
                    count[i] += n / pow(i, j);
                }
            }
        }
        lli ans = 1;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                ans *= count[i] + 1;
                ans %= MOD;
            }
        }
        cout << ans << endl;
    }
}
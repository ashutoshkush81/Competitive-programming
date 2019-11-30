//calculating total number of divisor of a factorial of given number
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
void primefactor(lli *count, lli n)
{
    //calculate prime factor of n
    for (lli i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            lli total = 0;
            while (n % i == 0)
            {
                n = n / i;
                total++;
            }
            count[i] += total;
        }
    }
    count[n]++;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        //one easy way is calculate the factorial of number and then calculate it's factorial which will take complexity of O(sqrt(n!))
        //other way is calculate the prime factor of all number between 2 to n
        lli count[n + 1] = {0};
        for (lli i = 2; i <= n; i++)
        {
            primefactor(count, i);
        }

        lli ans = 1;
        for (int i = 2; i <= n; i++)
        {
            ans *= count[i] + 1;
            ans %= MOD;
        }
        cout << ans << endl;
    }
}
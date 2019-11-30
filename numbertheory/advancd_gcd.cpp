//range of 1<=a<=10^250
//range of 1<=b<=10^9
//we can't store a in interger
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        lli n;
        cin >> n;
        if(str[0]=='0' and n==0)
        {
            cout<<0<<endl;
            continue;
        }
        int m = str.size();
        int arr[m];
        for (int i = 0; i < m; i++)
        {
            arr[i] = str[i] - '0';
        }
        int sizen = log10(n) + 1;
        int i;
        lli initial = 0;
        for (i = 0; i < min(sizen, m); i++)
        {
            initial *= 10;
            initial += arr[i];
        }
        initial = initial % n;
        for (; i < m; i++)
        {
            initial *= 10;
            initial += arr[i];
            initial %= n;
        }
        // cout<<initial<<endl;
        lli ans = gcd(n, initial);
        cout << ans << endl;
    }
    return 0;
}
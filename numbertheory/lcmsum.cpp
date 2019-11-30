//lcm sum
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

lli power(lli a, lli b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return power(a, b / 2) * power(a, b / 2);
    else
    {
        return power(a, b / 2) * power(a, b / 2) * a;
    }
}

lli binarysearch(lli num, lli a, lli low, lli high)
{
    lli ans = low;
    while (low <= high)
    {
        lli mid = (high + low) / 2;
        if (num % power(a, mid) == 0)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    lli n;
    cin >> n;
    lli m = n;
    lli arr[n];
    for (lli i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    vector<pair<lli, lli>> primefactor;

    for (lli j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            lli total = 0;
            while (n % j == 0)
            {
                n /= j;
                total++;
            }
            primefactor.push_back(make_pair(j, total));
        }
    }
    if (n > 1)
        primefactor.push_back(make_pair(n, 1));

    for (lli i = 0; i < primefactor.size(); i++)
    {
        // cout << i + 1 << endl;
        lli num = primefactor[i].first;
        lli maximum = primefactor[i].second;
        for (lli j = num; j <= m; j += num)
        {
            lli t = binarysearch(j, num, 1, maximum);
            // cout << t << " ";
            arr[j] /= power(num, t);
        }
        // cout << endl;
    }

    lli total1 = 0;
    for(int i=1;i<m;i++)
    {
        total1+=arr[i];
    }
    total1+=1;
    total1*=m;
    cout<<total1<<endl;
    return 0;
}
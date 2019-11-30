//https://codingninjas.in/app/classroom/me/696/content/12082/offering/101185/problem/1734
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
    lli n, k;
    cin >> n >> k;
    lli arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //now calculating the all prime factor of the k
    vector<pair<lli, lli>> primek;

    for (int i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            lli total = 0;
            while (k % i == 0)
            {
                k /= i;
                total++;
            }
            primek.push_back(make_pair(i, total));
        }
    }
    if (k != 1)
    {
        primek.push_back(make_pair(k, 1));
    }

    //now calculating all the prime factor of the of number such that we can store only the prime factor of k only.

    int m = primek.size();
    int dp[n][m];
    int allstore[n + 1][m];
    for(int i=0;i<m;i++)
    allstore[0][i]=0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i][j]=0;
            if (arr[i] % primek[j].first == 0)
            {
                int total = 0;
                while (arr[i] % primek[j].first == 0)
                {
                    arr[i] /= primek[j].first;
                    total++;
                }
                dp[i][j] = total;
            }

            allstore[i+1][j]=dp[i][j]+allstore[i][j];
        }
    }

    //now will store all the divisor in allstore arr;
    
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (i == 0)
    //         {
    //             allstore[i][j] = 0;
    //         }
    //         else
    //         {
    //             allstore[i][j] = dp[i - 1][j] + allstore[i - 1][j];
    //         }
    //     }
    // }

    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<allstore[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    lli total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            bool flag = true;
            for (int k = 0; k < m; k++)
            {
                if ((allstore[j][k] - allstore[i][k] - primek[k].second) < 0)
                {
                    flag = false;
                    break;
                }
            }
            if (flag == true)
            {
                total += 1 + n - j;
                break;
            }
        }
    }
    
    cout<<total<<endl;

    return 0;
}

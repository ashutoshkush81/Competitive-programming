#include <bits/stdc++.h>
using namespace std;
bool mycomp(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    bool arr[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = false;
    for (int i = n; i > 0; i--)
    {
        int m = i;
        if (arr[m] == false)
        {
            //convert into the prime factor of it's number
            vector<int> notoprint;
            notoprint.push_back(m);

            vector<int> prime; //all prime factor of m i,e. i
            for (int j = 2; j * j <= m; j++)
            {
                if (m % j == 0)
                {
                    prime.push_back(j);
                    while (m % j == 0)
                    {
                        m /= j;
                    }
                }
            }
            if (m != 1)
                prime.push_back(m);
            for (auto k : prime)
            {
                m = i;
                while (m - k > 0)
                {
                    m -= k;
                    if (arr[m] == false)
                        notoprint.push_back(m);
                    arr[m] = true;
                }
            }
            sort(notoprint.begin(), notoprint.end(), mycomp);
            for (auto k : notoprint)
            {
                cout << k << " ";
            }
        }
    }
    return 0;
}
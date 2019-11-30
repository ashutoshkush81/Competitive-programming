//https://codingninjas.in/app/classroom/me/696/content/13234/offering/113477/problem/2790
#include <bits/stdc++.h>
using namespace std;

int mex(int a, int b, int c)
{
    bool arr[4] = {false};
    arr[a] = true;
    arr[b] = true;
    arr[c] = true;
    for (int i = 0; i < 4; i++)
        if (arr[i] == false)
        {
            return i;
        }
}

int grundy(int n)
{
    if (n == 0)
        return 0;
    int m = mex(grundy(n / 2), grundy(n / 3), grundy(n / 6));
    return m;
}
int main()
{
    int n;
    cin >> n;
    int ans = grundy(n);
    cout << ans << endl;
}
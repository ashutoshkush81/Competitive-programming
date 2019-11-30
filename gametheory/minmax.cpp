#include <bits/stdc++.h>
using namespace std;
int minmax(int *arr, int depth, int index, bool maxima, int height)
{
    if (depth == height)
        return arr[index];

    int ans;
    if (maxima)
    {
        ans = max(minmax(arr, depth + 1, index * 2, false, height), minmax(arr, depth + 1, index * 2 + 1, false, height));
    }
    else
    {
        ans = min(minmax(arr, depth + 1, index * 2, true, height), minmax(arr, depth + 1, index * 2 + 1, true, height));
    }

    return ans;
}
int main()
{
    int n;
    cin >> n; //n must of pow of 2
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int height = log2(n); //height of the tree
    int ans = minmax(arr, 0, 0, true, height);
    cout << ans << endl;
}
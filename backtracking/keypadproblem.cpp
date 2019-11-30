#include <bits/stdc++.h>
using namespace std;
// int total = 0;

int substring(string *str, int n, string *output)
{
    if (n == 0)
    {
        output[0] = "";
        return 1;
    }

    int p = n % 10;
    n = n / 10;
    int count = substring(str, n, output);
    int size = str[p].size();
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < count; j++)
        {
            output[total + count] = output[j] + str[p][i];
            total++;
        }
    }
    return count * (size + 1);
}

int main()
{
    string str[10];
    str[0] = "";
    str[1] = "";
    str[2] = "abc";
    str[3] = "def";
    str[4] = "ghi";
    str[5] = "jkl";
    str[6] = "mno";
    str[7] = "pqrs";
    str[8] = "tuv";
    str[9] = "wxyz";
    int n;
    cin >> n;
    int s = log10(n);
    s++;
    int temp = n;
    while(temp)
    {
        int q = temp%10;
        if((q==1) or (q==0))
        {
            s--;
        }
        temp/=10;
    }
    string *output = new string[10000];
    int count = substring(str, n, output);
    for (int i = 1; i < count; i++)
    {
        if (output[i].size() == s)
        {
            cout << output[i] << endl;
        }
    }
}
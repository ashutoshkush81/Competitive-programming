#include <bits/stdc++.h>
using namespace std;

int subString(string str, string *output)
{
    if (str.empty())
    {
        output[0] = "";
        return 1;
    }
    string newsubString = str.substr(1);
    int subStringsize = subString(newsubString, output);
    for (int i = 0; i < subStringsize; i++)
    {
        output[i + subStringsize] = str[0] + output[i];
    }
    return 2 * subStringsize;
}

int main()
{
    string str;
    cin >> str;
    string *output = new string[1000];
    int count = subString(str, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << "\n";
    }
}
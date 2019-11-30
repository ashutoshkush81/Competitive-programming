#include <bits/stdc++.h>
using namespace std;
bool check_exit(string str, string dic[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (dic[i].compare(str)==0)
            return true;
    }
    return false;
}

void check(string str, string dic[], int n,int m, string result)
{
    for (int i = 1; i <= m; i++)
    {
        string prefix = str.substr(0, i);
        if(check_exit(prefix,dic,n))
        {
            if(i==m)
            {
                result+=prefix;
                cout<<result<<endl;
            }
            check(str.substr(i,m-i),dic,n,m-i,result+prefix+" ");
        }
    }
}
int main()
{
    string dic[] = {"mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i", "love", "ice", "cream"};
    int n = sizeof(dic) / sizeof(dic[0]);
    // cout<<n<<endl;
    string str;
    cin >> str;
    int m = str.size();
    check(str, dic, n,m, "");
}
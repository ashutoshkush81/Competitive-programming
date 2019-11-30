#include<bits/stdc++.h>
using namespace std;

bool valid(string str)
{
    int m =str.size();
    int cnt = 0;
    for(int i=0;i<m;i++)
    {
        if(str[i]=='(')
        cnt++;
        else if(str[i]==')')
        cnt--;
        if(cnt<0)
        return false;
    }
    return (cnt==0);
}

void removewrong(string str)
{
    if(str.size()==0)
    return ;

    //now applying bfs.
    set<string>visit;//keep checking all visited string 
    queue<string>q; //contain all string for checking for the valid string 
    q.push(str);
    while(!q.empty())
    {
        str = q.front();
        q.pop();
        if(valid(str))
        {
            cout<<str<<endl;
            continue;
        }
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==')' or str[i]=='(')
            {
                string temp = str.substr(0,i) + str.substr(i+1);
                if(visit.find(temp)==visit.end())
                {
                    q.push(temp);
                    visit.insert(temp);

                }
            }
        }
    }
    
}


int main()
{
    string  str;
    cin>>str;
    removewrong(str);
}
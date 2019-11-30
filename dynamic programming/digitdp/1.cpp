#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define fi(i,a,n) for(lli i = a; i < n; i++)
#define fd(i,a,n) for(lli i = a; i > n; i--)
#define fv(i,a) for(auto i:a)
#define pb push_back
#define mp make_pair

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
lli t=1;
cin>>t;
while(t--)
{
    lli s[3][3]={0};
    fi(i,0,3)
    {
        fi(j,0,3)
        cin>>s[i][j];    
    }
    bool isexist=true;
    lli mx=-1;
    fi(i,0,3)
    {
        lli k1,k2;
        if(i==0)
        {
            k1=1;
            k2=2;
        }
        if(i==1)
        {
            k1=0;
            k2=2;
        }
        if(i==2)
        {
            k1=1;
            k2=0;
        }
        bool flag1=false,flag2=false;
        lli c=0;
        fi(j,0,3)
        {
            if(s[i][j]<s[k1][j])
            {
                flag1=true;
                break;
            }
            if(s[i][j]==s[k1][j])
                c++;
        }
        if(c==3)
        {
            isexist=false;
            break;
        }
        c=0;
        fi(j,0,3)
        {
            if(s[i][j]<s[k2][j])
            {
                flag2=true;
                break;
            }
            if(s[i][j]==s[k2][j])
                c++;
        }
        if(c==3)
        {
            isexist=false;
            break;
        }
        if(!flag2 && !flag1)
        {
            mx=i;
            break;
        }
    }
    if(!isexist)
        cout<<"no"<<endl;
    else
    {
        if(mx==0)
        {
            if(s[1][0]>=s[2][0] && s[1][1]>=s[2][1] && s[1][2]>=s[2][2])
            {
                if(s[1][0]==s[2][0] && s[1][1]==s[2][1] && s[1][2]==s[2][2])
                    cout<<"no"<<endl;
                else
                    cout<<"yes"<<endl;
            }
            else if(s[1][0]<=s[2][0] && s[1][1]<=s[2][1] && s[1][2]<=s[2][2])
            {
                if(s[1][0]==s[2][0] && s[1][1]==s[2][1] && s[1][2]==s[2][2])
                    cout<<"no"<<endl;
                else
                    cout<<"yes"<<endl;
            }
            else
                cout<<"no"<<endl;
            // cout<<"h";
        }
        else if(mx==1)
        {
            if(s[0][0]>=s[2][0] && s[0][1]>=s[2][1] && s[0][2]>=s[2][2])
            {
                if(s[0][0]==s[2][0] && s[0][1]==s[2][1] && s[0][2]==s[2][2])
                    cout<<"no"<<endl;
                else
                    cout<<"yes"<<endl;
            }
            else if(s[0][0]<=s[2][0] && s[0][1]<=s[2][1] && s[0][2]<=s[2][2])
            {
                if(s[0][0]==s[2][0] && s[0][1]==s[2][1] && s[0][2]==s[2][2])
                    cout<<"no"<<endl;
                else
                    cout<<"yes"<<endl;
            }
            else
                cout<<"no"<<endl;
        }
        else if(mx==2)
        {
            if(s[1][0]>=s[0][0] && s[1][1]>=s[0][1] && s[1][2]>=s[0][2])
            {
                if(s[1][0]==s[0][0] && s[1][1]==s[0][1] && s[1][2]==s[0][2])
                    cout<<"no"<<endl;
                else
                    cout<<"yes"<<endl;
            }
            else if(s[1][0]<=s[0][0] && s[1][1]<=s[0][1] && s[1][2]<=s[0][2])
            {
                if(s[1][0]==s[0][0] && s[1][1]==s[0][1] && s[1][2]==s[0][2])
                    cout<<"no"<<endl;
                else
                    cout<<"yes"<<endl;
            }
            else
                cout<<"no"<<endl;
        }
        else
            cout<<"no"<<endl;
    }
}
return 0;
}
/*
Many well-known cryptographic operations require modular exponentiation. That is, given integers x,
y and n, compute x,  y mod n. In this question, you are tasked to program an efficient way to execute
this calculation.
Input
The input consists of a line containing the number c of datasets, followed by c datasets, followed by a
line containing the number ‘0’.
Each dataset consists of a single line containing three positive integers, x, y, and n, separated by
blanks. You can assume that 1 < x, n < 2
15 = 32768, and 0 < y < 2
31 = 2147483648.
Output
The output consists of one line for each dataset. The i-th line contains a single positive integer z such
that
z = x
y mod n
for the numbers x, y, z given in the i-th input dataset.
Sample Input
2
2 3 5
2 2147483647 13
0
Sample Output
3
11
*/

#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i,a,n) for(lli i = a; i < n; i++)
#define fb(i,a,n) for(lli i=n-1;i>=a;i--)

#define p64 pair<lli,lli>
#define v64 vector<lli>
#define p32 pair<int,int>
#define v32 vector<int>
#define vp64 vector<pair<lli , lli >>
#define vp32 vector<pair<int , int>>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x,y) memset(x,y,sizeof(x))

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
int t = 1;
cin>>t;
while(t--){
    lli a,b,c;
    cin>>a>>b>>c;
    lli ans = binpow(a,b,c);
    cout<<ans<<endl;
    
}
return 0;
}
/*
FIBOSUM - Fibonacci Sum
no tags 
The fibonacci sequence is defined by the following relation:

F(0) = 0
F(1) = 1
F(N) = F(N - 1) + F(N - 2), N >= 2
Your task is very simple. Given two non-negative integers N and M, you have to calculate the sum (F(N) + F(N + 1) + ... + F(M)) mod 1000000007.

Input
The first line contains an integer T (the number of test cases). Then, T lines follow. Each test case consists of a single line with two non-negative integers N and M.

Output
For each test case you have to output a single line containing the answer for the task.

Example
Input:
3
0 3
3 5
10 19

Output:
4
10
10857
Constraints
T <= 1000
0 <= N <= M <= 10^9
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define MOD 1000000007
#define f(i, a, n) for (lli i = a; i < n; i++)
#define fb(i, a, n) for (lli i = n - 1; i >= a; i--)

#define p64 pair<lli, lli>
#define v64 vector<lli>
#define p32 pair<int, int>
#define v32 vector<int>
#define vp64 vector<pair<lli, lli>>
#define vp32 vector<pair<int, int>>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(x, y) memset(x, y, sizeof(x))

int const matrixsize = 2;
void multiply(lli matrix[][matrixsize],lli M[][matrixsize])
{
    lli a = (matrix[0][0]*M[0][0])%MOD + (matrix[0][1]*M[1][0])%MOD;
    lli b = (matrix[0][0]*M[0][1])%MOD + (matrix[0][1]*M[1][1])%MOD;
    lli c = (matrix[1][0]*M[0][0])%MOD + (matrix[1][1]*M[1][0])%MOD;
    lli d = (matrix[1][0]*M[0][1])%MOD + (matrix[1][1]*M[1][1])%MOD;

    matrix[0][0]=a%MOD;
    matrix[0][1]=b%MOD;
    matrix[1][0]=c%MOD;
    matrix[1][1]=d%MOD;
}

void power(lli matrix[][matrixsize],lli n)
{
    if(n==0 || n==1)
    return ;
    power(matrix,n/2);

    multiply(matrix,matrix);
    lli M[2][2]={{1,1},{1,0}};
    if(n%2!=0)
    multiply(matrix,M);
}

lli fib(lli matrix[][matrixsize],lli n)
{
    if(n==0 )
    return 1;

    power(matrix,n);
    return matrix[0][0];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        lli n, m;
        cin >> n >> m;
        if (n > m)
        {
            swap(n, m);
        }
        n--;
        m--;
        lli matrix[2][2]={{1,1},{1,0}};
        lli ans = fib(matrix,n+1);
        lli matrix1[2][2]={{1,1},{1,0}};
        lli ans1 = fib(matrix1,m+2);
        ans1 = (ans1-ans+MOD)%MOD;
        cout<<ans1<<endl;

        
        
    }
    return 0;
}
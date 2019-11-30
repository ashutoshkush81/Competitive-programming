#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int const matrixsize = 2;


void multiply(int matrix[][matrixsize],int M[][matrixsize])
{
    int a = matrix[0][0]*M[0][0] + matrix[0][1]*M[1][0];
    int b = matrix[0][0]*M[0][1] + matrix[0][1]*M[1][1];
    int c = matrix[1][0]*M[0][0] + matrix[1][1]*M[1][0];
    int d = matrix[1][0]*M[0][1] + matrix[1][1]*M[1][1];

    matrix[0][0]=a;
    matrix[0][1]=b;
    matrix[1][0]=c;
    matrix[1][1]=d;
}

void power(int matrix[][matrixsize],int n)
{
    if(n==0 || n==1)
    return ;
    power(matrix,n/2);

    multiply(matrix,matrix);
    int M[2][2]={{1,1},{1,0}};
    if(n%2!=0)
    multiply(matrix,M);
}

int fib(int matrix[][matrixsize],int n)
{
    if(n==0 )
    return 0;

    power(matrix,n);
    return matrix[0][0];

} 
int main()
{
    int n;
    //calculating the nth fib. number using the matrix exponential
    //so my matrix m will be like the [{1,1},{1,0}]
    // and my matix k will f will be [1,0]
    cin>>n; // nth fib. number
    int matrix[2][2]={{1,1},{1,0}};
    int fun[2][1] = {{1},{0}};
    int ans = fib(matrix,n-1);
    cout<<ans<<endl;
}
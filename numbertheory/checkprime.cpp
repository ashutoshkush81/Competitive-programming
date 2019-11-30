#include <bits/stdc++.h>
using namespace std;
bool primenumber(int n)
{
    int count = 0;
    for (int i = 2; i*i<=n; i++)
    {
        if (n % i == 0)
            count++;
    }
    if (count == 0)
        return true;
    else
        return false;
}
void brute_force(int n)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (primenumber(i))
            count++;
    }
    cout << count << endl;
}

void convert(int factor,bool *arr,int n )
{
    for(int i=2;i*factor<=n;i++)
    {
        arr[i*factor]=false;
    }
}
void sieve(int n)
{
    bool arr[n + 1] ;
    for(int i=0;i<=n;i++)
    arr[i]=true;
    arr[0] = arr[1] = false;
    int total = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            convert(i,arr,n);
        }
    }
    for (int i = 0; i <= n ; i++)
    {
        if (arr[i])
            total++;
    }
    cout << total << endl;
}

int main()
{
    int n;
    cin >> n;
    //count number of prime number between 1 to n with help of brute force
    brute_force(n);
    //count number of prime number between 1 to n using the help of Sieve of Eratosthenes
    sieve(n);
    return 0;
}

//Time complexity of brute force is n*sqrt(n)
//Time complexity of sieve is n*(log(logn))
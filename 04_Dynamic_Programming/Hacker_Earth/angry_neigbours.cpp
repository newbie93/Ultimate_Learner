#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

vector<unsigned long long int>f;

int fib(unsigned long long int n)
{
    // Base cases
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    // If fib(n) is already computed
    if (f[n])
        return f[n];

    int k = (n & 1llu)? (n+1llu)/2llu : n/2llu;

    // Applyting above formula [Note value n&1 is 1
    // if n is odd, else 0.
    f[n] = (n & 1llu)? (fib(k)*fib(k) + fib(k-1llu)*fib(k-1llu))
           : (2llu*fib(k-1llu) + fib(k))*fib(k);

    return f[n];
}

int main()
{
    int t;
    unsigned long long int n,i;
    cin>>t;
    f.push_back(1llu);
    f.push_back(2llu);
    f.push_back(3llu);
    while(t--)
    {
        cin>>n;
        for(i=(unsigned long long int)f.size();i<=n;i++)
            f.push_back(((f[i-1]%MOD)+(f[i-2]%MOD))%MOD);
        cout<<f[n]<<endl;
    }
    return 0;
}


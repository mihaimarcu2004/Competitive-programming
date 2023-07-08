#include <bits/stdc++.h>
#define mod 666013

using namespace std;

ifstream f ("100m.in");
ofstream g ("100m.out");

long long  dp[2][5005];
int n;
long long fact(int x)
{
    long long nr=1;
    for(int i=1; i<=x; ++i)
    {
        nr*=i;
        nr=nr%mod;
    }
    return nr;
}
int main()
{
    f>>n;

    dp[0][1]=1;
    for(int i=2; i<=n; ++i)
    {
        for(int j=1; j<=i; ++j)
        {
            dp[1][j]=(j*dp[0][j]%mod)+dp[0][j-1]%mod;
            dp[1][j]=dp[1][j]%mod;
        }
        for(int j=1; j<=i; ++j)
            dp[0][j]=(dp[1][j]%mod);
    }
    long long rez=0;
    for(int i=1; i<=n; ++i)
    {
        rez=rez+(dp[1][i]*(fact(i)%mod))%mod;
        rez=rez%mod;
    }
    g<<rez%mod;
    return 0;
}

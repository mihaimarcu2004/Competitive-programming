#include <bits/stdc++.h>
#define mod 194767
using namespace std;

ifstream f ("1-sir.in");
ofstream g ("1-sir.out");

int n;
int s;
int dp[2][66000];


void copiere(int sum)
{

}

int main()
{
    f>>n>>s;
    int maxi=n*(n+1)/2;
    dp[0][0]=1;
    if(s>maxi)
    {
        g<<0;
        return 0;
    }
    for(int i=1; i<n; ++i)
    {
        for(int sum=0; sum<=(i*(i+1))/2; ++sum)
        {
            dp[1][sum]=dp[0][sum+i]+dp[0][max(sum-i,-sum+i)];
            dp[1][sum]=dp[1][sum]%mod;

        }
        for(int j=0; j<=(i*(i+1))/2; ++j)
        {
            dp[0][j]=dp[1][j];
            dp[1][j]=0;
        }

    }
    g<<dp[0][max(s,-s)];
    return 0;
}

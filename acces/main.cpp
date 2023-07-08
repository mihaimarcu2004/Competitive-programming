#include <bits/stdc++.h>

using namespace std;
ifstream f ("acces.in");
ofstream g ("acces.out");
int a[1005][1005];
int n,m,q;
int dp[1005][1005];

int main()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
            f>>a[i][j];
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
        {
            if(a[i][j]==1)
                dp[i][j]=min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            if(a[i][j]==0)
            {
                dp[i][j]=1;
                if(a[i][j-1]==0)
                    dp[i][j]+=dp[i][j-1];
                if(a[i-1][j]==0)
                    dp[i][j]+=dp[i-1][j];
                if(a[i][j-1]==0 && a[i-1][j]==0)
                    dp[i][j]-=dp[i-1][j-1];
            }
        }
    }
    f>>q;
    for(int query=1;query<=q;++query)
    {
        int a,b;
        f>>a>>b;
        g<<dp[a][b]<<"\n";

    }
    return 0;
}

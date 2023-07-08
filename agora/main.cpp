#include <bits/stdc++.h>

using namespace std;
ifstream f ("agora.in");
ofstream g ("agora.out");

int n,m,q;
long long a[2005][2005];
long long sumpart[2005][2005];
int main()
{
    f>>m>>n>>q;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {

            if( (i==1 && j!=1) || (i>1 && j==1))
                continue;
            else

                if(__gcd(i,j)==1)
                {
                    int val=sqrt(i*i+j*j);
                    if(val*val==(i*i+j*j))
                        a[i][j]=1;
                }
        }


    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=m; ++j)
            sumpart[i][j]=sumpart[i-1][j]+sumpart[i][j-1]-sumpart[i-1][j-1]+a[i][j];
    }
    for(int query=1; query<=q; ++query)
    {
        int x,y,z,t;
        int xsus,ysus,xjos,yjos;
        f>>xsus>>ysus>>xjos>>yjos;
        x=min(xsus,xjos);
        y=min(ysus, yjos);
        z=max(xsus,xjos);
        t=max(ysus, yjos);
        g<<sumpart[t][z]-sumpart[max(0,y-1)][z]-sumpart[t][max(0,x-1)]+sumpart[max(0,y-1)][max(0,x-1)]<<"\n";
    }
    return 0;
}

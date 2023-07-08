#include <bits/stdc++.h>

using namespace std;

ifstream f ("amedie.in");
ofstream g ("amedie.out");

int n,m;
int q;
int a[805][805];
int fr[100005];

int main()
{
    f>>n>>m>>q;
    int lung=n*m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            f>>a[i][j];
            fr[a[i][j]]++;
        }

    for(int query=1; query<=q; ++query)
    {
        char op;
        f>>op;
        if(op=='L')
        {
            int lin;
            f>>lin;
            for(int j=1; j<=m; ++j)
            {
                fr[a[lin][j]]--;
                if(a[lin][j]>-1)
                {
                     a[lin][j]=-1;
                     --lung;
                }


            }
        }
        if(op=='C')
        {
            int col;
            f>>col;
            for(int i=1; i<=n; ++i)
            {
                fr[a[i][col]]--;
                if(a[i][col]==-1)
                {
                     a[i][col]=-1;
                     --lung;
                }


            }
        }

        if(op=='Q')
        {
            int cont=0;
            for(int i=1;i<=100001;++i)
            {
                if(fr[i]>0)
                {
                    cont+=fr[i];
                }
                if(cont>=(lung+1)/2)
                {
                    g<<i<<"\n";
                    break;
                }
            }
        }
    }

    return 0;
}

#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

ifstream f ("albinuta.in");
ofstream g ("albinuta.out");

int n;
int q;
vector <int > a[1005];
bool dp[55][200005];
int inainteciclu[100005];
int ciclu[100005];
int cmmmc;

int multiplucomun(int x, int y)
{
    long long inm=x*y;
    int div=__gcd(x,y);
    return inm/div;
}
int modul(int x)
{
    while(x>cmmmc)
        x=x-cmmmc;
    return x;

}

int main()
{
    f>>n>>q;
    cmmmc=1;
    for(int i=1; i<=n; ++i)
    {
        int m;
        f>>m;
        cmmmc=multiplucomun(cmmmc, m);
        for(int j=1; j<=m; ++j)
        {
            int x;
            f>>x;
            a[i].push_back(x);
        }
    }

    int timp=1;
    int nod=1;
    while(dp[nod][(timp-1)%a[nod].size()]==0)
    {
        dp[nod][(timp-1)%a[nod].size()]=1;

        int len=a[nod].size();
        nod=a[nod][(timp-1)%len];
        ++timp;
        timp=modul(timp);

    }
    int nrnod=1;
    int t=1;
    int inainte=0;
    while(nrnod!=nod || t!=timp)
    {
        ++inainte;
        inainteciclu[inainte]=nrnod;
        int len=a[nrnod].size();
        nrnod=a[nrnod][(t-1)%len];
        ++t;
        t=modul(t);


    }


    int lungciclu=0;
    int len=a[nrnod].size();
    ++lungciclu;
    ciclu[lungciclu]=nrnod;
    nrnod=a[nrnod][(t-1)%len];

    ++t;
    t=modul(t);

    while(nrnod!=nod || t!=timp)
    {
        ++lungciclu;
        ciclu[lungciclu]=nrnod;
        int len=a[nrnod].size();
        nrnod=a[nrnod][(t-1)%len];
        ++t;
        t=modul(t);

    }

    for(int i=1;i<=q;++i)
    {
        int query;
        f>>query;
        if(query<inainte)
            g<<inainteciclu[query]<<"\n";
        else
        {
            query-=inainte;
            while(query>lungciclu)
                query-=lungciclu;
            g<<ciclu[query]<<"\n";

        }
    }

    return 0;
}

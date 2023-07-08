#include <bits/stdc++.h>
#define mod 769696969

using namespace std;

ifstream f ("aiacupalindroame.in");
ofstream g ("aiacupalindroame.out");



int n,q;
vector <int> v[100005];
struct nod
{
    long long  val;
    long long  grad;
    int primap;
    char elem;
};
int lung;
int euler[100005];
int rmq[20][100005];
nod a[100005];


void DFS(int nod, int tata)
{
    a[nod].grad=a[tata].grad+1;
    a[nod].val=a[tata].val*31+a[nod].elem-'a';
    a[nod].val=a[nod].val%mod;
    euler[++lung]=nod;
    a[nod].primap=lung;
    for(int x=0; x<v[nod].size();++x)
    {
        int fiu=v[nod][x];
        if(fiu!=tata)
        {
            DFS(fiu, nod);
            euler[++lung]=nod;
        }
    }
}


int main()
{
    f>>n>>q;
    for(int i=2; i<=n; ++i)
    {
        int x;
        f>>x;
        v[x].push_back(i);
        v[i].push_back(x);
    }
    a[1].elem='a';
    for(int i=2; i<=n; ++i)
    {
        char x;
        f>>x;
        a[i].elem=x;
    }

    DFS(1, 0);
    for(int i=1; i<=lung; ++i)
        rmq[0][i]=euler[i];


    int put=log2(lung);
    for(int x=1; x<=put; ++x)
    {
        for(int i=1; i<=lung; ++i)
        {
            int prim=rmq[x-1][i];
            int secund=rmq[x-1][i+(1<<(x-1))];
            if(a[prim].grad<=a[secund].grad)
                rmq[x][i]=prim;
            else
                rmq[x][i]=secund;
        }
    }

    for(int query=1;query<=q;++query)
    {
        int x , y;
        f>>x>>y;
        int prim=a[x].primap;
        int secund=a[y].primap;
        if(prim>secund)
            swap(prim , secund);
        if(a[x].grad!=a[y].grad)
        {
            g<<0<<"\n";
            continue;
        }

        int dif=secund-prim;
        int put=log2(dif);

        int interv1=rmq[put][prim];
        int interv2=rmq[put][secund-(1<<put)];
        int lca;
        if(a[interv1].grad<a[interv2].grad)
            lca=interv1;
        else
            lca=interv2;


        int val1=a[x].val-a[lca].val;
        if(val1<0)
            val1+=mod;
        int val2=a[y].val-a[lca].val;
        if(val2<0)
            val2+=mod;


        if(val2==val1)
            g<<1<<"\n";
        else
            g<<0<<"\n";

    }

    return 0;
}

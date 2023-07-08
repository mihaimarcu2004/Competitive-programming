#include <bits/stdc++.h>
#define mod 666013
using namespace std;

ifstream f ("aquapark.in");
ofstream g ("aquapark.out");

int c,n,m;
struct el
{
    int x;
    int y;
    int parte;
};
int cont=0;
el a[100005];
int marcat[100005];
vector <int> v[100005];
void DFS(int nod , int lung)
{
    marcat[nod]=1;
    for(int x=0;x<v[nod].size();++x)
    {
        int fiu=v[nod][x];
        if(marcat[fiu]==0)
        {
            a[fiu].parte=lung%2;
            DFS(fiu , lung+1);

        }
    }
}
int put(long long baza , long long exp)
{
    long long acum=1;
    while(exp>0)
    {
        if(exp%2==1)
        {
            acum*=baza;
            acum=acum%mod;
            --exp;
        }
        else if(exp%2==0)
        {
            baza=baza*baza;
            baza=baza%mod;
            exp=exp/2;
        }
    }
    return acum;
}

int main()
{

    f>>c>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int xx,yy;
        f>>xx>>yy;
        a[i].x=min(xx,yy);
        a[i].y=max(xx,yy);
    }
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j)
            if(a[i].x<a[j].x && a[j].y>a[i].y && a[i].y>a[j].x)
                v[i].push_back(j) , v[j].push_back(i);
    }
   /* for(int i=1;i<=n;++i)
    {
        for(int x=0;x<v[i].size();++x)
            cout<<v[i][x]<<" ";
        cout<<"\n";
    }
    */
    for(int i=1;i<=m;++i)
    {
        if(marcat[i]==0)
        {
            DFS(i , 1);
            ++cont;
        }
    }
    if(c==1)
    {
        for(int i=1;i<=m;++i)
        {
            if(a[i].parte==1)
                g<<a[i].x<<" "<<a[i].y<<" "<<a[i].parte<<"\n";
            else
                g<<a[i].x<<" "<<a[i].y<<" "<<2<<"\n";
        }
    }
    else
    {
        g<<put(2,cont);
    }


    return 0;
}

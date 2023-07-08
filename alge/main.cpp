#include <bits/stdc++.h>

using namespace std;
ifstream f ("alge.in");
ofstream g ("alge.out");
int n,m;
int a[40][40][40];
struct drum
{
    int i;
    int j;
    int k;
};
drum v[500005];
queue <drum> Q;

int di[8]= {0,0,1,-1,0,0};
int dj[8]= {0,0,0,0,1,-1};
int dk[8]= {1,-1,0,0,0,0};
int ok(int i, int  j, int k)
{
    if(i>n || i<1 || j>n || j<1 || k<1 ||k>n)
        return 0;
    if(a[i][j][k]!=0)
        return 0;
    return 1;
}
int Lee()
{
    Q.push({1,1,1});
    a[1][1][1]=1;
    while(!Q.empty())
    {
        int i=Q.front().i;
        int j=Q.front().j;
        int k=Q.front().k;
        for(int x=0; x<8; ++x)
        {
            if(ok(i+di[x], j+dj[x], k+dk[x]))
            {
                Q.push({i+di[x], j+dj[x], k+dk[x]});
                a[i+di[x]][j+dj[x]][k+dk[x]]=a[i][j][k]+1;
            }
        }
        Q.pop();

    }
    return a[n][n][n];
}
void Inapoi()
{
    Q.push({n,n,n});
    int it=0;
    while(!Q.empty())
    {
        int i=Q.front().i;
        int j=Q.front().j;
        int k=Q.front().k;
        v[++it].i=i;
        v[it].j=j;
        v[it].k=k;
        for(int x=0; x<8; ++x)
        {
            if(a[i+di[x]][j+dj[x]][k+dk[x]]==a[i][j][k]-1 && a[i+di[x]][j+dj[x]][k+dk[x]]!=0 && i<=n && i>=1 && j<=n && j>=1 && k>=1 && k<=n)
            {
                Q.push({i+di[x], j+dj[x], k+dk[x]});
                break;

            }
        }
        Q.pop();

    }
}
int main()
{
    f>>n>>m;
    for(int i=1; i<=m; ++i)
    {
        int x,y,z;
        f>>x>>y>>z;
        a[x][y][z]=-1;
    }
    int cont=Lee();
    Inapoi();
    g<<cont<<"\n";
    for(int i=cont; i>0; --i)
        g<<v[i].i<<" "<<v[i].j<<" "<<v[i].k<<"\n";
    return 0;
}

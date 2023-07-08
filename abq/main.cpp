#include <bits/stdc++.h>

using namespace std;
ifstream f ("abq.in");
ofstream g ("abq.out");

int n,m,q;
char c;
int mt[1001][1001];
int s[1001][1001];
queue <pair<int,int>> Q;
int di[4]= {0,0,-1,1};
int dj[4]= {1,-1,0,0};

int ok(int a,int b)
{
    if(a<1 || b<1 || a>n || b>m)
        return 0;
    if(s[a][b]!=0)
        return 0;
    return 1;

}
int LEE (int x1,int y1,int x2, int y2)
{
    Q.push(make_pair(x1,y1));
    s[x1][y1]=1;
    while(!Q.empty())
    {
        int i=Q.front().first;
        int j=Q.front().second;
        for(int x=0; x<4; ++x)
        {
            if(ok(i+di[x],j+dj[x]))
            {
                Q.push(make_pair(i+di[x],j+dj[x]));
                s[i+di[x]][j+dj[x]]=s[i][j]+1;;

            }

        }
        Q.pop();
    }
        if(s[x2][y2]==0)
            return -1;
        return s[x2][y2];

}
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=m; ++j)
        {
            f>>c;
            if(c=='b')
                mt[i][j]=-1;
        }

    f>>q;
    for(int query=1; query<=q; ++query)
    {
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
                s[i][j]=mt[i][j];
        int x1,y1,x2,y2;
        f>>x1>>y1>>x2>>y2;


        if(mt[x1][y1]==-1 || mt[x2][y2]==-1)
            g<<-1<<"\n";

        else
            g<<LEE(x1,y1,x2,y2)<<"\n";

    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
ifstream f ("alee.in");
ofstream g ("alee.out");
int n,q;
int x,y,z,t;
int mt[201][201];
int di[4]={0 , 0 , 1 , -1};
int dj[4]={1 , -1 , 0 , 0};
queue <pair <int ,int> > Q;
int ok (int i , int j)
{
    if(i<1 || i>n || j<1 || j>n)
        return 0;
    if(mt[i][j]>0)
        return 0;
    return 1;
}
int Lee (int x , int y)
{
    Q.push(make_pair(x,y));
    mt[x][y]=1;
    while(!Q.empty())
    {
        int i=Q.front().first;
        int j=Q.front().second;
        for(int p=0;p<4;++p)
        {
            if(ok(i+di[p] , j+dj[p]))
            {
                mt[i+di[p]][j+dj[p]]=mt[i][j]+1;
                Q.push(make_pair(i+di[p] , j+dj[p]));
            }
        }
        Q.pop();

    }
    return mt[z][t];
}


int main()
{
    f>>n>>q;
    for(int i=1;i<=q;++i)
    {
        int a,b;
        f>>a>>b;
        mt[a][b]=99999;
    }
    f>>x>>y>>z>>t;
    g<<Lee(x , y);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

ifstream f ("aib.in");
ofstream g ("aib.out");

int n,m;
long long a[5000005];


void update(int x,int val)
{
    while(x<=n)
    {
        a[x]+=val;
        x+=(x & -x);
    }
}


long long query(int x)
{
    long long rez=0;
    while(x>0)
    {
        rez+=a[x];
        x-=(x & -x);
    }
    return rez;
}
int bs(int val)
{
    int st=1;
    int dr=n;

    while(st<=dr)
    {
        int mij=(st+dr)/2;
        int x=query(mij);
        if(x==val)
            return mij;
        if(x<val)
            st=mij+1;
        else
            dr=mij-1;
    }
    return -1;
}
int main()
{
    f.tie(0);
    ios::sync_with_stdio(0);

    f>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        int x;
        f>>x;
        update(i,x);
    }
    for(int t=1; t<=m; ++t)
    {
        char tip;
        int a,b;
        f>>tip>>a;
        if(tip=='2')
            g<<bs(a)<<"\n";
        else
        {
            f>>b;
            if(tip=='0')
                update(a,b);
            else
                g<<query(b)-query(a-1)<<"\n";
        }



    }
    return 0;
}

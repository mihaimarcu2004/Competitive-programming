#include <bits/stdc++.h>

using namespace std;

int n,q;
int a[1000001];
int b[1000001];
int ur,vur;
int main()
{
    ur=0;
    vur=0;
    cin>>n;
    cin>>q;
    for (int test=1; test<=q; test++)
    {
        string cod;
        cin>>cod;
        if (cod=="SET")
        {
            int x,y;
            cin>>x>>y;
            a[x]=y;
            b[x]=test;
        }
        else if (cod=="RESTART")
        {
            ur=test;
            cin>>vur;
        }
        else
        {
            int poz;
            cin>>poz;
            if (ur>b[poz])
                cout<<vur<<"\n";
            else
                cout<<a[poz]<<"\n";
        }
    }
    return 0;
}

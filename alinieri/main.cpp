#include <bits/stdc++.h>

using namespace std;
ifstream f ("alinieri.in");
ofstream g ("alinieri.out");
int n,p,z,val;
int a[1001];
int gr[361];
int main()
{
    f>>n>>p>>z;
    for(int i=1;i<=n;++i)
       {
           int x;
           f>>x;
           a[x%180]++;
       }
    for(int i=1;i<=min(z,180);++i)
    {
        int cont=0;
        for(int j=0;j<=179;++j)
            gr[j]=0;

        for(int j=0;j<=179;j++)
            if (a[j]!=0)
                gr[(j*i)%180]+=a[j];


        for(int j=0;j<=179;++j)
        {
            if(gr[j]>=p)
                ++cont;
        }
        val+=cont;
    }
if(z>180)
 {
    int rest=z%180;
    z/=180;
    val*=z;
        for(int i=1;i<=rest;++i)
    {
        int cont=0;
        for(int j=0;j<=179;++j)
            gr[j]=0;

        for(int j=0;j<=179;j++)
            if (a[j]!=0)
                gr[(j*i)%180]+=a[j];


        for(int j=0;j<=179;++j)
        {
            if(gr[j]>=p)
                ++cont;
        }
        val+=cont;
    }

}
    g<<val;
    return 0;
}

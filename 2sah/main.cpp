#include <bits/stdc++.h>
#define mod 100003
using namespace std;

ifstream f ("2sah.in");
ofstream g ("2sah.out");

int p, n, k;
long long a[5][5];
long long b[5][5];
long long c[5][5];


void init(long long  x[5][5])
{
    for(int i=1; i<=3; ++i)
        for(int j=1; j<=3; ++j)
            x[i][j]=0;
}
void inmultire(long long  x[5][5], long long  y[5][5], long long  reciver[5][5])
{
    long long  z[5][5];
    init(z);
    for(int i=1; i<=3; ++i)
        for(int j=1; j<=3; ++j)
            for(int k=1; k<=3; ++k)
                z[i][j]+=1LL*(x[i][k]*y[k][j])%mod;


    for(int i=1; i<=3; ++i)
        for(int j=1; j<=3; ++j)
            reciver[i][j]=z[i][j]%mod;
}


long long putere(int exp)
{
    long long put=3;
    long long rest=1;
    while(exp>1)
    {
        if(exp%2==1)
        {
            rest=rest*put;
            rest=rest%mod;
            --exp;
        }
        else if(exp%2==0)
        {
            put=put*put;
            put=put%mod;
            exp=exp/2;

        }
    }
    put=put*rest;
    put=put%mod;
    return put;
}




void matrice(int exp)
{
    while(exp>=1)
    {
        if(exp%2==1)
        {
            inmultire(c, b, c);
            exp--;
        }
        inmultire(b, b, b);
        exp=exp/2;
    }
}


int main()
{
    f>>p;
    f>>n>>k;
    if(p==1)
    {
        g<<putere(k-1);
    }
    else
    {
        a[1][1]=1;
        a[1][2]=1;
        a[1][3]=1;

        b[1][3]=b[2][1]=b[2][3]=b[3][2]=b[3][3]=1;
        c[1][1]=c[2][2]=c[3][3]=1;

        if(n==k)
            g<<1;
        else if(n==k+1)
            g<<2;
        else if(n==k+2)
            g<<4;
        else
        {
            matrice(n-k+2);

            g<<c[1][3];
        }

    }
    return 0;
}

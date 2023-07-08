#include <bits/stdc++.h>

using namespace std;

ifstream f ("aemi.in");
ofstream g ("aemi.out");

int n,q;
int a[100005];
int arb[1000005];

void init(int nod , int st , int dr)
{
    if(st==dr)
    {
        arb[nod]=a[st];
        return;
    }
    int mij=(st+dr)/2;
    init(2*nod , st , mij);
    init(2*nod+1 , mij+1 , dr);
    arb[nod]=__gcd(arb[2*nod] , arb[2*nod+1]);

}

void update(int nod , int st , int dr , int poz , int val)
{
    if(st==dr)
    {
        arb[nod]=val;
        return;
    }
    int mij=(st+dr)/2;
    if(poz<=mij)
        update(2*nod, st, mij, poz, val);
    else
        update(2*nod+1, mij+1, dr, poz, val);

    arb[nod]=__gcd(arb[2*nod] , arb[2*nod+1]);


}
int query(int nod , int st , int dr , int x , int y)
{
    if(st==x && dr==y)
        return arb[nod];

    int mij=(st+dr)/2;
    if(mij>=y)
        return query(2*nod , st ,mij , x , y);
    else if(mij<x)
        return query(2*nod+1 ,  mij+1 ,dr, x , y);
    else
        return __gcd(query(2*nod , st ,mij , x , mij) , query(2*nod+1 , mij+1 , dr , mij+1 , y));


}
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>a[i];
    init(1,1,n);
    f>>q;
    for(int test=1;test<=q;++test)
    {
        int tip,st,dr;
        f>>tip>>st>>dr;
        if(tip==1)
        {
            g<<query(1,1,n,st,dr)<<"\n";
        }
        else
        {
            update(1,1,n,st,dr);
        }
    }
    return 0;
}

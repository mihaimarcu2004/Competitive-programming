#include <bits/stdc++.h>

using namespace std;

ifstream f ("aproapecoliniare.in");
ofstream g ("aproapecoliniare.out");

int n;
struct el
{
    long long x;
    long long y;
    int poz;
};
el a[100005];
int cmp1(el A, el B)
{
    if(A.x<B.x)
        return 1;
    if(A.x==B.x && A.y<B.y)
        return 1;
    return 0;
}

int cmp3(el A, el B)
{
    if(A.x<B.x)
        return 1;
    if(A.x==B.x && A.y>B.y)
        return 1;
    return 0;
}
int cmp2(el A, el B)
{
    return A.y<B.y;
}
long long aintst[1200005];
long long aintdr[1200005];

void Updatest(int nod , int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        aintst[nod]+=val;
        return;
    }
    else
    {
        int mij=(st+dr)/2;
        if(mij>=poz)
            Updatest(2*nod, st, mij, poz, val);
        else
            Updatest(2*nod+1, mij+1, dr, poz, val);
        aintst[nod]=aintst[2*nod]+aintst[2*nod+1];
    }
}


void Updatedr(int nod , int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        aintdr[nod]+=val;
        return;
    }
    else
    {
        int mij=(st+dr)/2;
        if(mij>=poz)
            Updatedr(2*nod, st, mij, poz, val);
        else
            Updatedr(2*nod+1, mij+1, dr, poz, val);
        aintdr[nod]=aintdr[2*nod]+aintdr[2*nod+1];
    }
}

int Queryst(int nod , int intervalst, int intervaldr, int st, int dr)
{
    if(st==intervalst && dr==intervaldr)
        return aintst[nod];
    else
    {
        int mij=(intervalst+intervaldr)/2;
        if(mij>=dr)
            return Queryst(2*nod, intervalst, mij, st, dr);
        if(mij<st)
            return Queryst(2*nod+1, mij+1, intervaldr, st, dr);
        else
            return Queryst(2*nod, intervalst, mij, st, mij)+Queryst(2*nod+1, mij+1, intervaldr, mij+1, dr);

    }
}


int Querydr(int nod , int intervalst, int intervaldr, int st, int dr)
{
    if(st==intervalst && dr==intervaldr)
        return aintdr[nod];
    else
    {
        int mij=(intervalst+intervaldr)/2;
        if(mij>=dr)
            return Querydr(2*nod, intervalst, mij, st, dr);
        if(mij<st)
            return Querydr(2*nod+1, mij+1, intervaldr, st, dr);
        else
            return Querydr(2*nod, intervalst, mij, st, mij)+Querydr(2*nod+1, mij+1, intervaldr, mij+1, dr);

    }
}


int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>a[i].x>>a[i].y;
    sort(a+1, a+n+1, cmp1);

    int poz=1;
    for(int i=1;i<=n;++i)
    {
        if(a[i].x!=a[i+1].x)
        {
            a[i].x=poz;
            ++poz;
        }
        else
            a[i].x=poz;
    }
    sort(a+1, a+n+1, cmp2);

     poz=1;
    for(int i=1;i<=n;++i)
    {
        if(a[i].y!=a[i+1].y)
        {
            a[i].y=poz;
            ++poz;
        }
        else
            a[i].y=poz;
    }
    sort(a+1, a+n+1, cmp1);

    for(int i=1;i<=n;++i)
        cout<<a[i].x<<" "<<a[i].y<<"\n";

    for(int i=3;i<=n;++i)
        Updatedr(1, 1, n, a[i].y, 1);
    Updatest(1, 1, n , a[1].y, 1);
    long long rez=0;
    for(int i=2;i<n;++i)
    {
        long long xst=Queryst(1, 1, n, 1, a[i].y);
        long long xdr=Querydr(1, 1, n , a[i].y, n);

        rez+=xst*xdr;


        Updatest(1, 1, n, a[i].y, 1);
        Updatedr(1, 1, n , a[i+1].y, -1);
    }

    for(int i=1;i<n;++i)
        Updatest(1, 1, n , a[i].y, -1);

    sort(a+1, a+n+1, cmp3);

    for(int i=3;i<=n;++i)
        Updatedr(1, 1, n, a[i].y, 1);
    Updatest(1, 1, n , a[1].y, 1);

    for(int i=2;i<n;++i)
    {
        long long yst=0;
        long long ydr=0;
        if(a[i].y<n)
            yst=Queryst(1, 1, n, a[i].y+1, n);
        if(a[i].y>1)
            ydr=Querydr(1, 1, n, 1, a[i].y-1);


        rez+=yst*ydr;

        Updatest(1, 1, n, a[i].y, 1);
        Updatedr(1, 1, n , a[i+1].y, -1);
    }
    g<<rez*2;

    return 0;
}

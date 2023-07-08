#include <bits/stdc++.h>
using namespace std;

ifstream f ("expectedgoals.in");
ofstream g ("expectedgoals.out");

int n;
int q;
int sum[4000005];
int poz[4000005];
int nrelem;


///pentru pozitie
void update1(int nod, int intervalst, int intervaldr, int x)
{
  /// cout<<nod<<" "<<intervalst<<" "<<intervaldr<<" "<<x<<"\n";
    if(intervalst==intervaldr)
    {
        poz[nod]++;
        return ;
    }
    int mij=(intervalst+intervaldr)/2;
    if(x>mij)
    {
        update1(2*nod+1 , mij+1 , intervaldr , x);
        poz[nod]=poz[2*nod]+poz[2*nod+1];
    }
    if(x<=mij)
    {
        update1(2*nod , intervalst , mij, x);
        poz[nod]=poz[2*nod]+poz[2*nod+1];
    }

}

///pentru valoare
void update2(int nod, int intervalst, int intervaldr, int x)
{
    if(intervalst==intervaldr)
    {
        sum[nod]+=x;
        return ;
    }
    int mij=(intervalst+intervaldr)/2;
    if(x>mij)
    {
        update2(2*nod+1 , mij+1 , intervaldr , x);
        sum[nod]=sum[2*nod]+sum[2*nod+1];
    }
    if(x<=mij)
    {
        update2(2*nod , intervalst , mij, x);
        sum[nod]=sum[2*nod]+sum[2*nod+1];
    }

}

int query1(int nod , int intervalst , int intervaldr , int val)
{
   /// cout<<nod<<" "<<intervalst<<" "<<intervaldr<<" "<<val<<" "<<sum[2*nod]<<"\n";
    if(intervaldr==intervalst)
        return intervaldr;

    int mij=(intervaldr+intervalst)/2;
    if(poz[2*nod]<val)
        return query1(2*nod+1 , mij+1 , intervaldr , val-poz[2*nod]);

    else
        return query1(2*nod , intervalst , mij , val);
}

int query2(int nod , int intervalst , int intervaldr , int elem)
{
    if(intervaldr==intervalst)
        return sum[nod];

    int mij=(intervaldr+intervalst)/2;
    if(elem<=mij)
        return query2(2*nod , intervalst , mij , elem);
    else
        return query2(2*nod+1 , mij+1 , intervaldr , elem)+sum[2*nod];

}

int query3(int nod , int intervalst , int intervaldr , int elem)
{
    if(intervaldr==intervalst)
        return poz[nod];

    int mij=(intervaldr+intervalst)/2;
    if(elem<=mij)
        return query3(2*nod , intervalst , mij , elem);
    else
        return query3(2*nod+1 , mij+1 , intervaldr , elem)+poz[2*nod];

}


int main()
{
    f.tie();
    ios_base::sync_with_stdio(0);
    f>>q;
    for(int query=1; query<=q; ++query)
    {
        int tip;
        int x;
        f>>tip>>x;
        if(tip==1)
        {
            n=max(n,x);
            ++nrelem;
            update1(1, 1, 1000005, x);
            update2(1, 1, 1000005, x);
            ///cout<<poz[1]<<" "<<sum[1]<<"\n";


        }
        if(tip==2)
        {
            ///ce elem apare pe poz x
            int elem=query1(1 , 1 , 1000005 , x);
            int maimic=query2(1 , 1, 1000005 , elem-1);
            int catemaimici=query3(1 , 1 ,1000005 ,  elem-1);

            ///cout<<elem<<" "<<maimic<<" "<<catemaimici<<"\n";

            g<<maimic+(x-catemaimici)*elem<<"\n";
        }
    }

    return 0;
}

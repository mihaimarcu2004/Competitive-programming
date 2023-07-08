#include <bits/stdc++.h>

using namespace std;

ifstream f ("anarhie.in");
ofstream g ("anarhie.out");

int n;
int val[300005];
int sum[300005];
vector <int> v[100005];
int pus[300005];
int parinte[300005];
struct el
{
    int maxim;
    int minim;
};
el padure[300005];

struct muc
{
    int x;
    int y;
};
muc muchii[300005];

int Find(int nod)
{
    int aux=nod;
    while(parinte[aux]!=0)
    {
        aux=parinte[aux];
    }
    while(parinte[nod]!=0)
    {
        int ajut=nod;
        nod=parinte[nod];
        parinte[ajut]=aux;
        padure[ajut].maxim=padure[aux].maxim;
        padure[ajut].minim=padure[aux].minim;
    }
    return aux;
}
int pseudoUnion(int x, int y)
{
    if(pus[x]==0 && pus[y]==0)
    {
        return abs(padure[x].maxim-padure[y].maxim);
    }
    if(pus[x]==0 && pus[y]==1)
    {
        return max(padure[x].maxim-padure[y].maxim, 0)+max(padure[y].minim-padure[x].minim, 0);
    }
    if(pus[x]==1 && pus[y]==0)
    {
        return max(padure[y].maxim-padure[x].maxim, 0)+max(padure[x].minim-padure[y].minim, 0);
    }
    if(pus[x]==1 && pus[y]==1)
    {
        if(padure[x].maxim>padure[y].maxim && padure[y].minim>padure[x].minim)
            return -padure[x].maxim+padure[x].minim;
       else if(padure[y].maxim>padure[x].maxim && padure[x].minim>padure[y].minim)
            return -padure[y].maxim+padure[y].minim;
       else
            return max((-padure[y].maxim+padure[x].minim),(-padure[x].maxim+padure[y].minim));
    }
}
void Union(int x, int y)
{
    parinte[x]=y;
    int mini=min(padure[x].minim, padure[y].minim);
    int maxi=max(padure[x].maxim, padure[y].maxim);
    padure[y].maxim=maxi;
    padure[y].minim=mini;
    padure[x].maxim=maxi;
    padure[x].minim=mini;



}


int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
        f>>val[i];
    for(int i=1;i<=n;++i)
    {
        padure[i].maxim=padure[i].minim=val[i];
    }
    for(int i=1;i<n;++i)
    {
        int x,y;
        f>>x>>y;
        muchii[i].x=x;
        muchii[i].y=y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=n-1;i>0;--i)
    {
        int adunmax=-9999999999;
        int unire1=0;
        int unire2=0;
        int ind=0;
        for(int j=1;j<n;++j)
        {
            int p1=Find(muchii[j].x);
            int p2=Find(muchii[j].y);
            if(p1!=p2)
            {
                int x=pseudoUnion(p1,p2);
                if(x>adunmax)
                {
                    unire1=p1;
                    unire2=p2;
                    adunmax=x;
                    ind=j;
                }
            }
        }
        sum[i]=sum[i+1]+adunmax;
        Union(unire1, unire2);
        pus[muchii[ind].x]=1;
        pus[muchii[ind].y]=1;
    }
    for(int i=1;i<=n;++i)
        g<<sum[i]<<" ";

    f.close();

    return 0;
}

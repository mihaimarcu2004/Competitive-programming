#include <bits/stdc++.h>

using namespace std;

ifstream f ("aranjare3.in");
ofstream g ("aranjare3.out");

int n;
int m;

struct el
{
    int a, b;
};
el sol[100005];
vector <int> s[10005];
int a[10005];

int main()
{
    f>>n;
    for(int i=1; i<=n; ++i)
        f>>a[i];

    int m=0;
    int cont=0;
    for(int i=n; i>0; --i)
    {
        int ok=0;
        for(int j=1; j<=m; ++j)
        {
            if(s[j].back()>a[i])
            {
                s[j].push_back(a[i]);
                ok=1;
                sol[++cont]= {0, j};
                break;

            }
        }
        if(ok==0)
        {
            ++m;
            s[m].push_back(a[i]);
            sol[++cont]= {0, m};
        }
    }
    for(int i=1;i<=n;++i)
    {
        int minim=9999999;
        int stmin=0;
        for(int j=1;j<=m;++j)
        {
            if(s[j].size()!=0)
            {
                if(minim>s[j].back())
                {
                    minim=s[j].back();
                    stmin=j;
                }
            }
        }
        sol[++cont]={stmin , 0};
        s[stmin].pop_back();
    }
    g<<m<<" "<<cont<<"\n";
    for(int i=1;i<=cont;++i)
        g<<sol[i].a<<" "<<sol[i].b<<"\n";



    return 0;
}

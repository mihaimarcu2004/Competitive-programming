#include <bits/stdc++.h>

using namespace std;
ifstream f ("anagrame3.in");
ofstream g ("anagrame3.out");
int p;
int n,m;
int fr[30];
int copiefr[30];
char a[100005];
char v[100005];

int verif()
{
    for(int i=0; i<30; ++i)
        if(fr[i]>0)
            return 0;
    return 1;
}
void copiere()
{
    for(int i=0; i<30; ++i)
        fr[i]=copiefr[i];
}
int main()
{
    f>>p;
    f>>a;
    f>>v;
    int n=strlen(a);
    int m=strlen(v);
    for(int i=0; i<m; ++i)
        fr[v[i]-'a']++;
    for(int i=0; i<30; ++i)
        copiefr[i]=fr[i];
    int s=0;
    for(int i=0; i<n; ++i)
    {
        if(fr[a[i]-'a']>0)
        {
            --fr[a[i]-'a'];
        }
        if(fr[a[i]-'a']==0)
        {
            if(verif())
            {
                copiere();
                s+=m;
            }
        }
    }
    if(p==1)
        g<<s;
    else
    {
        copiere();
        for(int i=0; i<n; ++i)
        {
            if(fr[a[i]-'a']>0 && s>0)
            {
                --fr[a[i]-'a'];
                g<<a[i];
                --s;
            }
            if(fr[a[i]-'a']==0)
            {
                if(verif())
                {
                    copiere();
                }
            }
        }
    }
    return 0;
}

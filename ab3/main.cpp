#include <bits/stdc++.h>

using namespace std;
ifstream f ("ab3.in");
ofstream g ("ab3.out");
int n;
long long  a[100001];
long long  cub (long long t)
{
    return t*t*t;

}
int main()
{
    long long  maxim=1000000;
    f>>n;
    for(int i=1; i<=n; ++i)
     {
         f>>a[i];

     }

    for(int i=1; i<=n; ++i)
    {
        if(a[i]<3)
            g<<0<<"\n";
        else
        {
            long long st=1;
            long long dr=maxim;
            long long j=(st+dr)/2;
            while(st<=dr)
            {
                if(cub(j)+j<=a[i] && cub(j+1)+j+1 >a[i])
                {
                    g<<j<<"\n";
                    break;
                }
                if(cub(j)+j<=a[i])
                    st=j+1;
                else
                    dr=j-1;
                j=(st+dr)/2;
            }
        }

    }

    return 0;
}

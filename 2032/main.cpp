#include <bits/stdc++.h>

using namespace std;
ifstream f ("mmult.in");
ofstream g ("mmult.out");
int n;
int x;
int s;
int fr[1000005];
int main()
{
    f>>n;
    for(int i=1;i<=n;++i)
    {
        f>>x;
        fr[x]++;

    }
    for(int i=2;i<=1000000;++i)
    {
        if(fr[i]>fr[i-1])
        {
            g<<-1;
            return 0;
        }
    }
    g<<fr[1];

    return 0;
}

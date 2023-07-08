#include <bits/stdc++.h>

using namespace std;

int n;
struct interval
{
    int st, dr;

};
interval v[1005]
int mars[1005];
int sumpart[1005];
int main()
{
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>v[i].st>>v[i].dr;
        mars[v[i].st]++;
        mars[v[i].dr+1]--;
    }

    for(int i=1; i<=2*n; ++i)
        sumpart[i]=sumpart[i-1]+mars[i];

    int cont=0;
    int ok=0;
    while(ok==0)
    {
        ok=1;
        int maxim=0;
        for(int i=1;i<=2*n;++i)
        {
            if(sumpart[i]>maxim)
                maxim=sumpart[i];
        }
        if(maxim>0)
        {
            maxim=1;
            for(int i=1;i<=2*n;++i)
            {

            }
        }
    }




    return 0;
}

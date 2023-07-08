#include <iostream>
#include <queue>
using namespace std;
int T,n;

void calcul(int n, int A[])
{
    queue <int> Q;
    for(int i=1;i<=n;i++)
        Q.push(i);
    for(int i=1;i<=n;i++)
    {
        ///se determina A[i]
        for(int p=1;p<=i;p++)
        {
            int v;
            v=Q.front();
            Q.pop();
            Q.push(v);
        }
        A[i]=Q.front();
        Q.pop();
    }
}
int main()
{
    cin>>T;
    for(int test=1;test<=T;test++)
    {
        cin>>n;
        int A[15];
        int S[15];
        calcul(n,A);
        for(int i=1;i<=n;i++)
            S[A[i]]=i;
        for(int i=1;i<=n;i++)
            cout<<S[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

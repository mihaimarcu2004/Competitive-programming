#include <bits/stdc++.h>

using namespace std;

ifstream f ("adn.in");
ofstream g ("adn.out");



string s[50];
int schimb[50][50];

int KMP(string a, string b)
{
    int ss[100005]= {0};
    int rez[100005]= {0};
    int n=a.size();
    int m=b.size();

    --n;
    --m;

    int i=0;
    int j=1;
    ss[0]=-1;
    while(i<=j && j<=n)
    {
        if(a[i]==a[j])
        {
            ss[j]=i;
            ++i;
            ++j;
        }
        else
        {
            --i;
            while(a[i+1]!=a[j] && i!=-1)
            {
                i=ss[i];
            }
            ++i;
            if(a[i]==a[j])
            {
                ss[j]=i;
                ++i;
                ++j;
            }
            else
            {
                ss[j]=-1;
                ++j;
            }

        }
    }


    i=0;
    j=0;

    while(i<=j && j<=m)
    {
        if(a[i]==b[j] && i<=n)
        {
            if(j!=0 && i!=0)
                rez[j]=i;
            else if(j==0 || i==0)
                rez[j]=i;

            ++i;
            ++j;
        }
        else
        {
            --i;
            while(a[i+1]!=b[j] && i!=-1)
            {
                i=ss[i];
            }
            ++i;
            if(a[i]==b[j])
            {
                rez[j]=i;
                ++i;
                ++j;
            }
            else
            {
                rez[j]=-1;
                ++j;
            }
        }
        if(i==n+1)
        {
            i=ss[i-1]+1;
        }
    }


    for(int k=0;k<=m;++k)
        if(rez[k]==n)
            return -3;

    return rez[m];
}

int dp[20][500005];
int from[20][500005];
int n;

struct el
{
    int nod;
    int stare;
    int valoare;
    bool operator < (const el &A)const
    {
        return valoare>A.valoare;
    }

};
priority_queue <el> Q;

int intra(int i, int st)
{
    if(((1<<(i-1)) & st)==0)
        return 1;
    return 0;

}



void Ciclu(int nod)
{
    while(!Q.empty())
        Q.pop();

    Q.push({nod, (1<<(nod-1)),  s[nod].size()});
    dp[nod][(1<<(nod-1))]=s[nod].size();
    while(!Q.empty())
    {
        int nod=Q.top().nod;
        int stare=Q.top().stare;
        int val=Q.top().valoare;

        ///cout<<nod<<" "<<stare<<" "<<val<<"\n";
        for(int i=1; i<=n; ++i)
        {

            if(intra(i, stare) && i!=nod)
            {

                if(dp[nod][stare]+schimb[nod][i]<dp[i][stare+(1<<(i-1))] || dp[i][stare+(1<<(i-1))]==0)
                {
                    dp[i][stare+(1<<(i-1))]=dp[nod][stare]+schimb[nod][i];
                    from[i][stare+(1<<(i-1))]=i;
                    Q.push({i, stare+(1<<(i-1)), dp[i][stare+(1<<(i-1))]});

                }
               /// cout<<i<<" "<<nod<<" "<<dp[nod][stare]<<" "<<stare<<" "<<dp[i][stare+(1<<(i-1))]<<"\n";

            }

        }
        Q.pop();
    }

}
int rasp[1000];

void inapoi(int cuv , int stare , int pas , int val)
{
   /// cout<<"\n";
    ///cout<<cuv<<" "<<stare<<" "<<pas<<" "<<val<<"\n";
    rasp[pas]=cuv;
    if(pas==1)
        return ;
    for(int i=1;i<=n;++i)
    {
        if(intra(i , stare)==0 && i!=cuv)
        {
          ///  cout<<i<<" "<<dp[i][stare-(1<<(i-1))]<<" "<<schimb[i][cuv]<<" "<<stare-(1<<(i-1))<<"\n";
            if(dp[i][stare]+schimb[i][cuv]==val)
            {
                inapoi(i , stare-(1<<(i-1)) , pas-1 , val-schimb[i][cuv]);
                return ;
            }
        }
    }




}

void afisare()
{
    g<<s[rasp[1]];
    for(int i=2;i<=n;++i)
    {
        int ultim=schimb[rasp[i-1]][rasp[i]];
        if(ultim!=0)
        {
            for(int j=s[rasp[i]].size()-ultim;j<s[rasp[i]].size();++j)
                g<<s[rasp[i]][j];
        }

    }
}








int main()
{
    f>>n;
    for(int i=1; i<=n; ++i)
        f>>s[i];
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            if(i!=j)
            {
                if(KMP(s[j] , s[i])==-3)
                    schimb[i][j]=0;
                else
                    schimb[i][j]=s[j].size()-KMP(s[j], s[i])-1;
            }
            else
                schimb[i][j]=-1;
    }


    for(int i=1; i<=n; ++i)
    {
        Ciclu(i);
    }
    int minim=INT_MAX;
    int imin=-1;
    for(int i=1; i<=n; ++i)
    {
        if(minim>dp[i][(1<<n)-1])
        {
            minim=dp[i][(1<<n)-1];
            imin=i;
        }

       ///cout<<dp[i][(1<<n)-1]<<"\n";
    }
   /// cout<<imin<<" "<<minim<<"\n";
    inapoi(imin , (1<<n)-1-(1<<(imin-1)) , n , minim);

    afisare();

    return 0;
}

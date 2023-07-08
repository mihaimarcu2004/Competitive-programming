#include <bits/stdc++.h>

using namespace std;
ifstream f ("ai.in");
ofstream g ("ai.out");
int mt[1005][1005];
int n;
int T1,T2, S1,S2, S3,S4, R1,R2, R3,R4;

int Robot1Tinta1[10005];
int Robot1Tinta2[10005];
int Robot2Tinta1[10005];
int Robot2Tinta2[10005];


int r2[1005][1005];
int LeeRobot1[1005][1005];
int LeeRobot2[1005][1005];
int di[4]= {0,0,1,-1};
int dj[4]= {1,-1,0,0};
int mx1,mx2,mx3,mx4;
queue <pair<int,int>> Q;

int ok1(int i, int j )
{
    if(i<1 || j<1 || i>n || j>n)
        return 0;
    if(mt[i][j]==100 || mt[i][j]==-1)
        return 0;
    if(LeeRobot1[i][j]>0)
        return 0;
    return 1;
}

int ok2(int i, int j )
{
    if(i<1 || j<1 || i>n || j>n)
        return 0;
    if(mt[i][j]==100 || mt[i][j]==-1)
        return 0;
    if(LeeRobot2[i][j]>0)
        return 0;
    return 1;
}
void Lee1()
{
    Q.push({R1,R2});
    while(!Q.empty())
    {
        int i=Q.front().first;
        int j=Q.front().second;
        for(int x=0; x<4; ++x)
        {
            if(ok1(i+di[x], j+dj[x]))
            {
                LeeRobot1[i+di[x]][j+dj[x]]=LeeRobot1[i][j]+1;
                Q.push({i+di[x], j+dj[x]});
            }

        }
        Q.pop();
    }
}

void Lee2()
{
    Q.push({R3,R4});
    while(!Q.empty())
    {
        int i=Q.front().first;
        int j=Q.front().second;
        for(int x=0; x<4; ++x)
        {
            if(ok2(i+di[x], j+dj[x]))
            {
                LeeRobot2[i+di[x]][j+dj[x]]=LeeRobot2[i][j]+1;
                Q.push({i+di[x], j+dj[x]});
            }

        }
        Q.pop();
    }
}




int main()
{
    f>>n;
    f>>T1>>T2>>S1>>S2>>S3>>S4>>R1>>R2>>R3>>R4;
    /// tinta 100 , sursa 1000 , robot 10

    mt[S1][S2]=1001;
    mt[S3][S4]=1001;
    mt[R1][R2]=10;
    mt[R3][R4]=10;
    mt[T1][T2]=100;
    int q;
    f>>q;
    for(int i=1; i<=q; ++i)
    {
        int a,b;
        f>>a>>b;
        mt[a][b]=-1;
    }
    ///se rezolva 1;
    int maxim=0;
    for(int i=1; i<=n; ++i)
    {
        int cont=0;
        for(int j=1; j<=n; ++j)
        {
            if(mt[i][j]==-1)
                ++cont;
            if(mt[i][j]==0)
                cont=0;
            maxim=max(maxim,cont);
        }
    }
    for(int i=1; i<=n; ++i)
    {
        int cont=0;
        for(int j=1; j<=n; ++j)
        {
            if(mt[j][i]==-1)
                ++cont;
            else
                cont=0;
            maxim=max(maxim,cont);
        }
    }
    g<<maxim<<"\n";

    Lee1();
    Lee2();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            cout<<LeeRobot1[i][j]<<" ";
        cout<<"\n";
    }
    int l1=0;
    int l2=0;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if((i-S1)*(T2-S2)==(j-S2)*(T1-S1) && mt[i][j]!=-1 && mt[i][j]!=100
                && i<=max(S1,T1) && i>=min(S1,T1) && j<=max(S2,T2) && j>=min(S2,T2)
                && (LeeRobot1!=0 || mt[i][j]==10) && (LeeRobot2!=0 || mt[i][j]==10))
            {

                Robot1Tinta1[++l1]=LeeRobot1[i][j];
                Robot2Tinta1[l1]=LeeRobot2[i][j];



            }
            if((i-S3)*(T2-S4)==(j-S4)*(T1-S3) && mt[i][j]!=-1 && mt[i][j]!=100 && i<=max(S3,T1) && i>=min(S3,T1) && j<=max(S4,T2) && j>=min(S4,T2) && (LeeRobot1!=0 || mt[i][j]==10) && (LeeRobot2!=0 || mt[i][j]==10))
            {

                Robot1Tinta2[++l2]=LeeRobot1[i][j];
                Robot2Tinta2[l2]=LeeRobot2[i][j];


            }
        }
    }

    sort(Robot1Tinta1+1, Robot1Tinta1+l1+1);
    sort(Robot2Tinta1+1, Robot2Tinta1+l2+1);
    sort(Robot1Tinta2+1, Robot1Tinta2+l2+1);
    sort(Robot2Tinta1+1, Robot2Tinta1+l1+1);

    int m1=max(Robot1Tinta1[1], Robot2Tinta2[1] );
    int m2=max(Robot1Tinta2[1], Robot2Tinta1[1] );
    cout<<Robot1Tinta1[1]<<" "<< Robot2Tinta2[1]<<" " <<Robot1Tinta2[1]<<" "<< Robot2Tinta1[1];
    g<< min(m1, m2);
    return 0;
}

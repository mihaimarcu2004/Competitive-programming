#include <bits/stdc++.h>

using namespace std;


string pus[100005];
string nefolosit[100005];
int nr=0;
int x=0;
struct el
{
    string s;
    int st;
    int dr;
    int total;
    int index;
    int maducst;
    int maducdr;
};
el a[100005];

int diferit(int y)
{
    if(!isalpha(pus[y][0]))
        return 0;
    for(int i=0; i<x; ++i)
        if(pus[y]==nefolosit[i])
            return 0;
    return 1;
}
int cmp(el A, el B)
{
    for(int i=0; i<min(A.s.size(), B.s.size()); ++i)
    {
        if(tolower(A.s[i])<tolower(B.s[i]))
            return 1;
        if(tolower(A.s[i])>tolower(B.s[i]))
            return 0;
    }
}

string findARow(string original, string unused, string rows)
{

    for(int i=0; i<original.size(); ++i)
    {
        if(!isalpha(original[i]))
        {
            ++nr;
            if(original[i]!=' ')
            {
                pus[nr].push_back(original[i]);
            }

        }
        else
            pus[nr].push_back(original[i]);
    }

    for(int i=0; i<unused.size(); ++i)
    {

        if(unused[i]==' ')
            ++x;
        else
            nefolosit[x].push_back(unused[i]);
    }
    int i=1;
    int kk=int(nr);


    int max1=0;
    int max2=0;
    int max3=0;
    while(i<=kk)
    {
        a[i].s=pus[i];
        a[i].index=i;
        int ok=1;
        for(int j=0;j<x;++j)
            if(a[i].s==nefolosit[j])
                ok=0;
        for(int j=i+1; j<=min(nr, i+3); ++j)
        {
            if(diferit(j))
                a[i].dr+=pus[j].size()+1;
            else
                break;
            ++a[i].maducdr;

        }
        if(ok==1)
        max1=max(max1, a[i].dr);
        for(int j=i-1; j>=max(0, i-3); --j)
        {
            if(diferit(j))
                a[i].st+=pus[j].size()+1;
            else
                break;
            ++a[i].maducst;
        }
        if(ok==1)
        max2=max(max2, a[i].st);
        int ll=a[i].s.size();
        if(ok==1)
        max3=max(max3, ll);
        ++i;
    }
    sort(a+1, a+nr+1, cmp);
    int incep=0;
    for(int i=1; i<=nr; ++i)
    {
        if(isalpha(a[i].s[0]))
        {
            incep=i;
            break;
        }
    }
    for(int i=1; i<=nr; ++i)
        cout<<a[i].s<<" "<<a[i].st<<" "<<a[i].dr<<"\n";

    int l1,l2;
    int val=0;
    int stop=0;
    for(int x=0; x<rows.size(); ++x)
    {
        if(rows[x]==' ')
        {
            stop=x;
            break;
        }
        val*=10;
        val+=rows[x]-'0';
    }
    l1=val;
    val=0;
    for(int x=stop+1; x<rows.size(); ++x)
    {
        if(rows[x]==' ')
            stop=x;
        val*=10;
        val+=rows[x]-'0';
    }
    l2=val;

    int puss=0;
    int summax=0;
    int indmax=0;
    for(int i=1; i<=nr; ++i)
    {
        int ok=1;
        for(int j=0;j<x;++j)
            if(a[i].s==nefolosit[j])
                ok=0;
        if(diferit(i) && ok==1)
        {
            ++puss;
            if(puss>=l1 && puss<=l2 && a[i].s.size()+a[i].st+a[i].dr>summax)
            {
                summax=a[i].s.size()+a[i].st+a[i].dr;
                indmax=i;
            }
        }

    }
    string rez;
    for(int i=a[indmax].index-a[indmax].maducst;i<a[indmax].index;++i)
        rez=rez+pus[i], rez=rez+" ";
    for(int i=a[indmax].st+1;i<=max2;++i)
        rez=rez+"-";
    rez=rez+" ";
    rez=rez+"<";
    rez+=a[indmax].s;
    for(int i=a[indmax].s.size();i<=max3-1;++i)
        rez+="-";
    rez+=">";
    rez+=" ";
    for(int i=a[indmax].index+1;i<=a[indmax].index+a[indmax].maducdr;++i)
    {
         rez+=pus[i];
        if(i+1<=a[indmax].index+a[indmax].maducdr)
            rez+=" ";
    }

    for(int i=a[indmax].dr+1;i<=max1-a[indmax].dr;++i)
        rez+="-";
    return rez;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string original;
    getline(cin, original);

    string unused;
    getline(cin, unused);

    string rows;
    getline(cin, rows);

    string result = findARow(original, unused, rows);

    fout << result << "\n";

    fout.close();

    return 0;
}

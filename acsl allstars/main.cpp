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
    int i=0;
    int kk=int(nr);

    while(i<=kk)
    {

        a[i].s=pus[i];
        a[i].index=i;
        for(int j=i+1; j<=min(nr, i+3); ++j)
        {
            if(diferit(j))
                a[i].dr+=pus[j].size();
            else
                break;

        }

        for(int j=i-1; j>=max(0, i-3); --j)
        {
            if(diferit(j))
                a[i].st+=pus[j].size();
            else
                break;
        }

     ///   cout<<a[i].st<<" "<<a[i].dr<<"\n";
        ++i;
    }




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

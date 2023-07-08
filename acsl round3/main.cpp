#include <bits/stdc++.h>

using namespace std;

string s;
vector <int> val;

void inserare(int poz, char vali)
{
    cout<<poz<<" "<<vali<<"\n";

    s.push_back('0');
    val.push_back(0);

    int maxi=0;
    if(s.size()==0)
        maxi=-1;
   else  if(poz==0)
        maxi=val[0];
   else if(poz==s.size()-1)
        maxi=val[s.size()-2];
    else
    {
        maxi=max(val[poz-1], val[poz]);
    }
    maxi=maxi+1;


    for(int i=s.size()-1; i>poz; --i)
    {
        s[i]=s[i-1];
        val[i]=val[i-1];
    }
    s[poz]=vali;
    val[poz]=maxi;
}


string onlyLeftOrRight(string input)
{


    for(int i=0; i<input.size(); ++i)
    {
        int ok=0;
        if(s.size()==0 || input[i]>s[s.size()-1])
        {
            ok=1;
            s.push_back(input[i]);
            if(s.size()==1)
            val.push_back(0);
            else
                val.push_back(val[val.size()-1]+1);
        }
        else
        {
            for(int j=0; j<input.size()-1 && ok==0; ++j)
            {
                if(s[j]<input[i] && s[j+1]>=input[i])
                {
                    inserare(j+1, input[i]);
                    ok=1;
                }

            }
            if(ok==0)
            {
               inserare(0, input[i]);
            }
        }
        cout<<s<<"\n";
        for(int x=0;x<val.size();++x)
            cout<<val[x]<<" ";
        cout<<"\n\n";

    }
    string st;
    string dr;

    cout<<"\n";
    for(int i=0;i<val.size();++i)
    {
        int okst=1;
        int okdr=1;
        int pusst=0;
        int pusdr=0;
        for(int j=i-1;j>=0;--j)
        {
            if(val[j]<val[i])
                okst=0;
            if(val[j]==val[i]+1)
                pusst=1;
            if(pusst==1)
                break;

        }
        for(int j=i+1;j<s.size();++j)
        {
            if(val[j]<val[i])
                okdr=0;
            if(val[j]==val[i]+1)
                pusdr=1;
            if(pusdr==1)
                break;

        }
        int bagst=0;
        int bagdr=0;
        if(okst==1 && pusst==1)
            bagst=1;
        if(okdr==1 && pusdr==1)
            bagdr=1;
        if(bagst==1 && bagdr==0)
            st.push_back(s[i]);
        else if(bagst==0 && bagdr==1)
            dr.push_back(s[i]);
    }
    string rasp;
    if(st.size()!=0)
    rasp+=st;
    else
        rasp+="NONE";
    rasp+=' ';
    if(dr.size()!=0)
    rasp+=dr;
    else
        rasp+="NONE";
    return rasp;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string input;
    getline(cin, input);

    string result = onlyLeftOrRight(input);

    fout << result << "\n";

    fout.close();

    return 0;
}

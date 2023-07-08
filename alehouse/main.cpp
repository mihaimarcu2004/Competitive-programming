#include <iostream>

using namespace std;
int n,k;
struct prieteni{
int i;
int j;
};
prieteni a[100005];

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i].i>>a[i].j;
        a[i].j+=k;
    }
    sort(a+1 , a+n+1 , cmp);
    return 0;
}

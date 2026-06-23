#include<iostream>
#include<algorithm>

using namespace std;
const int N=1010;
int a[N];
bool b[N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int t;cin>>t;
        //cout<<t<<endl;
        b[t]=true;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(b[a[i]%1000])ans++;
    }
    cout<<ans<<endl;

}
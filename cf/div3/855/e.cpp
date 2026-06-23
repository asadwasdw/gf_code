#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10;
char a[N];
void solve()
{
    int n;cin>>n;
    int ans=n-1;
    for(int i=1;i<=n;i++)
    {
        char t;
        cin>>t;
        a[i]=t;
        if(i>=3&&t==a[i-2])ans--;
    }
    cout<<ans<<endl;
}

int main()
{
    int t;cin>>t;while(t--)
    solve();
}
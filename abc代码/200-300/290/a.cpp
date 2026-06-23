#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

const int N=2e5+10;
int a[N];
void solve()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)cin>>a[i];

    long long ans=0;
    for(int i=1;i<=m;i++)
    {
        int x;cin>>x;
        ans+=a[x];
    }

    cout<<ans<<endl;
   

}


int main()
{
    // int t;cin>>t;while(t--){
        solve();
    // }
}
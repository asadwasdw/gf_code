#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

ll a[N];
ll b[N];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int j=1;j<=n;j++)cin>>b[j];

    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i]*b[i];
    }

    if(sum)cout<<"No";
    else cout<<"Yes";


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
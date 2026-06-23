#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

ll a[N],b[N];
ll dp[N][N];


void solve()
{
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    for(int i=1;i<=m;i++)
    {
        int x;
        ll y;cin>>x>>y;
        b[x]=y;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][0] = max({dp[i-1][j-1],dp[i][0]}); 
            dp[i][j] = dp[i-1][j-1]+a[i]+b[j];
        }
    }

    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        ans= max(ans,dp[n][i]);
    }

    cout<<ans<<endl;
    





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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n,k;
int w[N];
int dp[N][2];
int ans = 0;

void dfs(int u,int fa){
    if (w[u] == 1) {
        dp[u][0]=-INF,dp[u][1]=1;
    } else {
        dp[u][0]=w[u];
        dp[u][1]=-INF;
    }

    for(auto v:edg[u]) {
        if(v==fa)continue;
        dfs(v,u);
        int t1 = dp[u][1];
        int t0 = dp[u][0];

        dp[u][1] = max({t1,t1+dp[v][0],t0+dp[v][1]});
        dp[u][0] = max({t0,t0+dp[v][0],t1+dp[v][1]});
    }

    if(dp[u][k&1]>=k) {
        ans++;
        dp[u][1]=dp[u][0]=-INF;
    }
}

void solve()
{
    ans = 0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>w[i],edg[i].clear();

    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    dfs(1,-1);
    cout<<ans<<"\n";
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int dp[N][2];

int c[N];

int ans = 0;
void dfs(int u, int fa) {
    dp[u][c[u]] = 0;

    int mx0 = -INF, mx1 = - INF;
    if(c[u] == 0) mx0 = 0;
    else mx1 = 0;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);

        ans = max(ans, mx0 + dp[v][1] + 1);
        ans = max(ans, mx1 + dp[v][0] + 1);


        // cout << u << " " << v << " " << ans << endl;

        mx1 = max(mx1, dp[v][1] + 1);
        mx0 = max(mx0, dp[v][0] + 1);
    }
    dp[u][0] = mx0;
    dp[u][1] = mx1;
    // cout << u << " " << dp[u][1] << " " << dp[u][0] << endl;
    // ans = max(ans, dp[u][1] + dp[u][0]);
}





void solve()
{
    memset(dp, -0x3f, sizeof dp);
    // cout << INF << endl;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << ans << endl;



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}
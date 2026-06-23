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

int son[N], deep[N];
ll dp[N];

void dfs(int u, int fa) {
    deep[u] = deep[fa] + 1;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
        son[u] += son[v] + 1;
        dp[u] += dp[v];
    }
    dp[u] += son[u];

    // cout << u << " " << son[u] << " " << dp[u] << endl;
}
ll f[N];
int n;

void dfs2(int u, int fa) {
    f[u] = f[fa] + n - 2 * son[u];
    for(auto v : adj[u]) {
        if(v == fa) continue;
        // f[v] = f[u] + n - 2 * son[v];
        dfs2(v, u);
    }
}


void solve()
{
    cin >> n;

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    // f[1] = dp[1];
    dfs2(1, 0);
    int ans = 1;
    for(int i = 1; i <= n; i ++) {
        if(f[i] > f[ans]) ans = i;
        // cout << f[i] << endl;
    }
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
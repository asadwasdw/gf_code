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
int n, k;
int m[N];

int dp[N][25];

void dfs(int u, int fa) {
    dp[u][0] += m[u];
    for(auto v : adj[u]) {
        if(v == fa) continue;

        dfs(v, u);

        for(int i = 0; i <= k; i ++) {
            dp[u][i + 1] += dp[v][i];
        }
    }
    // cerr << u << endl;
    // for(int i = 0; i <= k; i ++) cerr << dp[u][i] << " \n"[i == k];
}

int f[N][25];

int ans[N];

void dfs2(int u, int fa) {

    for(int i = 0; i <= k; i ++) {
        f[u][i] += dp[u][i];
        ans[u] += f[u][i];
    }

    for(auto v : adj[u]) {
        if(v == fa) continue;
        for(int j = 0; j <= k; j ++) {
            // f[v][j] += dp[v][j];
            if(j >= 1) f[v][j] += f[u][j - 1];
            if(j >= 2) f[v][j] -= dp[v][j - 2];
        }
        dfs2(v, u);
    }

    // cout << u << "\n";
    // for(int i = 0; i <= k; i ++) cout << f[u][i] << " \n"[i == k];
}



void solve()
{
    cin >> n >> k;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    for(int i = 1; i <= n; i ++) {
        cin >> m[i];
    }

    dfs(1, 0);
    dfs2(1, 0);

    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << endl;
    }






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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<PII>>adj(N);
ll dis[N][2], son[N], f[N];

void dfs(int u, int fa) {
    int res = 0;
    for(auto [v, w] : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
        ll t = dis[v][0] + w;
        if(t >= dis[u][0]) {
            dis[u][1] = dis[u][0];
            dis[u][0] = t;
            son[u] = v;
        } else if(t > dis[u][1]) {
            dis[u][1] = t;
        }
    }
    res = dis[u][0];
    // cout << u << " " << res << endl;
}


void dfs2(int u, int fa) {
    for(auto [v, w] : adj[u]) {
        if(v == fa) continue;
        if(son[u] != v) {
            f[v] = max(f[u], dis[u][0]) + w;
        } else {
            f[v] = max(f[u], dis[u][1]) + w;
        }
        dfs2(v, u);
    }
    // cout << u << " " << f[u] << " " << dis[u][0] << " " << dis[u][1] << endl;
}

void solve()
{
    int n;
    while(cin >> n) {
        for(int i = 2; i <= n; i ++) {
            int u = i, v, w;
            cin >> v >>w; 
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        dfs(1, 0);
        dfs2(1, 0);
        // for(int i = 1; i)

        for(int i = 1; i <= n; i ++) {
            cout << max(f[i], dis[i][0]) << endl;
        }

        for(int i = 1; i <= n; i ++) {
            adj[i].clear();
            dis[i][0] = dis[i][1] = 0;
            son[i] = f[i] = 0;
        }
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
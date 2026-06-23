#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
using ll = long long;
using i64 = long long;
#define endl "\n"
using P = pair<int, int>;
constexpr int N = 1e5 + 10;

int n;
vector<P> g[N];

int root, sz_root, sz[N], cur_n;
bool st[N];

void dfs(int u, int fa){
    sz[u] = 1;
    int mx = 0;
    for(auto [v, w] : g[u]){
        if(v == fa || st[v])continue;
        dfs(v, u);
        sz[u] += sz[v];
        mx = max(mx, sz[v]);
    }
    mx = max(mx, cur_n - sz[u]);
    if(sz_root > mx){
        mx = sz_root;
        root = u;
    }
}
map<int, int> mp;
int dist[N];
ll res;
void dfs2(int u, int fa, int op){
    if(op == 0){
        res += mp[(2019 - dist[u]) % 2019];
    }
    else{
        mp[dist[u]]++;
    }
    for(auto [v, w] : g[u]){
        if(v == fa || st[v])continue;
        dist[v] = (dist[u] + w) % 2019;
        dfs2(v, u, op);
    }
}

void dfz(int u){
    st[u] = true;
    for(auto [v, w] : g[u]){
        if(st[v])continue;
        dist[v] = w;
        dfs2(v, u, 0);
        dfs2(v, u, 1);
    }
    res += mp[0];
    mp.clear();
    for(auto [v, w] : g[u]){
        if(st[v])continue;
        sz_root = INF;
        dfs(v, u);
        dfs(root, 0);
        cur_n = sz[root];
        dfz(root);
    }
}

void solve() {
    while(cin >> n){
    for(int i=1; i<n; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    cur_n = n;
    sz_root = INF;
    dfs(1, 0);
    dfs(root, 0);
    cur_n = sz[root];
    dfz(root);
    cout << res << endl;

    for(int i=1; i<=n; ++i){
        g[i].clear();
        root = sz_root = cur_n = 0;
        sz[i] = dist[i] = 0;
        st[i] = false;
    }
    mp.clear();
    res = 0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}
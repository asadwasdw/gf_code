#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);
struct gflca{
    int n, m, root;
    vector<vector<int>> fa;
    vector<int> dep;
    void init(int _n, int _m, int _root) {
        n = _n + 10;
        m = _m;
        root = _root;
        fa.resize(n);
        dep.resize(n);

        for(int i = 0; i < n; i ++) {
            fa[i].resize(m);
            dep[i] = 0;
            for(int j = 0; j < m; j ++) fa[i][j] = 0;
        }

        dfs(root, 0);
    }

    void dfs(int u, int father) {
        dep[u] = dep[father] + 1;
        fa[u][0] = father;
        for(int i = 1; (1 << i) <= dep[u]; i ++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }

        for(auto v: adj[u]) {
            if(v != father) dfs(v, u);
        }
    }

    int LCA(int x, int y) {
        if(dep[x] < dep[y]) swap(x, y);
        for(int i = m - 1; i >= 0; i --) {
            if(dep[x] - (1 << i) >= dep[y]) x = fa[x][i]; 
        }
        if(x == y) return x;
        for(int i = m - 1; i >= 0; i --) {
            if(fa[x][i] != fa[y][i]) {
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return fa[x][0];
    }

    int len(int x, int y) {
        return dep[x] + dep[y] - 2*dep[LCA(x, y)];
    }

    int find(int u, int k) {
        for(int i = m - 1; i >= 0; i --) {
            if(((k >> i) & 1)) {
                u = fa[u][i];
            }
        }
        if(u == 0) u = root;
        return u;
    }

}lca;

PII d1[N],d2[N],d[N];
int len[N];

void dfs(int u, int fa) {
    d1[u] = d2[u] = {0, u};
    for(auto v : adj[u]) {
        if(fa == v) continue;
        dfs(v, u);
        if(d1[v].first + 1 >= d1[u].first) {
            d2[u] = d1[u];
            d1[u] = d1[v];
            d1[u].first += 1;
        } else if(d1[v].first + 1 > d2[u].first) {
            d2[u] = d1[v];
            d2[u].first += 1;
        }
    }

    len[u] = d1[u].first + d2[u].first;
    d[u] = {d1[u].second, d2[u].second};

    for(auto v : adj[u]) {
        if(v == fa) continue;
        if(len[v] > len[u]) {
            d[u] = d[v];
        }
    }
}


void solve()
{
    int n; cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    lca.init(n,25,1);
    dfs(1, -1);


    // for(int i = 1; i <= n; i ++) {
    //     cout << d1[i].first << " " << d1[i].second << " " << d2[i].first << " " << d2[i].second << endl;
    // }

    // for(int i = 1; i <= n; i ++) {
    //     cout << d[i].first << " " << d[i].second << " " << len[i] << endl;
    // }
    int q; cin >> q;
    while(q --) {
        int u, k; cin >> u >> k;
        int fa = lca.find(u, k);
        // cout << fa << endl;
        cout << max(lca.len(u, d[fa].first), lca.len(u,d[fa].second)) << " ";
    }
    cout << endl;


    for(int i = 1; i <= n; i ++) {
        len[i] = 0;
        d[i] = d1[i] = d2[i] = {0, 0};
        adj[i].clear();
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
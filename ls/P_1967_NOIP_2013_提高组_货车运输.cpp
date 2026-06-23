#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=10007;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int fa[N][20];
int deep[N];

void dfs(int u, int father) {
    deep[u] = deep[father] + 1;
    fa[u][0] = father;
    for(int i = 1; (1 << i) < deep[u]; i ++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    for(auto v : adj[u]) {
        if(v == father) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 19; i >= 0; i --) {
        if(deep[x] - (1 << i) >= deep[y]) {
            x = fa[x][i];
        }
    }
    if(x == y) return x;

    for(int i = 19; i >= 0; i --) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int len(int x, int y) {
    return deep[x] + deep[y] - 2 * deep[lca(x, y)];
}

struct edg{
    int u, v, w;
}e[N];

int W[N];
int f[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = {u, v, w};
    }

    sort(e + 1, e + m + 1,[&](edg a, edg b){
        return a.w > b.w;
    });

    for(int i = 1; i <= n; i ++) f[i] = i;

    for(int i = 1; i <= m; i ++) {
        auto[u, v, w] = e[i];
        if(find(u) == find(v)) continue;
        ++ n;
        f[n] = n;
        u = find(u), v = find(v);
        f[u] = n, f[v] = n;
        adj[n].push_back(u);
        adj[n].push_back(v);
        W[n] = w;
    }

    for(int i = n; i >= 1; i --) {
        if(find(i) == i) dfs(i, 0);
    }

    int q;
    cin >> q;
    W[0] = -1;
    while(q -- ) {
        int u, v; cin >> u >> v;
        int lca_uv = lca(u, v);
        cout << W[lca_uv] <<endl;
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
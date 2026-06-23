#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

constexpr int LOGN = 20;
void solve()
{
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int root, t0; cin >> root >> t0;

    vector<int> deep(n + 1);
    vector<vector<int>> fa(n + 1, vector<int> (LOGN + 1));
    vector<vector<int>> bfn(n + 1);
    auto dfs = [&](auto self, int u, int father) -> void {
        deep[u] = deep[father] + 1;
        bfn[deep[u]].emplace_back(u);
        fa[u][0] = father;
        for (int i = 1; i <= LOGN; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u]) {
            if (v == father) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, root, 0);

    auto lca = [&](int x, int y) -> int {
        if (deep[x] < deep[y]) swap(x, y);
        for (int i = LOGN; i >= 0; i--) {
            if (deep[x] - (1 << i) >= deep[y]) x = fa[x][i];
        }
        if (x == y) return x;
        for (int i = LOGN; i >= 0; i--) {
            if (fa[x][i] != fa[y][i]) {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
    };
    auto dis = [&](int x, int y) -> int {
        return deep[x] + deep[y] - 2 * deep[lca(x, y)] + 1;
    };
    vector<array<int, 3>> tr(n + 1);
    tr[0] = {root, root, 1};
    vector<int> vis(n + 1);
    
    for (int i = 1; i <= n; i++) {
        tr[i] = tr[i - 1];
        for (auto u : bfn[i]) {
            auto [l, r, len] = tr[i];
            if (dis(l, u) < dis(r, u)) swap(l, r);
            if (dis(l, u) > len) {
                tr[i] = {l, u, dis(l, u)};
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        tr[i - 1] = tr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << tr[i][0] << ' ' << tr[i][1] << ' ';
        cout << tr[i][2] << '\n';
    }
    auto check = [&](int t, int k) -> bool {
        int len = tr[min(n - 1, t)][2];

        return len <= 1 + (t - t0) * k;
    };
    cout << check(4, 1) << ' ';
    for (int i = 1; i <= n; i++) {
        int l = t0, r = 2 * n;
        while (l < r) {
            int m = l + r >> 1;
            if (check(m, i)) r = m;
            else l = m + 1;
        }
        cout << l << ' ';
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
}
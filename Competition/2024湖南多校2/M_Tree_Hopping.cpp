#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    int n;cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<int> deep(n + 1);
    vector<vector<int>> fa(n + 1, vector<int>(30)); 
    auto dfs = [&](auto self, int u, int father) ->void{
        deep[u] = deep[father] + 1;
        fa[u][0] = father;
        for (int i = 1; i < 30; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u]) {
            if (v == father) continue;
            self(self, v, u);
        }
    };
    dfs(dfs, p[0], 0);
    auto lca = [&](int x, int y) ->int {
        if (deep[x] < deep[y]) swap(x, y);
        for (int i = 29; i >= 0; i--) {
            if (deep[x] - (1 << i) >= deep[y]) x = fa[x][i];
        }
        if (x == y) return x;
        for (int i = 29; i>= 0; i--)
            if (fa[x][i] != fa[y][i]) {
                x = fa[x][i], y = fa[y][i];
            }
        return fa[x][0];
    };
    bool ok = true;
    for (int i = 1; i < n; i++) {
        int f = lca(p[i - 1], p[i]);
        int dis = deep[p[i - 1]] + deep[p[i]] - 2 * deep[f];
        // cout << dis << ' ';
        if (dis > 3) ok = false;
    }
    cout << ok << '\n';





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
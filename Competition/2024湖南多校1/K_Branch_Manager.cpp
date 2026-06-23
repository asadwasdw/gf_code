#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

const int LOGN = 30;

void solve()
{
    int n, m;cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    vector<int> in(n + 1), out(n + 1);
    vector<int> deep(n + 1);
    vector<vector<int>> fa(n + 1, vector<int>(LOGN + 1));
    int idx = 0;
    vector<int> mp(n + 1);
    auto dfs = [&](auto self, int u, int father) ->void {
        deep[u] = deep[father] + 1;
        fa[u][0] = father;
        for (int i = 1; (1 << i) <= deep[u]; i++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        in[u] = ++idx;
        mp[idx] = u;
        for (auto v : g[u]) {
            if (v == father)continue;
            self(self, v, u);
        }
        out[u] = idx;
    };
    dfs(dfs, 1, 0);
    auto lca = [&](int x, int y) ->int {
        if (deep[x] < deep[y]) swap(x, y);
        for (int i = LOGN; i >= 0; i--) {
            if (deep[x] - (1 << i) >= deep[y])
                x = fa[x][i];
        }
        if (x == y)return x;
        for (int i = LOGN; i >= 0; i--) {
            if (fa[x][i] != fa[y][i]) {
                x = fa[x][i], y = fa[y][i];
            }
        }
        return fa[x][0];
    };
    idx = 1;
    int ans = 0;
    while (m--) {
        int x;cin >> x;
        if (lca(x, mp[idx]) == x) {
            ans++;
            continue;
        }
        while(idx <= n && mp[idx] != x) idx++;
        if (idx == n + 1) break;
        else ans++;
    }
    cout << ans << '\n';
    cout << atan((long double)1 / 2e9) <<endl;
    cout << atan((long double)2 / 2e9) <<endl;
    cout << atan((long double)3 / 2e9) <<endl;

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
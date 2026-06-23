#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;
using i64 = long long;
typedef long long ll;

constexpr int P = 998244353;
int n, q;
vector<int> g[N];

struct POUFEN
{
    int sz[N], son[N], fa[N], top[N], dep[N], cnt, dfn[N], qst[N], qed[N];
    ll sum[N], up_sum[N];
    void claer(){
        for(int i=0; i<=n+n; ++i)sz[i] = son[i] = fa[i] = top[i] = dep[i] = cnt = dfn[i] = qst[i] = qed[i] = sum[i] = up_sum[i] = 0;

    }
    void dfs(int u, int far){
        son[u] = 0, fa[u] = far, sz[u] = 1, dep[u] = dep[far] + 1;
        dfn[u] = 0;
        for(auto v : g[u]){
            if(v == far)continue;
            dfs(v, u);
            sz[u] += sz[v];
            if(sz[son[u]] < sz[v])son[u] = v;
        }
    }
    void dfs3(int u){
        qst[u] = cnt + 1;
        for(auto v : g[u]){
            if(v == fa[u] || v == son[u])continue;
            dfn[v] = ++cnt;
        }
        qed[u] = cnt;
        if(son[u])dfs3(son[u]);
    }
    void dfs2(int u, int tp){
        top[u] = tp;
        if(!dfn[u])dfn[u] = ++cnt;
        if(top[u] == u)dfs3(u);
        if(son[u])dfs2(son[u], tp);
        for(auto v : g[u]){
            if(v == fa[u] || v == son[u])continue;
            dfs2(v, v);
        }
    }
    void init(vector<vector<ll>> &f, vector<ll> &f2){
        dfs(1, 0);
        dfs2(1, 1);
        sum[0] = 0;
        for(int i=1; i<=n; ++i)sum[dfn[i]] = (f[i][0] + f[i][1]) % P, up_sum[i] = f2[i];
        for(int i=1; i<=cnt; ++i)sum[i] = (sum[i] + sum[i-1]) % P;
    }
    ll query(int u, int v){
        auto qry = [&](int l, int r){
            if(l > r)return 0ll;
            return (sum[r] - sum[l-1] + P) % P;
        };
        ll res = 0;
        while(top[u] != top[v]){
            if(dep[top[u]] < dep[top[v]])swap(u, v);
            res += qry(qst[top[u]], qed[u]);
            res %= P;
            if(son[u])res += qry(dfn[son[u]], dfn[son[u]]);
            if(fa[top[u]])res -= qry(dfn[top[u]], dfn[top[u]]);
            res %= P;
            res = (res + P) % P;
            u = fa[top[u]];
        }
        if(dep[u] > dep[v])swap(u, v);
        if(son[v])res += qry(dfn[son[v]], dfn[son[v]]);
        res += qry(qst[u], qed[v]);
        res %= P;
        res = (res + up_sum[u]) % P;
        return (res + P) % P;
    }   
}sp;


void solve() {
    std::cin >> n >> q;
    for(int i=1; i<=n; ++i)g[i].clear();
    for (int i = 2; i <= n; i++) {
        int fa; cin >> fa;
        g[fa].push_back(i);
        g[i].push_back(fa);
    }
    vector dp(n + 1, vector<i64> (2));
    auto dfs1 = [&](auto self, int u, int fa) -> void {
        dp[u][1] = 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
            dp[u][0] += dp[v][0] + dp[v][1];
            dp[u][1] *= (dp[v][1] + 1);
            dp[u][0] %= P;
            dp[u][1] %= P;
        }
    };
    dfs1(dfs1, 1, 0);
    vector<i64> dp1(n + 1);
    auto qpow = [&](i64 a, i64 b) -> i64 {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            b >>= 1;
            a = a * a % P;
        }
        return res;
    };
    auto dfs2 = [&](auto self, int u, int fa, i64 val1, i64 val2) -> void {
        dp1[u] = val1 + val2;
        for (auto v : g[u]) {
            if (v == fa) continue;
            i64 nval1 = val1 + dp[u][0] - (dp[v][0] + dp[v][1]) + val2;
            nval1 = (nval1 % P + P) % P;
            i64 nval2 = dp[u][1] * qpow(dp[v][1] + 1, P - 2) % P * (val2 + 1) % P;
            self(self, v, u, nval1, nval2);
        }
    };
    dfs2(dfs2, 1, 0, 0, 0);
    // for (int i = 1; i <= n; i++) { 
    sp.claer();
    sp.init(dp, dp1);
    // cout << dp[1][0] + dp[1][1] << endl;
    for(int i=1; i<=q; ++i){
        int u,v;
        cin >> u >> v;
        cout << (dp[1][0] + dp[1][1] - sp.query(u, v)  + P) % P << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
// #define int long long 
typedef unsigned long long ull;
typedef long long ll;
typedef double db;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const int N = 1e6 + 50, LOGN = 30;
const ll mod = 998244353, inf = 1e9;

struct DSU {
    vector<int> fa, sz;

    DSU() {}
    DSU(int n) {
        init(n);
    } 

    void init(int n){
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        sz.assign(n, 1);
    }

    inline int find(int x){
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }

    inline bool merge(int x, int y) {
        // x = find(x), y = find(y);
        //if(x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }

    inline bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sz[find(x)];
    }
};

inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
vector<int> g[N];

int fa[N], deep[N];
inline void dfs(int u, int p){
    fa[u] = p;
    deep[u] = deep[p] + 1;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}
int mp[N];

inline void solve(){
    int n;cin >> n;
    vector<array<int, 2>> op(n);
    for (int i = 1; i < n; i++) {
        cin >> op[i][0] >> op[i][1];
    }
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    dfs(1, 1);
    ll ans = 1;
    DSU dsu(n + 1);
    for (int i = 1; i < n; i++) {
        int a = op[i][0], b = op[i][1];
        a = dsu.find(a); b = dsu.find(b);
        if (deep[a] < deep[b]) swap(a, b);
        if (dsu.same(b, fa[a])) {
            if (!mp[dsu.sz[a]]) mp[dsu.sz[a]] = qpow(dsu.sz[a], mod - 2);
            if (!mp[dsu.sz[b]
            
            
            
            ]) mp[dsu.sz[b]] = qpow(dsu.sz[b], mod - 2);
            ans = ans * mp[dsu.sz[a]] % mod * mp[dsu.sz[b]] % mod;
            dsu.merge(b, a);
        }else {
            ans = 0;
            break;
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}

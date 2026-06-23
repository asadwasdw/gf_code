#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N = 3e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;
typedef long long ll;

vector<vector<int>>adj(N);
struct gfLCA {
    int n, now, cur, tot;
    vector<array<int, 20>> fa, rev; 
    vector<int> deep; 
    vector<int> cnt; 
    vector<int> dfn, fdfn, L, R, FL;
    vector<int> lg, depth; // RMQ

    void clear() {
        tot = now = 0;

        fa.resize(n + 10); // 重新设置向量的大小为 n
        fill(fa.begin(), fa.end(), array<int, 20>{0}); // 将所有元素初始化为 0

        rev.resize(2 * n + 10); 
        fill(rev.begin(), rev.end(), array<int, 20>{0}); 

        deep.resize(n + 10, 0);
        cnt.resize(n + 10, 0);
        L.resize(n + 10, 0);
        FL.resize(n + 10, 0);
        R.resize(n + 10, 0);

        fdfn.resize(n + 10, 0);

        dfn.resize(2 * n + 10, 0);
        lg.resize(2 * n + 10, 0);
        depth.resize(2 * n + 10, 0);
    }

    int dfs(int u, int father) {
        cnt[u] = 1;
        L[u] = ++now;
        FL[L[u]] = u;

        dfn[++tot] = L[u];
        fdfn[u] = tot; 

        depth[tot] = deep[u] = deep[father] + 1;
        fa[u][0] = father;
        for(int i = 1; (1 << i) <= deep[u]; i ++) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for(int v : adj[u]) {
            if(v == father) continue;
            cnt[u] += dfs(v, u);

            dfn[++tot] = L[u];
            depth[tot] = deep[father] + 1;
        }
        R[u] = now;
        return cnt[u];
    }

    void init(int _n, int root) {
        n = _n;
        clear();
        dfs(root, 0);
        for(int i = 2; i <= tot + 1; i ++) lg[i] = lg[i >> 1] + 1;
        for(int i = 1; i <= tot; i ++) rev[i][0] = dfn[i];
        for(int j = 1; j <= lg[tot]; j ++) {
            for(int i = 1; i + (1 << j) - 1 <= tot; i ++) {
                rev[i][j] = min(rev[i][j - 1], rev[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int LCA(int x, int y) {
        if(deep[x] < deep[y]) swap(x, y);
        for(int i = 19; i >= 0; i --) {
            if(deep[x] - (1 << i) >= deep[y])
                x = fa[x][i];
        }
        if(x == y) return x;
        for(int i = 19; i >= 0; i --) {
            if(fa[x][i] != fa[y][i]){
                x = fa[x][i];
                y = fa[y][i];
            }
        }
        return fa[x][0];
    }

    int RMQ(int l, int r) {
        l = fdfn[l], r = fdfn[r];
        if(l > r) swap(l, r);
        int k = lg[r - l + 1]; 
        int root = min(rev[l][k], rev[r - (1 << k) + 1][k]);
        root = FL[root];
        return root;
    }

    int len(int x, int y) {
        return deep[x] + deep[y] - 2 * deep[LCA(x, y)];
    }

    void debug() {
        // for(int i = 1; i <= n; i ++) cout << fa[i][0] << " \n"[i == n]; 
        // for(int i = 1; i <= n; i ++)   cout << L[i] << " \n"[i == n];
        for(int i = 1; i <= tot; i ++) cout << dfn[i] << " \n"[i == tot];
        for(int i = 1; i <= tot; i ++) cout << rev[i][1] << " \n"[i == tot];
    }

    bool pd_lrx(int x, int l, int r) {
        return len(l, r) == len(l, x) + len(x, r);
    }

    int get_root_son(int x) {
        // 跳到深度为2的节点（根节点0深度为1，其直接子节点深度为2）
        for(int i = 19; i >= 0; i --) {
            if(deep[x] - (1 << i) > 1) { // 保证跳完后深度≥2
                x = fa[x][i];
            }
        }
        return x;
    }



}lca;


void solve() {

    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    lca.init(n, 0);

    ll ans = n + n * (n - 1) / 2;

    for(auto v : adj[0]) {
        ll num = lca.cnt[v];
        ans -= num * (num - 1) / 2 + num;
    }


    int l = 0, r = 0;

    for(int mex = 2; mex <= n; mex ++) {
        int u = mex - 1;
        if(lca.pd_lrx(u, l, r)) {

        } else if(lca.pd_lrx(l, u, r)) {
            l = u;
        } else if(lca.pd_lrx(r, l, u)) {
            r = u;
        } else {
            break;
        }
        ll sizl = (l == 0 ? n - lca.cnt[lca.get_root_son(r)] : lca.cnt[l]);
        ll sizr = (r == 0 ? n - lca.cnt[lca.get_root_son(l)] : lca.cnt[r]);
        ans += sizl * sizr;
    }


    cout << ans << endl;
}

signed main() {

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
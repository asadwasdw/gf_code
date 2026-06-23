#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10, M = 1e5;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);
vector<vector<PII>> v(N);
void init(int n) { // 预处理lcm<=n的所有数队 n((logn)^2)
    for(ll gcd = 1; gcd <= n; gcd ++) {    
        for(int i = gcd; i <= n; i += gcd) {
            for(int j = gcd; j <= n && i/gcd*j <= n && j <= i; j += gcd) {
                if(__gcd(i, j) == gcd) {
                    ll lcm = i/gcd*j;
                    v[lcm].push_back({j, i}); // (j <= i)
                }
            }
        }
    }
}

struct gfLCA {
    int n, now, cur, tot;
    vector<array<int, 20>> fa, rev; 
    vector<int> deep; 
    vector<int> dfn, fdfn, L, R, FL;
    vector<int> lg, depth; // RMQ

    void clear() {
        tot = now = 0;

        fa.resize(n + 10); // 重新设置向量的大小为 n
        fill(fa.begin(), fa.end(), array<int, 20>{0}); // 将所有元素初始化为 0

        rev.resize(2 * n + 10); 
        fill(rev.begin(), rev.end(), array<int, 20>{0}); 

        deep.resize(n + 10, 0);
        L.resize(n + 10, 0);
        FL.resize(n + 10, 0);
        R.resize(n + 10, 0);

        fdfn.resize(n + 10, 0);

        dfn.resize(2 * n + 10, 0);
        lg.resize(2 * n + 10, 0);
        depth.resize(2 * n + 10, 0);
    }

    void dfs(int u, int father) {
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
            dfs(v, u);
            dfn[++tot] = L[u];
            depth[tot] = deep[father] + 1;
        }
        R[u] = now;
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
}lca;

struct gfBIT {
    int n;
    vector<int> tr;

    void clear() {
        tr.clear();
        tr.resize(n + 10, 0); 
    }

    void init(int _n) {
        n = _n;
        clear();
    }

    int lowbit(int x) {
        return (x) & (-x);
    }

    void update(int x, int d) {
        for(int i = x; i <= n; i += lowbit(i)) tr[i] += d;
    }

    ll sum(int x) {
        ll ans = 0;
        for(int i = x; i > 0; i -= lowbit(i)) ans += tr[i];
        return ans;
    }

    ll get(int l, int r) {
        return sum(r) - sum(max(0,l - 1));
    }

    void debug() {
        cout << n << endl;
        for(int i = 1; i <= n; i ++) {
            cout << get(i, i) << " \n"[i == n];
        }
    }
}bit;


void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) adj[i].clear();
    for(int i = 1; i < n; i ++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    lca.init(n, 1);
    bit.init(n + 1);

    int q; cin >> q;
    vector<int> ans(q + 1);
    vector<vector<PII>> query(M + 1);
    for(int i = 1; i <= q; i ++) {
        int x, y; cin >> x >> y;
        query[y].push_back({x, i});
    }

    for(int i = 1; i <= M; i ++) {
        for(auto [x, y] : v[i]) {
            if(y > n) continue;
            int t = 1;
            if(x != y) t ++;
            // int root = lca.LCA(x, y);
            int root2 = lca.RMQ(x, y);
            bit.update(lca.L[root2], t);
        }

        for(auto [root, id] : query[i]) {
            ans[id] = bit.get(lca.L[root], lca.R[root]);
        }
    }
    for(int i = 1; i <= q; i ++) cout << ans[i] << " \n"[i == q];
}


signed main()
{
    init(1e5+1);
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
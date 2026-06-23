#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
vector<int> g[N];
int st[N];

int dep[N], top[N], sz[N], son[N], cnt, dfn[N], rnk[N], fa[N];

void dfs(int u, int far){
    fa[u] = far, son[u] = -1, sz[u] = 1;
    for(auto v : g[u]){
        if(v == far)continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];
        if(son[u] == -1 || sz[son[u]] < sz[v])son[u] = v;
    }
}
ll val[N], mi[N], val2[N];
void dfs2(int u, int tp){
    top[u] = tp, dfn[u] = ++cnt, rnk[cnt] = u, val[u] = -dep[u], val2[u] = dep[u];
    if(st[u])mi[u] = 0;
    else mi[u] = INF;
    if(son[u] == -1)return;
    dfs2(son[u], tp), mi[u] = min(mi[u], mi[son[u]]+1);
    for(auto v : g[u]){
        if(v == son[u] || v == fa[u])continue;
        dfs2(v, v);
        mi[u] = min(mi[u], mi[v]+1);
    }
}

void dfs3(int u, ll pre){
    val[u] += 1ll * min(mi[u], pre) * 3;
    val2[u] += 1ll * min(mi[u], pre) * 3;
    for(auto v : g[u]){
        if(v == fa[u])continue;
        dfs3(v, min(pre, mi[u])+1);
    }
}

ll tr[N << 2], tr2[N << 2];
#define ls k<<1
#define rs k<<1|1
void pushup(int k){
    tr[k] = min(tr[ls], tr[rs]);
    tr2[k] = min(tr2[ls], tr2[rs]);
}
void build(int k, int l, int r){
    tr[k] = INF;
    if(l == r){
        tr[k] = val[rnk[l]];
        tr2[k] = val2[rnk[l]];
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    pushup(k);
}

ll query(int k, int l, int r, int ql, int qr, int op){
    if(l == ql && r == qr)return op == 1 ? tr[k] : tr2[k];
    int mid = l + r >> 1;
    if(mid >= qr)return query(ls, l, mid, ql, qr, op);
    else if(mid < ql)return query(rs, mid+1, r, ql, qr, op);
    else return min(query(ls, l, mid, ql, mid, op), query(rs, mid+1, r, mid+1, qr, op));
}

int lca(int a, int b){
    while(top[a] != top[b]){
        if(dep[top[a]] > dep[top[b]])a = fa[top[a]];
        else b = fa[top[b]];
    }
    return dep[a] > dep[b] ? b : a;
}

ll query_tree(int a, int b, int op){
    ll res = INF;
    while(top[a] != top[b]){
        if(dep[top[a]] < dep[top[b]])swap(a, b);
        res = min(res, query(1, 1, n, dfn[top[a]], dfn[a], op));
        a = fa[top[a]];
    }
    if(dep[a] < dep[b])swap(a, b);
    res = min(res, query(1, 1, n, dfn[b], dfn[a], op));
    return res;
}

void solve()
{
    cin >> n >> m;
    for(int i=1; i<n; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1; i<=m; ++i){
        int x;cin >> x;
        st[x] = 1;
    }
    dfs(1, 0);
    dfs2(1, 1);
    dfs3(1, mi[1]);
    build(1, 1, n);
    int q;cin >> q;
    while(q--){
        int u, v;
        cin >> u >> v;
        if(u == v){
            cout << 0 << endl;continue;
        }
        int lc = lca(u, v);
        int dist = dep[u] + dep[v] - dep[lc] * 2;
        ll res = dist * 2;
        res = min(res, 1ll * mi[u] * 3 + dist);
        res = min(res, 1ll * query_tree(u, lc, 1) + dep[u] + dist);
        res = min(res, 1ll * query_tree(lc, v, 2) - dep[lc] + dep[v] - dep[lc] + (dep[u] - dep[lc]) * 2);
        cout << res << endl;
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
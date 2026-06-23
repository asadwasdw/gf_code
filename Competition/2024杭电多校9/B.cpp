#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);
int p[N];
int L[N], R[N], fL[N], fR[N];
int now = 0;
void dfs(int u,int fa) {
    L[u] = ++now;

    for(auto v : adj[u]) {
        if(fa == v) continue;
        dfs(v, u);
    }

    R[u] = ++now;
}

struct gfseg { // 区间最值
    int a[N], _n;
    struct Node {
        int l, r;
        int max, min;
    }tr[N];

    void pushup(int u) {
        tr[u].max = max(tr[u << 1].max, tr[u << 1 | 1].max);
        tr[u].min = min(tr[u << 1].min, tr[u << 1 | 1].min);
    }

    void build(int u, int l, int r) {
        // cout << u << " " << l << " " << r << endl;
        if(l == r) {
            tr[u] = {l, r, a[l], a[r]};
            // cout << l << " " << a[l] << endl;
            return;
        }
        int mid = l + r >> 1;
        tr[u] = {l, r, -INF, INF};
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void init(vector<int> _a) {
        _n = _a.size();
        for(int i = 1; i <= _n; i ++) {
            a[i] = _a[i - 1];
        } 
        build(1, 1, _n);
    }

    void modify(int u, int x, int y) {
        if(tr[u].l == tr[u].r && tr[u].l == x) {
            tr[u].min = tr[u].max = y;
            return;
        }
        int mid = tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u << 1, x, y);
        if(x >  mid) modify(u << 1 | 1, x, y);
        pushup(u);
    }

    int querymin(int u, int l, int r) {
        // cout << u << " " << l << " " << r << endl;
        if(l <= tr[u].l && tr[u].r <= r) {
            return tr[u].min;
        }

        int res = INF;
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) res = min(querymin(u << 1, l,  r), res);
        if(r >  mid) res = min(querymin(u << 1 | 1, l,  r), res);
        return res;
    }

    int querymax(int u, int l, int r) {
        if(l <= tr[u].l && tr[u].r <= r) {
            return tr[u].max;
        }

        int res = -INF;
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) res = max(querymax(u << 1, l,  r), res);
        if(r >  mid) res = max(querymax(u << 1 | 1, l,  r), res);
        return res;
    }
}dfn, fdfn, sp;

int deep[N], siz[N], son[N], top[N], fa[N], id[N], num, w[N];
void dfs1(int u, int father) {
    deep[u] = deep[father] + 1;
    fa[u] = father;
    siz[u] = 1;
    for(auto v : adj[u]) {
        if(v == father) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(!son[u] || siz[son[u]] < siz[v]) son[u] = v;
    }
}


void dfs2(int u, int topu) {
    // cout << u << " - " << topu << endl;
    id[u] = ++ num;
    w[num] = p[u];
    top[u] = topu;
    if(!son[u]) return;
    dfs2(son[u], topu);

    for(auto v : adj[u]) {
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void update(int x, int y) {
    sp.modify(1, id[x], y);
}

bool check(int x, int y, int cnt, int l, int r) {
    int mn = INF, mx = -INF;
    while(top[x] != top[y]) {
        // cout << x << " " << y << endl;
        if(deep[top[x]] < deep[top[y]]) swap(x, y);
        mn = min(mn, sp.querymin(1, id[top[x]], id[x]));
        mx = max(mx, sp.querymax(1, id[top[x]], id[x]));
        cnt -= abs(id[x] - id[top[x]] + 1);
        x = fa[top[x]];
    }
    // cout << x << " " << y << endl;
    // cout << mn << " " << mx << endl;
    if(deep[x] > deep[y]) swap(x, y);
    mn = min(mn, sp.querymin(1, id[x], id[y]));
    mx = max(mx, sp.querymax(1, id[x], id[y]));
    cnt -= abs(id[y] - id[x] + 1);
    // cout << cnt << " " << mn << " " << mx << endl;
    if(cnt || mn != l || mx != r) return false;
    return true;
}


void solve()
{
    int n; cin >> n;
    
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i < n; i ++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);

    for(int i = 1; i <= n; i ++)  fL[L[i]] = i;
    for(int i = 1; i <= n; i ++)  fR[R[i]] = i;
    dfs1(1, 0); 
    dfs2(1, 1);

    vector<int> T;
    for(int i = 1; i <= n; i ++) T.push_back(L[i]); dfn.init(T);T.clear();
    for(int i = 1; i <= n; i ++) T.push_back(R[i]);fdfn.init(T);T.clear();
    for(int i = 1; i <= n; i ++) T.push_back(w[i]);  sp.init(T);T.clear();

    // for(int i = 1; i <= n; i ++) cout << top[i] << " "; cout << endl;
    // for(int i = 1; i <= n; i ++) cout << son[i] << " "; cout << endl;

    int q; cin >> q;
    while(q --) {
        int op, x, y; cin >> op >> x >> y;
        if(op == 1) {
            if(x == y) continue;
            swap(p[x], p[y]);

            swap(L[x], L[y]);
            fL[L[x]] = x;
            fL[L[y]] = y;
            dfn.modify(1, x, p[x]);
            dfn.modify(1, y, p[y]);

            swap(R[x], R[y]);
            fR[R[x]] = x;
            fR[R[y]] = y;
            fdfn.modify(1, y, p[y]);
            fdfn.modify(1, y, p[y]);

            update(x, p[x]);
            update(y, p[y]);

        } else {
            int u = fL[dfn.querymax(1, x, y)], v = fR[fdfn.querymin(1, x, y)];
            if(u == v) v = fL[dfn.querymin(1, x, y)];
            // cout << u << " " << v << endl;
            if(check(u, v, y - x + 1 ,x, y)) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    // cout << "s" << endl;

    for(int i = 0; i <= 2 * n; i ++) {
        L[i] = R[i] = fL[i] = R[i] = 0;
        deep[i] =  siz[i] = son[i] = top[i] = fa[i] = id[i] = w[i] = p[i] = 0;
    }
    for(int i = 0; i <= n; i ++) adj[i].clear();
    num = 0;
    now = 0;
}


signed main()
{
    freopen("1002.in","r", stdin);
    freopen("1002.out","w", stdout);
    
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
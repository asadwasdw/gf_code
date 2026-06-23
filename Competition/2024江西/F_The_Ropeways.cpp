#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
map<PII, int> mp;
int f[N], f2[N];//f:ans, f2:son-sum
int duan[N];
vector<int> g[N];
int dep[N], top[N], son[N], cnt, sz[N], dfn[N], rk[N];
int fa[N][21];
void dfs(int u, int far){
    fa[u][0] = far, son[u] = -1, sz[u] = 1;
    f2[u] = 1;
    dep[u] = dep[far] + 1;
    for(int i=1; i<21; ++i)fa[u][i] = fa[fa[u][i-1]][i-1];
    for(auto v : g[u]){
        if(v == far)continue;
        dfs(v, u);
        sz[u] += sz[v];
        duan[u] += duan[v];
        if(a[mp[{u, v}]])f[u] += f2[v], duan[u]++;
        else f[u] += f[v], f2[u] += f2[v];
        if(son[u] == -1 || sz[son[u]] < sz[v])son[u] = v;
    }
    // cout << u << ' ' << f[u] << ' ' << f2[u] << endl;
}

void dfs2(int u, int tp){
    top[u] = tp, dfn[u] = ++cnt, rk[cnt] = u;
    if(son[u] == -1)return;
    dfs2(son[u], tp);
    for(auto v : g[u]){
        if(v == son[u] || v == fa[u][0])continue;
        dfs2(v, v);
    }
}

struct node
{
    int l, r;
    int f, g, duan;
    int lzf, lzg, lzd;
}tr[N << 2];
#define ls k<<1
#define rs k<<1|1
void pushup(int k){
    tr[k].f = tr[ls].f + tr[rs].f;
    tr[k].g = tr[ls].g + tr[rs].g;
    tr[k].duan = tr[ls].duan + tr[rs].duan;
}
void build(int k, int l, int r){
    tr[k] = {l, r, 0, 0, 0, 0};
    if(l == r){
        tr[k].f = f[rk[l]];
        tr[k].g = f2[rk[l]];
        tr[k].duan = duan[rk[l]];
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
    pushup(k);
}
void pushdown1(int k, int d){
    tr[k].f += d * (tr[k].r - tr[k].l + 1);
    tr[k].lzf += d;
}
void pushdown2(int k, int d){
    tr[k].g += d * (tr[k].r - tr[k].l + 1);
    tr[k].lzg += d;
}
void pushdown3(int k, int d){
    tr[k].duan += d * (tr[k].r - tr[k].l + 1);
    tr[k].lzd += d;
}
void pushdown(int k){
    if(tr[k].lzf){
        pushdown1(ls, tr[k].lzf);
        pushdown1(rs, tr[k].lzf);
        tr[k].lzf = 0;
    }
    if(tr[k].lzg){
        pushdown2(ls, tr[k].lzg);
        pushdown2(rs, tr[k].lzg);
        tr[k].lzg = 0;
    }
    if(tr[k].lzd){
        pushdown3(ls, tr[k].lzd);
        pushdown3(rs, tr[k].lzd);
        tr[k].lzd = 0;
    }
}

void update(int k, int l, int r, int d, int op){
    if(tr[k].l >= l && tr[k].r <= r){
        if(op == 1)pushdown1(k, d);
        else if(op == 2) pushdown2(k, d);
        else pushdown3(k, d);
        return;
    }
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= l)update(ls, l, r, d, op);
    if(mid < r)update(rs, l, r, d, op);
    pushup(k);
}

node query(int k, int x){
    if(tr[k].l == tr[k].r)return tr[k];
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= x)return query(ls, x);
    return query(rs, x);
}

PII aa[N];

void update(int a, int b, int d, int op){
    while(top[a] != top[b]){
        if(dep[top[a]] < dep[top[b]])swap(a, b);
        update(1, dfn[top[a]], dfn[a], d, op);
        a = fa[top[a]][0];
    }
    if(dep[a] < dep[b])swap(a, b);
    update(1, dfn[b], dfn[a], d, op);
}

void solve()
{
    cin >> n >> m;
    for(int i=1; i<n; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        a[i] = w;
        aa[i] = {u, v};
        mp[{u,v}] = mp[{v,u}] = i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    dfs2(1, 1);
    for(int i=1; i<n; ++i){
        if(fa[aa[i].first][0] != aa[i].second)swap(aa[i].first, aa[i].second);
    }
    build(1, 1, cnt);
    cout << "test" << endl;
    auto get_fa = [&](int x){
        int sum = query(1, dfn[x]).duan;
        for(int i=20; i>=0; --i){
            if(fa[x][i] && query(1, dfn[fa[x][i]]).duan >= sum)x = fa[x][i];
        }
        return x;
    };
    
    // cout << query(1, dfn[3]).duan << ' ' << query(1, dfn[2]).duan << endl;
    // cout << get_fa(3) << endl;
    while(m--){
        int op,x;
        cin >> op >> x;
        if(op == 1){
            auto [u, v] = aa[x];
            node it = query(1, dfn[u]);
            if(a[x]){
                int f1 = get_fa(v);
                update(v, f1, it.f - it.g, 1);
                update(v, f1, it.g, 2);
                if(fa[f1][0]){
                    int f2 = get_fa(fa[f1][0]);
                    update(fa[f1][0], f2, it.g, 2);
                }
                update(1, v, -1, 3);
                
            }
            else{
                int f1 = get_fa(v);
                update(v, f1, -it.f + it.g, 1);
                update(v, f1, -it.g, 2);
                if(fa[f1][0]){
                    int f2 = get_fa(fa[f1][0]);
                    update(fa[f1][0], f2, -it.g, 2);
                }
                update(1, v, 1, 3);
            }
            a[x] ^= 1;
        }
        else{
            x = get_fa(x);
            cout << x << endl;
            node it = query(1, dfn[x]);
            int res = it.f + it.g;
            if(fa[x][0]){
                int f2 = get_fa(fa[x][0]);
                res += query(1, dfn[f2]).g;
            }
            cout << res << endl;
        }
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
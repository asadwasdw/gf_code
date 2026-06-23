#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define ls k<<1
#define rs k<<1|1
//vector<vector<int>>edg(N);

struct node{
    int l,r;
    int val;
    int lz;
}tr[N << 2];

void build(int k, int l, int r){
    tr[k] = {l, r, 0, 0};
    if(l == r)return;
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid+1, r);
}

void pushdown(int k){
    if(tr[k].lz){
        tr[ls].val = tr[rs].val = 0;
        tr[ls].lz = tr[rs].lz = 1;
        tr[k].lz = 0;
    }
}

void add(int k, int x, int d){
    if(tr[k].l == x && tr[k].r == x){
        tr[k].val++;
        return;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= x)add(ls, x, d);
    else add(rs, x, d);
    tr[k].val = (tr[ls].val+tr[rs].val);
}

void modify(int k, int l, int r, int d){
    if(tr[k].l >= l && tr[k].r <= r){
        tr[k].val = 0;
        tr[k].lz = 1;
        return;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    if(mid >= l)modify(ls, l, r, d);
    if(mid < r)modify(rs, l, r, d);
    tr[k].val = (tr[ls].val+tr[rs].val);
}

int query(int k, int ql, int qr){
    if(ql <= tr[k].l && qr >= tr[k].r){
        return tr[k].val;
    }
    pushdown(k);
    int mid = tr[k].l + tr[k].r >> 1;
    int res = 0;
    if(mid >= ql)res = (res+ query(ls, ql, qr));
    if(mid < qr)res = (res+ query(rs, ql, qr));
    return res;
}
int n;
int mxdeep = 0, ans = 0;

vector<int> g[N];
int deep[N];
int dfs1(int u, int fa){
    deep[u] = deep[fa] + 1;
    mxdeep = max(mxdeep, deep[u]);

    auto it = lower_bound(g[u].begin(), g[u].end(), fa);
    if (*it == fa) g[u].erase(it);

    array<int, 2> tmp({deep[u], deep[u]});
    int cnt = 0;
    for (auto v : g[u]) {
        tmp[cnt++] = dfs1(v, u);
    }
    if (g[u].size() > 1 && tmp[0] > tmp[1]) {
        swap(g[u][0], g[u][1]);
    }
    return max(tmp[0], tmp[1]);
};

int dfs2(int u, int fa) {
    array<int, 2> tmp({deep[u], deep[u]});
    int cnt = 0;
    for (auto v : g[u]) {
        tmp[cnt++] = dfs2(v, u);
    }
    add(1, deep[u], 1);

    if (tmp[0] == tmp[1]) return tmp[0];
    if (tmp[0] > tmp[1]) swap(tmp[0], tmp[1]);
    if (1 <= tmp[1] - 2 && tmp[0] < tmp[1] - 1) {
        ans += query(1, 1, tmp[1] - 2);
        modify(1, 1, tmp[1] - 2, 0);
    }
    return tmp[1] - 1;
};
void solve()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= n; i++) {
        deep[i] = mxdeep - deep[i] + 1;
    }
    build(1, 1, mxdeep);
    dfs2(1, 0);
    cout << ans;
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
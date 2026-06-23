#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];
ll qmi(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % c;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

struct Node {
    int l, r;
    ll s;
    ll lazy;
} tr[N << 2];

void eval(Node &root, Node son) {
    int sum = (root.s + son.s) % mod;
    root.s = sum;
}

void pushdown(int u) {
    if(tr[u].lazy) {
        tr[u << 1].lazy = tr[u].lazy;
        tr[u << 1 | 1].lazy = tr[u].lazy;

        tr[u << 1].s = (tr[u << 1].r - tr[u << 1].l + 1) * tr[u].lazy;
        tr[u << 1 | 1].s = (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * tr[u].lazy;
    }

    tr[u].lazy = 0;
}

void pushup(int u) {
    tr[u].s = 0;
    tr[u].lazy = 0;
    eval(tr[u], tr[u << 1]);
    eval(tr[u], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l, r, a[l]};
        return;
    }

    int mid = l + r >> 1;
    tr[u] = {l, r, 0, 0};
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

ll query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
        // cerr << tr[u].l << " " << tr[u].r << " " << tr[u].s << endl;
        return tr[u].s;
    }


    int mid = tr[u].l + tr[u].r >> 1;

    ll res = 0;
    pushdown(u);
    if(l <= mid) res += query(u << 1, l, r);
    if(r >= mid + 1) res += query(u << 1 | 1, l, r);
    pushup(u);
    
    return res % mod;
}

void modify(int u, int l, int r, ll x) {
    if(l <= tr[u].l && tr[u].r <= r) {
        tr[u].lazy = x;
        tr[u].s = (tr[u].r - tr[u].l + 1) * x % mod;
        // cerr << u << " " << tr[u].l << " " << tr[u].r << " " << tr[u].s << endl;
        return;
    }

    // cerr << u << " " << tr[u].l << " " << tr[u].r << " " << tr[u].s << endl;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    // cerr << l << " " << mid << endl;
    if(l <= mid) modify(u << 1, l, r, x);
    if(r >= mid + 1) modify(u << 1 | 1, l, r, x);
    pushup(u);
}

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    build(1, 1, n);
    // cerr << "S\n" ;
    // cout << query(1, 4, 6) << endl;
    // modify(1, 4, 6, 30);

    while(m -- ) {
        int l, r;
        cin >> l >> r;
        ll sum = query(1, l, r);
        // cerr << "S" ;
        int len = r - l + 1;
        int flen = qmi(r - l + 1, mod - 2, mod);
        modify(1, l, r, sum * flen % mod);
    }



    for(int i = 1; i <= n; i ++) {
        cout << query(1, i, i) << " ";
    }
    // cerr << "S" ;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(0) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
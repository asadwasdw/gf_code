#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define x first
#define y second
typedef unsigned long long ull;
int n,q;
string s;

ull P[30][N][2];

int p[] = {
	1000000007, 
	1000000009, 
	1000000021, 
	1000000033, 
	1000000087
};

ull p2[N][2] ;

void init() {
    for(int i = 1; i <= 26; i ++) {
        for(int j = 0; j < N; j ++) {
            for(int k = 0; k < 1; k ++) {
                if(j == 0) P[i][j][k] = 0;
                else P[i][j][k] = P[i][j - 1][k] * p[k] + i;
            }
        }
    }

    for(int i = 0; i < N; i ++) {
        for(int k = 0; k < 1; k ++) {
            if(i == 0) p2[i][k] = 1;
            else p2[i][k] = p2[i - 1][k] * p[k];
        }
    }
}

struct T
{
    ull h1,h2,pw;
};

struct node {
    int l, r;
    T h[2];
    int lazy = 0;

    node(){
        for(int i = 0; i < 1; i++) {
            h[i] = {0,0,0};
        }
        lazy = 0;
    };

    node(int c, int size, int _l, int _r) {
        for(int i = 0; i < 1; i++) {
            h[i] = {P[c][size][i], P[c][size][i], p2[size][i]};
        }
        lazy = 0;
        l = _l, r = _r;
    }
}tr[N * 4];

void merge(node &root, node &le, node &ri) {// 哈希合并
    for(int i = 0; i < 1; i++) {
        root.h[i].h1 = le.h[i].h1 * ri.h[i].pw + ri.h[i].h1;
        root.h[i].h2 = le.h[i].h2 + ri.h[i].h2 * le.h[i].pw;
        root.h[i].pw = le.h[i].pw * ri.h[i].pw;
    }
}

void pushup(int u) {
    merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void pushdown(int u) {
    if(tr[u].lazy && tr[u].l != tr[u].r) {

        tr[u << 1 | 1] = node(tr[u].lazy, tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1, tr[u << 1 | 1].l, tr[u << 1 | 1].r);
        tr[u << 1 ] = node(tr[u].lazy, tr[u << 1].r - tr[u << 1].l + 1, tr[u << 1].l, tr[u << 1].r);
        tr[u << 1].lazy = tr[u].lazy;
        tr[u << 1 | 1].lazy = tr[u].lazy;
    }
    tr[u].lazy = 0;
}

void build(int u, int l, int r) {
    tr[u] = node(s[r] - 'a' + 1, 1, l ,r);
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void update(int u,int x, int c) {
    if(x == tr[u].l && x == tr[u].r) {
        tr[u] = node(c,1,tr[u].l,tr[u].r);
        return ;
    }

    int mid = (tr[u].l + tr[u].r) >> 1;
    if(x <= mid) update(u << 1, x, c);
    if(x >= mid + 1) update(u << 1 | 1, x, c);
    pushup(u);
}

void modify(int u, int l, int r, int c) {
    // cout << tr[u].l << " " << tr[u].r << endl;
    if(l <= tr[u].l &&  tr[u].r <= r) {
        // cout << tr[u].l << " " << tr[u].r << endl;
        tr[u] = node(c, tr[u].r - tr[u].l + 1, tr[u].l, tr[u].r);
        tr[u].lazy = c;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    pushdown(u);
    if(l <= mid) modify(u << 1, l, r, c);
    if(r >= mid + 1) modify(u << 1 | 1, l , r, c);
    pushup(u);
}

node query(int u, int l, int r, int L, int R) {

    pushdown(u);
    if(L > R) {
        return tr[0];
    }

    if(L <= l && r <= R) {
        return tr[u];
    }

    int mid = (l + r) >> 1;
    if(R <= mid) return query(u << 1,l ,mid, L, R);
    if(L >= mid + 1) return query(u << 1 | 1, mid + 1, r, L, R);

    node res;
    node le = query(u << 1, l, mid, L, R);
    node ri = query(u << 1 | 1, mid + 1, r, L, R);
    merge(res, le, ri);
    return res;
}


bool check(int l1, int r1, int l2, int r2) {
    node l = query(1, 1, n, l1, r1);
    node r = query(1, 1, n, l2, r2);

    int flag = 1;
    for(int i = 0; i < 1; i++) {
        // cout << l.h[i].h1 << " " << r.h[i].h2 << endl;
        flag &= l.h[i].h1 == r.h[i].h2;//正反哈希相同，为回文串
    } 
    return flag;
}


void solve()
{
    tr[0] = node();
    cin >> n >> q >> s;
    s = " " + s;
    build(1, 1, n);

    while(q--) {
        int op;
        cin >> op;
        int l, r;
        cin >> l >> r;
        if(op == 2) {
            char t;
            cin >> t;
            int c = t - 'a' + 1;
            modify(1,l,r,c);
            // for(int i = l; i <= r; i ++) update(1,i,c);
            continue;
        }

        if(l == r) {
            cout << "YES\n";
            continue;
        }

        int rmid, lmid;

        if((r - l + 1) % 2) {
            lmid = (l + r) / 2 - 1;
            rmid = lmid + 2;
        }
        else {
            lmid = (l + r) / 2;
            rmid = lmid + 1;
        }
        int L = 0, R = (r - l + 1) / 2;

        while(L < R) {
            int mid = (L + R + 1) >> 1;
            int ll = max(l, lmid - mid + 1), rr = min(rmid + mid - 1, r);
            if(check(ll, lmid, rmid, rr)) L = mid;
            else R = mid - 1;
        }
        // cout << L << " " << R << " " << lmid << " " << rmid<< endl;
        lmid = lmid - L - 1;
        rmid = rmid + R + 1;
        
        // cout << l << " " << lmid << " " << rmid << " " << r << endl;
        if(check(l, lmid, rmid, r)) cout << "YES\n";
        else cout << "NO\n";

    }
}



signed main()
{
    init();
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
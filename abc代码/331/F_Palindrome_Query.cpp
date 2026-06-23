#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define x first
#define y second
typedef unsigned long long ull;
int n,q;
string s;

int p[] = {
	1000000007, 
	1000000009, 
	1000000021, 
	1000000033, 
	1000000087
};

struct T
{
    ull h1,h2,pw;
};

struct node {
    T h[5];
    node() {
        for(int i = 0; i < 5; i++) {
            h[i] = {0, 0, 1};
        }
    }

    node(char c) {
        for(int i = 0; i < 5; i++) {
            h[i] = {(ull)c, (ull)c, (ull)p[i]};
        }
    }
}tr[N * 4];

void merge(node &root, node &le, node &ri) {
    for(int i = 0; i < 5; i++) {
        root.h[i].h1 = le.h[i].h1 * le.h[i].pw + ri.h[i].h1;
        root.h[i].h2 = le.h[i].h2 + ri.h[i].h2 * ri.h[i].pw;
        root.h[i].pw = le.h[i].pw * ri.h[i].pw;
    }
}

void pushup(int u) {
    merge(tr[u], tr[u << 1], tr[u << 1 | 1]);
}


void build(int u, int l, int r) {
    tr[u] = node(s[r]);
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void update(int u, int l, int r, int x, char c) {
    if(x == l && x == r) {
        tr[u] = node(c);
        return ;
    }

    int mid = (l + r) >> 1;
    if(x <= mid) update(u << 1, l, mid, x, c);
    if(x >= mid + 1) update(u << 1 | 1, mid + 1, r, x, c);
    pushup(u);
}

node query(int u, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return tr[u];
    }

    int mid = (l + r) >> 1;
    if(R <= mid) return query(u << 1,l ,mid, L, R);
    if(L >= mid + 1) return query(u << 1 | 1, mid + 1, r, L, R);

    node res;
    node le = query(u << 1, l, mid, L, R);
    node ri = query(u << 1, mid + 1, r, L, R);
    merge(res, le, ri);
    return res;
}


void solve()
{
    cin >> n >> q >> s;
    s = " " + s;
    build(1, 1, n);
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x;
            char c;
            cin >> x >> c;
            update(1, 1, n, x, c);
        }
        else {
            int l, r;
            cin >> l >> r;
            node res = query(1, 1, n, l, r);
            int flag = 1;
            for(int i = 0; i < 5; i++) {
                flag &= res.h[i].h1 == res.h[i].h2;
            }
            cout << (flag ? "Yes\n" : "No\n");
        }

    }



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
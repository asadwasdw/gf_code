#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


int n, q;
char S[N << 2];

struct Node {
    int l, r;
    int len;
    int lmx, rmx;
    char lc, rc;
    int mx;

    void print() {
        cout << l << " " << r << " " << lmx << " " << rmx << " " << mx << endl;
    }
}tr[N << 2];    



void eval(Node &root, Node lson, Node rson) {
    root = {0,0,0,0,0,0,0,0};
    // if(lson.l == 1 && lson.r == 2 && rson.l == 3 && rson.r == 3) {
    //     cout << lson.rc << " " << rson.lc << endl;
    //     cout << lson.rmx << " " << rson.lmx << endl;
    // }
    if(lson.rc == rson.lc) root.mx = lson.rmx + rson.lmx;
    
    if(lson.lmx == lson.len && lson.lc == rson.lc) {
        root.lmx = lson.len + rson.lmx;
    } else {
        root.lmx = lson.lmx;
    }

    if(rson.rmx == rson.len && rson.rc == lson.rc) {
        root.rmx = rson.len + lson.rmx;
    } else {
        root.rmx = rson.rmx;
    }

    root.lc = lson.lc;
    root.rc = rson.rc;
    root.l = lson.l;
    root.r = rson.r;
    root.mx = max({root.mx, root.lmx, root.rmx, lson.mx, rson.mx});
    root.len = root.r - root.l + 1;

    // if(lson.l == 1 && lson.r == 2 && rson.l == 3 && rson.r == 3) {
    //     root.print();
    // }
}

void pushup(int t) {
    Node lson = tr[t << 1], rson = tr[t << 1 | 1];
    Node &root = tr[t];

    eval(tr[t], tr[t << 1], tr[t << 1 | 1]);
}

void build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l, r, 1, 1, 1, S[l], S[r], 1};
        return;
    }

    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int k, char x) {
    if(tr[u].l == k && tr[u].r == k) {
        tr[u].lc = tr[u].rc = x;
        return;
    }

    int mid = tr[u].l + tr[u].r >> 1;

    if(k <= mid) modify(u << 1, k, x);
    if(k >= mid + 1) modify(u << 1 | 1, k, x);
    pushup(u);
}

Node query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
        return tr[u];
    }

    int mid = tr[u].l + tr[u].r >> 1;
    Node lson = {0,0,0,0,0,0,0};
    Node rson = {0,0,0,0,0,0,0};
    Node root = {0,0,0,0,0,0,0};
    
    if(l <= mid) lson = query(u << 1, l, r);
    if(r >= mid + 1) rson = query(u << 1 | 1, l, r);

    eval(root, lson, rson);

    return root;
}

void debug(int u) {
    cout << u << " ";
    tr[u].print();

    if(tr[u].l == tr[u].r) return;
    debug(u << 1);
    debug(u << 1 | 1);

}


void solve()
{
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> S[i];
    }

    build(1, 1, n);
    // for(int i = 1; i <= 3; i ++) {
    //     cout << i << " " << tr[i].l << " " << tr[i].r << " " << tr[i].mx << " " 
    //     << tr[i].lmx << " " << tr[i].rmx << endl;
    // }

    while(q --) {
        int op, l, r, k;
        char c;
        cin >> op;
        if(op == 1) {
            cin >> k >> c;
            modify(1, k, c);

            // debug(1);




        } else {
            cin >> l >> r;
            cout << query(1, l, r).mx << endl;
        }
    }

    // cout << "S" << endl;
    







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
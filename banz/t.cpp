#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
const int MAXN = 1010 * 4;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m;
int js(int x1, int y1, int x2, int y2) {
    return 1;
    int sum = (x2 - x1 + 1) * (y2 - y1 + 1);

    bool is1 = (x1 + y1) % 2;
    bool is2 = (x2 + y2) % 2;
    if(is1 && is2) return (sum + 1)/2;
    return sum / 2;
}

struct node_y {
    int l, r;
    int odd, even;
    int sum;
    int la;
};

struct tree_y {
    #define lson tree[u << 1]
    #define rson tree[u << 1 | 1]
    #define root tree[u]
    node_y tree[MAXN];

    void pushup(int u) {
        root.odd = rson.odd + lson.odd;
        root.even = rson.even + lson.even;
        root.sum = lson.sum + rson.sum;
    }

    void pushdown(int u) {
        if(root.la) {
            swap(lson.odd, lson.even);
            swap(rson.odd, rson.even);
            lson.la ^= 1;
            rson.la ^= 1;
        }
        root.la = 0;
    }

    int build(int u, int l, int r,int x, int y) {
        root.l = l; root.r = r;
        // cout << u << " " << l << " " << r << endl;

        if(l == r) {
            root.even = root.sum = js(x,l,y,r);
            return;
        }
        
        int mid = l + r >> 1;
        if(l <= mid) build(u << 1, l, mid, x, y);
        if(r >= mid + 1) build(u << 1 | 1, mid + 1, r, x, y);
        pushup(u);
        return root.odd;
    }

    void modify(int u, int l, int r) {
        
        if(l <= root.l && root.r <= r) {
            swap(root.even, root.odd);
            root.la ^= 1;
            return;
        }
        pushdown(u);
        int mid = root.l + root.r >> 1;
        if(l <= mid) modify(u << 1, l, r);
        if(r >= mid + 1) modify(u << 1 | 1, l, r);
        pushup(u);
        // cout << root.l << " " << root.r << " " << root.odd << endl;
    }

    int query(int u, int l, int r) {
        // cout << u << " " << root.l << " " << root.r << endl;
        if(l <= root.l && root.r <= r) {
            return root.odd;
        }
        int sum = 0;
        int mid = root.l + root.r >> 1;
        pushdown(u);
        if(l <= mid) sum += query(u << 1, l, r);
        if(r >= mid + 1) sum += query(u << 1 | 1, l, r);
        return sum;
    }

    #undef root
    #undef lson
    #undef rson
};

// tree_y tr;

struct node_x {
    int up, down;
    int la;
    tree_y tr;
};

struct tree_y {
    node_x tree[MAXN];
    #define lson tree[u << 1]
    #define rson tree[u << 1 | 1]
    #define root tree[u]

    void pushdown(int u) {
        if(root.la) {
            
        }
    }

    void build(int u, int up, int down) {
        root.up = up; root.down = down;
        root.num = root.tr.build(1,1,n);
        if(up == down) {
            return;
        }
    }
    
};


void solve()
{
    
    cin >> n >> m;
    tr.build(1,1,n,1,1);
    while(m --) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1) tr.modify(1, l, r);
        else cout << tr.query(1, l, r) << endl;
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
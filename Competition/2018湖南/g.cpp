#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 1e5+10, INF = 0x3f3f3f3f, mod = 1e9+7;

struct node
{
    #define ls k<<1
    #define rs k<<1|1
    ll val[N << 2], lz[N << 2];
    void pushdown(int k, int l, int r, ll d){
        val[k] += d * (r - l + 1);
        lz[k] += d;
    }
    void pushdown(int k, int l, int r){
        int mid = l + r >> 1;
        if(lz[k]){
            pushdown(ls, l, mid, lz[k]);
            pushdown(rs, mid+1, r, lz[k]);
            lz[k] = 0;
        }
    }
    void update(int k, int l, int r, int ql, int qr){
        if(l >= ql && r <= qr)return pushdown(k, l, r, 1);
        int mid = l + r >> 1;
        pushdown(k, l, r);
        if(mid >= ql)update(ls, l, mid, ql, qr);
        if(mid< qr)update(rs, mid+1, r, ql, qr);
        val[k] = val[ls] + val[rs];
    }
    ll query(int k, int l, int r, int ql, int qr){
        if(l >= ql && r <= qr)return val[k];
        int mid = l + r >> 1;
        pushdown(k, l, r);
        ll res = 0;
        if(mid >= ql)res += query(ls, l, mid, ql, qr);
        if(mid < qr)res += query(rs, mid+1, r, ql, qr);
        return res;
    }
}st[3];


void solve() {
    int n,m;
    while(cin >> n >> m){
        for(int i=0; i<3; ++i)for(int j=0; j<=n*4; ++j)st[i].val[j] = st[i].lz[j] = 0;
        while(m--){
            int op,l,r;
            cin >> op >> l >> r;
            if(op == 1){
                if(r - l >= 2)st[2].update(1, 1, n, l+2, r);
                if(r - l >= 1)st[1].update(1, 1, n, l+1, r);
                st[0].update(1, 1, n, l, r);
            }
            else{
                int res = 0;
                if(r - l >= 2)res += st[2].query(1, 1, n, r, r);
                else if(r - l >= 1)res += st[1].query(1, 1, n, r, r);
                else res += st[0].query(1, 1, n, r, r);
                cout << res << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
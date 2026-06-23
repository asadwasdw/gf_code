#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 1e5+10, INF = 0x3f3f3f3f, mod = 1e9+7;


int row, col, cnt;
struct node
{
    int l,r;
    int val,lz;
}tr[N * 64];

void pushdown(int k, int l, int r){
    if(tr[k].lz == 0)return;
    int mid = l + r >> 1;
    if(tr[k].l == 0){
        tr[k].l = ++cnt;
        tr[cnt] = {0, 0, 0, 0};
    }
    tr[tr[k].l].val = mid - l + 1;
    tr[tr[k].l].lz = 1;
    if(tr[k].r == 0){
        tr[k].r = ++cnt;
        tr[cnt] = {0, 0, 0, 0};
    }
    tr[tr[k].r].val = r - mid;
    tr[tr[k].r].lz = 1;
    tr[k].lz = 0;
}
void update(int &k, int l, int r, int ql, int qr){
    if(!k){
        k = ++cnt;
        tr[k] = {0, 0, 0, 0};
    }
    if(l >= ql && r <= qr){
        tr[k].val = r - l + 1;
        tr[k].lz = 1;
        return;
    }
    pushdown(k, l, r);
    int mid = l + r >> 1;
    if(mid >= ql)update(tr[k].l, l, mid, ql, qr);
    if(mid < qr)update(tr[k].r, mid+1, r, ql, qr);
    tr[k].val = tr[tr[k].l].val + tr[tr[k].r].val;
}

int query(int k, int l, int r, int ql, int qr){
    if(!k)return 0;
    if(l >= ql && r <= qr)return tr[k].val;
    int mid = l + r >> 1;
    pushdown(k, l, r);
    int res = 0;
    if(mid >= ql)res += query(tr[k].l, l, mid, ql, qr);
    if(mid < qr)res += query(tr[k].r, mid+1, r, ql, qr);
    return res;
}

void clear(){
    for(int i=0; i<=cnt; ++i)tr[i] = {0, 0, 0, 0};
    cnt = row = col = 0;
}
void solve() {
    int n,m,q;
    int op,l,r;
    cnt = row = col = 0;
    tr[0] = {0, 0, 0, 0};
    int len = 1e9;
    bool f_row, f_col;
    while(cin >> n >> m >> q){
        f_row = f_col = false;
        ll res = (ll)n * m;
        while(q--){
            cin >> op >> l >> r;
            if(op == 1){
                
                int col_cnt = query(col, 1, len, 1, len);
                int cnt = r - l + 1 - query(row, 1, len, l, r);
                update(row, 1, len, l, r);
                if(f_col){
                    if(f_row){
                        res -= (ll)cnt * m - (ll)col_cnt * cnt;
                    }
                    else{
                        res -= (ll)cnt * m - (ll)col_cnt * cnt;
                        res -= col_cnt - 1;
                    }
                }
                else{
                    res -= (ll)cnt * m;
                    res += cnt;
                }
                f_row = true;
            }
            else{
                int row_cnt = query(row, 1, len, 1, len);
                int cnt = r - l + 1 - query(col, 1, len, l, r);
                update(col, 1, len, l, r);
                if(f_row){
                    if(f_col){
                        res -= (ll)cnt * n - (ll)row_cnt * cnt;
                    }
                    else{
                        res -= (ll)cnt * n - (ll)row_cnt * cnt;
                        res -= row_cnt - 1;
                    }
                }
                else{
                    res -= (ll)cnt * n;
                    res += cnt;
                }
                f_col = true;
            }
            cout << res << endl;
        }
        clear();
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
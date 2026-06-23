// #pragma GCC optimize(2)
#include<bits/stdc++.h>
#define endl '\n'
#define lowbits(x) ((x)&((-x)))
#define INF 0x3f3f3f3f
#define uu __int128
#define PI acos(-1)
#define ls k<<1
#define rs k<<1|1
using namespace std;
typedef  long long ll;
typedef  unsigned long long ull;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PII;
const int N=5e5+10, M=2*N;
const int mod=998244353;
const double eps=1e-9;
int nx[] = {0, 0, 1, -1}, ny[] = {1, -1, 0, 0};


ll n,C,m;


ll t[N], p[N];

ll f[N];

ll mx1[N << 2], mx2[N << 2];

void pushup(int k){
    mx1[k] = max(mx1[ls], mx1[rs]);
    mx2[k] = max(mx2[ls], mx2[rs]);
}

void update(int k, int l, int r, int x, ll d1, ll d2){
    if(l == r){
        mx1[k] = max(mx1[k], d1);
        mx2[k] = max(mx2[k], d2);
        return;
    }
    int mid = l + r >> 1;
    if(mid >= x)update(ls, l, mid, x, d1, d2);
    else update(rs, mid+1, r, x, d1, d2);
    pushup(k);
}

ll query1(int k, int l, int r, int ql, int qr, int op){
    if(ql > qr)return (ll)-1e18;
    if(l == ql && r == qr){
        if(op == 1)
        return mx1[k];
        else return mx2[k];
    }
    int mid = l + r >> 1;
    if(mid >= qr)return query1(ls, l, mid, ql, qr, op);
    else if(mid < ql)return query1(rs, mid+1, r, ql, qr, op);
    else return max(query1(ls, l, mid, ql, mid, op), query1(rs, mid+1, r, mid+1, qr, op));
}

void solve(){
    cin >> n >> C;
    cin >> m;
    for(int i=1; i<=m; ++i){
        cin >> t[i] >> p[i];
    }
    t[0] = 1;p[0] = 0;
    memset(mx1, -0x3f, sizeof mx1);
    memset(mx2, -0x3f, sizeof mx2);
    update(1, 0, n, 0, 0 + t[0] * C, 0 - t[0] * C);
    ll ans = 0;
    for(int i=1; i<=m; ++i){
        ll res1 = query1(1, 0, n, 0, t[i], 1), res2 = query1(1, 0, n, t[i]+1, n, 2);
        f[i] = max(res1 + p[i] - t[i] * C, res2 + p[i] + t[i] * C);
        ans = max(ans, f[i]);
        update(1, 0, n, t[i], f[i] + t[i] *C, f[i] - t[i] * C);
    }
    cout << ans << endl;
}


signed main()
{   
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int t = 1;
    // cout << fixed << setprecision(9)
    // cin >> t;
    while(t--)solve();
    return 0;

}
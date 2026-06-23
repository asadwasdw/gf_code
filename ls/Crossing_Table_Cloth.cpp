#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

struct node {
    int v, w;
    bool operator<(const node& t)const {
        return t.w < w;
    }
};

struct SegTree {
    struct Node {
        int mx, mx2, mn, mn2, cmx, cmn, tmx, tmn, tad;
        long long sum;
        Node() : mx(0), mx2(-INT_MAX), mn(0), mn2(INT_MAX),
            cmx(1), cmn(1), tmx(-INT_MAX), tmn(INT_MAX), tad(0), sum(0) {
        }
    };

    int n;
    vector<Node> t;
    vector<int> a;

    // 构造函数
    SegTree(int _n = 0) : n(_n) {
        t.resize(n * 4);
        a.resize(n + 1);
    }

    void pushup(int u) {
        const int lu = u << 1, ru = u << 1 | 1;
        t[u].sum = t[lu].sum + t[ru].sum;

        if (t[lu].mx == t[ru].mx) {
            t[u].mx = t[lu].mx; t[u].cmx = t[lu].cmx + t[ru].cmx;
            t[u].mx2 = max(t[lu].mx2, t[ru].mx2);
        } else if (t[lu].mx > t[ru].mx) {
            t[u].mx = t[lu].mx; t[u].cmx = t[lu].cmx;
            t[u].mx2 = max(t[lu].mx2, t[ru].mx);
        } else {
            t[u].mx = t[ru].mx; t[u].cmx = t[ru].cmx;
            t[u].mx2 = max(t[lu].mx, t[ru].mx2);
        }

        if (t[lu].mn == t[ru].mn) {
            t[u].mn = t[lu].mn; t[u].cmn = t[lu].cmn + t[ru].cmn;
            t[u].mn2 = min(t[lu].mn2, t[ru].mn2);
        } else if (t[lu].mn < t[ru].mn) {
            t[u].mn = t[lu].mn; t[u].cmn = t[lu].cmn;
            t[u].mn2 = min(t[lu].mn2, t[ru].mn);
        } else {
            t[u].mn = t[ru].mn; t[u].cmn = t[ru].cmn;
            t[u].mn2 = min(t[lu].mn, t[ru].mn2);
        }
    }

    void push_add(int u, int l, int r, int v) {
        t[u].sum += (r - l + 1ll) * v;
        t[u].mx += v; t[u].mn += v;
        if (t[u].mx2 != -INT_MAX) t[u].mx2 += v;
        if (t[u].mn2 != INT_MAX) t[u].mn2 += v;
        if (t[u].tmx != -INT_MAX) t[u].tmx += v;
        if (t[u].tmn != INT_MAX) t[u].tmn += v;
        t[u].tad += v;
    }

    void push_min(int u, int tg) {
        if (t[u].mx <= tg) return;
        t[u].sum += 1ll * (tg - t[u].mx) * t[u].cmx;
        if (t[u].mn2 == t[u].mx) t[u].mn2 = tg;
        if (t[u].mn == t[u].mx) t[u].mn = tg;
        if (t[u].tmx > tg) t[u].tmx = tg;
        t[u].mx = tg; t[u].tmn = tg;
    }

    void push_max(int u, int tg) {
        if (t[u].mn >= tg) return;
        t[u].sum += 1ll * (tg - t[u].mn) * t[u].cmn;
        if (t[u].mx2 == t[u].mn) t[u].mx2 = tg;
        if (t[u].mx == t[u].mn) t[u].mx = tg;
        if (t[u].tmn < tg) t[u].tmn = tg;
        t[u].mn = tg; t[u].tmx = tg;
    }

    void pushdown(int u, int l, int r) {
        int mid = (l + r) >> 1;
        int lu = u << 1, ru = u << 1 | 1;
        if (t[u].tad) push_add(lu, l, mid, t[u].tad), push_add(ru, mid + 1, r, t[u].tad);
        if (t[u].tmx != -INT_MAX) push_max(lu, t[u].tmx), push_max(ru, t[u].tmx);
        if (t[u].tmn != INT_MAX) push_min(lu, t[u].tmn), push_min(ru, t[u].tmn);
        t[u].tad = 0; t[u].tmx = -INT_MAX; t[u].tmn = INT_MAX;
    }

    void build(int u = 1, int l = 1, int r = -1) {
        if (r == -1) r = n;
        t[u].tmn = INT_MAX; t[u].tmx = -INT_MAX;
        if (l == r) {
            t[u].sum = t[u].mx = t[u].mn = a[l];
            t[u].mx2 = -INT_MAX; t[u].mn2 = INT_MAX;
            t[u].cmx = t[u].cmn = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void add(int L, int R, int v, int u = 1, int l = 1, int r = -1) {
        if (r == -1) r = n;
        if (R < l || r < L) return;
        if (L <= l && r <= R) return push_add(u, l, r, v);
        int mid = (l + r) >> 1;
        pushdown(u, l, r);
        add(L, R, v, u << 1, l, mid);
        add(L, R, v, u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void tomin(int L, int R, int v, int u = 1, int l = 1, int r = -1) {
        if (r == -1) r = n;
        if (R < l || r < L || t[u].mx <= v) return;
        if (L <= l && r <= R && t[u].mx2 < v) return push_min(u, v);
        int mid = (l + r) >> 1;
        pushdown(u, l, r);
        tomin(L, R, v, u << 1, l, mid);
        tomin(L, R, v, u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void tomax(int L, int R, int v, int u = 1, int l = 1, int r = -1) {
        if (r == -1) r = n;
        if (R < l || r < L || t[u].mn >= v) return;
        if (L <= l && r <= R && t[u].mn2 > v) return push_max(u, v);
        int mid = (l + r) >> 1;
        pushdown(u, l, r);
        tomax(L, R, v, u << 1, l, mid);
        tomax(L, R, v, u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    long long qsum(int L, int R, int u = 1, int l = 1, int r = -1) {
        if (r == -1) r = n;
        if (R < l || r < L) return 0;
        if (L <= l && r <= R) return t[u].sum;
        int mid = (l + r) >> 1;
        pushdown(u, l, r);
        return qsum(L, R, u << 1, l, mid) + qsum(L, R, u << 1 | 1, mid + 1, r);
    }

    long long qmax(int L, int R, int u = 1, int l = 1, int r = -1) {
        if (r == -1) r = n;
        if (R < l || r < L) return -INT_MAX;
        if (L <= l && r <= R) return t[u].mx;
        int mid = (l + r) >> 1;
        pushdown(u, l, r);
        return max(qmax(L, R, u << 1, l, mid), qmax(L, R, u << 1 | 1, mid + 1, r));
    }

    long long qmin(int L, int R, int u = 1, int l = 1, int r = -1) {
        if (r == -1) r = n;
        if (R < l || r < L) return INT_MAX;
        if (L <= l && r <= R) return t[u].mn;
        int mid = (l + r) >> 1;
        pushdown(u, l, r);
        return min(qmin(L, R, u << 1, l, mid), qmin(L, R, u << 1 | 1, mid + 1, r));
    }
};

vector<int> l[N], r[N];
map<PII, int> cnt;
void solve()
{
    int n, m;
    cin >> n >> m;
    SegTree st(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        l[x].push_back(y);
        r[y].push_back(x);
        cnt[{x, y}] ++;
        st.a[y] = max(st.a[y], x);
    }
    st.build();

    for(int i = 1; i <= n; i ++) {
        l[i].push_back(-INF);
        l[i].push_back(INF);
        sort(l[i].begin(), l[i].end(),[&](int a, int b){
            return a < b;
        });

        r[i].push_back(-INF);
        r[i].push_back(INF);
        sort(r[i].begin(), r[i].end(),[&](int a, int b){
            return a < b;
        });
        // cout << i << ": \n";
        // for(auto t : l[i]) cout << t << " "; cout << endl;
        // for(auto t : r[i]) cout << t << " "; cout << endl;
    }
    int q;
    cin >> q;

    while(q --) {
        int a, b;
        cin >> a >> b;
        auto L = prev(upper_bound(l[a].begin(), l[a].end(), b));
        auto R = lower_bound(r[b].begin(), r[b].end(), a);
        int ar = *L;
        int bl = *R;

        bool ky = false;

        if(cnt[{a, b}] >= 2) {
            ky = true;
        } else if(cnt[{a, b}]){
            if (st.qmax(a, b - 1) >= a || st.qmax(a, b) > a) {
                ky = true;
            } 
        } else {

            // cout << a << " " << b << " " << ar << " " << bl << endl;
            if(ar+ 1 >= bl)  {
                ky = true;
            } 
        }

        if(ky) {
            cout << "Yes\n";
        }else {
            cout << "No\n";
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
    return 0;
}
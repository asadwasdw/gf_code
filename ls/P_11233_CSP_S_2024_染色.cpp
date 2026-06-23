#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

ll dp[N];
ll a[N], w[N];

// 线段树数组大小为区间大小的 4 倍
ll tree[N << 2];

// 初始化线段树区间为极小值
void build(int u, int l, int r) {
    tree[u] = -INFll;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
}

// 单点更新：将 pos 位置上的值与 val 取 max
void update(int u, int l, int r, int pos, ll val) {
    if (l == r) {
        tree[u] = max(tree[u], val);
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(u << 1, l, mid, pos, val);
    else update(u << 1 | 1, mid + 1, r, pos, val);
    tree[u] = max(tree[u << 1], tree[u << 1 | 1]);
}

// 区间最大值查询
ll query(int u, int l, int r, int ql, int qr) {
    if (ql > qr) return -INFll;
    if (ql <= l && r <= qr) return tree[u];
    int mid = (l + r) >> 1;
    ll res = -INFll;
    if (ql <= mid) res = max(res, query(u << 1, l, mid, ql, qr));
    if (qr > mid) res = max(res, query(u << 1 | 1, mid + 1, r, ql, qr));
    return res;
}

void solve()
{
    int n; 
    cin >> n;
    ll max_a = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        max_a = max(max_a, a[i]);
        if(a[i] == a[i - 1]) w[i] = a[i];
        else w[i] = 0;
        w[i] += w[i - 1];
    }
    
    // 初始化线段树，覆盖范围为 [1, max_a]
    if (max_a > 0) {
        build(1, 1, max_a);
    }
    
    ll global_max = 0; // 处理 j=0 的边界情况
    dp[1] = 0;
    
    for(int i = 2; i <= n; i ++) {
        // 全局最大值转移（包括线段树中的最大值 和 j=0 时的初始全局最大值）
        ll val1 = global_max + w[i - 1];
        if (max_a > 0) val1 = max(val1, query(1, 1, max_a, 1, max_a) + w[i - 1]);
        
        // 单点同值转移：查询 a[i] 上的最大值并额外增加 A[i] 贡献
        ll val2 = -INFll;
        if (max_a > 0) val2 = query(1, 1, max_a, a[i], a[i]) + a[i] + w[i - 1];
        
        dp[i] = max(val1, val2);
        
        // 计算当前决策值并单点更新到线段树的 A[i-1] 上
        ll val = dp[i] - w[i];
        global_max = max(global_max, val);
        if (max_a > 0) {
            update(1, 1, max_a, a[i - 1], val);
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, dp[i] + w[n] - w[i]);
    }
    cout << ans << endl;
}

int main()
{
    // 快读
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t; t = 1;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        solve();
    }
    return 0;
}
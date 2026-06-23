#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

int n, m, q;
int a[N], init_cnt[N], cnt[N];
ll s[N]; // 修改点 1：前缀和必须用 ll

vector<int> v[N];

struct Node
{
    int l, r, sum;
} tr[N * 45];

int root[N + 10], idx;

int update(int pre, int l, int r, int pos) {
    int cur = ++ idx;
    tr[cur] = tr[pre];
    tr[cur].sum ++ ;
    if(l == r) return cur;
    int mid = l + r >> 1;
    if(pos <= mid) tr[cur].l = update(tr[pre].l, l, mid, pos);
    else tr[cur].r = update(tr[pre].r, mid + 1, r, pos);
    return cur;
}

int query_kth(int u, int l, int r, int k) {
    if(l == r) return l;
    int mid = l + r >> 1;
    if(k <= tr[tr[u].l].sum) return query_kth(tr[u].l, l, mid, k);
    else return query_kth(tr[u].r, mid + 1, r, k - tr[tr[u].l].sum);
}

ll get_total(ll h) {
    if(h <= 0) return 0;
    ll t;
    // 这里的逻辑保持你的命名：寻找初始次数小于 h 的数字个数
    if(h > n) t = m;
    else t = lower_bound(cnt + 1, cnt + m + 1, h) - cnt - 1;

    // 修改点 2：这里 t*h 在 h=3e12, t=5e5 时约为 1.5e18，不会溢出 ll
    return (ll)t * h - s[t];
}

void solve()
{
    if (!(cin >> n >> m)) return;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        init_cnt[a[i]] ++;
    }

    for(int i = 1; i <= m; i ++) {
        cnt[i] = init_cnt[i];
        v[cnt[i]].push_back(i);
    }
    
    // 排序用于 get_total 的二分查找
    sort(cnt + 1, cnt + m + 1);
    for(int i = 1; i <= m; i ++) {
        s[i] = s[i - 1] + (ll)cnt[i];
    }

    // 主席树：版本 h 代表 initial_cnt <= h 的数字集合
    for(int h = 0; h <= n; h ++) {
        root[h] = (h == 0) ? 0 : root[h - 1];
        for(auto id : v[h]) {
            root[h] = update(root[h], 1, m, id);
        }
    }

    cin >> q;
    while(q --) {
        ll x; cin >> x;
        if(x <= n) {
            cout << a[x] << endl;
            continue;
        }

        x -= n;

        // 修改点 3：限制 r 的大小，防止 get_total 内部乘法溢出
        ll l = 1, r = 3e12; 
        ll level = r;
        while(l <= r) {
            ll mid = l + (r - l) / 2;
            if (get_total(mid) >= x) {
                level = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        ll k = x - get_total(level - 1);

        // 查找初始次数 <= level-1 的数字集合中第 k 小的编号
        int version = (level - 1 >= n) ? n : (int)(level - 1);
        cout << query_kth(root[version], 1, m, (int)k) << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}
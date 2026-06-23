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


struct Node {
    int l, r;
    int x;
}tr[N * 2];

int a[N];

void pushup(int u) {
    tr[u].l = tr[u << 1].l;
    tr[u].r = tr[u << 1 | 1].r;
    tr[u].x = max(tr[u << 1].x, tr[u << 1 | 1].x);
}


void build(int u, int l, int r) {
    if(l == r) {
        tr[u] = {l, r, a[l]};
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int k, int x) {
    if(tr[u].l == k && tr[u].r == k) {
        tr[u].x = x;
        return;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if(k <= mid) modify(u << 1, k, x);
    if(k >= mid + 1) modify(u << 1 | 1, k, x);
    pushup(u);
}


int query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) {
        return tr[u].x;
    }

    int mx = -1;

    int mid = tr[u].l + tr[u].r >> 1;
    if(l <= mid) mx = max(mx, query(u << 1, l, r));
    if(r >= mid + 1) mx = max(mx, query(u << 1 | 1, l, r));
    return mx;
}

int dp[N];
int fa[N];

void solve()
{
    int n, d, R;
    cin >> n >> d >> R;
    memset(a, -1, sizeof a);
    build(1, 1, n); 

    for(int i = 1; i <= n; i ++ ) {
        cin >> a[i];
        fa[a[i]] = i;
    }

    int ans = 0;
    for(int i = n; i; i --) {
        if(i + d <= n) modify(1, fa[i + d], dp[i + d]);
        int l = max(1, fa[i] - R);
        int r = min(n, fa[i] + R);
        dp[i] = max(dp[i], 1 + query(1, l, r));
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;


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
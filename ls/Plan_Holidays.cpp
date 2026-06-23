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


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    ll ans = INFll;

    auto check = [&](int m) -> void{
        vector<vector<ll>>  l(k + 10, vector<ll>(2, INFll));
        vector<vector<ll>>  r(k + 10, vector<ll>(2, INFll));
        l[0][1] = r[0][1] = a[m];
        for(int i = 1; i <= k && m - i >= 1; i ++) {
            l[i][0] = l[i - 1][1];
            l[i][1] = min(l[i - 1][1], l[i - 1][0]) + a[m - i];
        }

        for(int i = 1; i <= k && m + i <= n; i ++) {
            r[i][0] = r[i - 1][1];
            r[i][1] = min(r[i - 1][1], r[i - 1][0]) + a[m + i];
        }

        for(int i = 0; i <= k - 1; i ++) {
            ans = min(ans, l[i][1]+r[k-i-1][1]-a[m]);
        }
    };

    for(int i = 1; i <= n; i += k) {
        check(i);
        if(i + 1 <= n) check(i + 1); 
    }
    k ++;


    for(int i = 1; i <= n; i += k) {
        check(i);
        if(i + 1 <= n) check(i + 1); 
    }

    cout << ans << endl;
}

int a[N];
int n, k;
struct Node {
    int l, r;
    ll max01, max10, max00,max11;
} tr[N * 4];

void pushup(Node& root,  Node lson,  Node rson) {
    root.max00 = min({lson.max01 + rson.max10, lson.max00 + rson.max10, lson.max01 + rson.max00});
    root.max01 = min({lson.max00 + rson.max11, lson.max01 + rson.max01, lson.max01 + rson.max11});
    root.max10 = min({lson.max11 + rson.max00, lson.max11 + rson.max10, lson.max10 + rson.max10});
    root.max11 = min({lson.max10 + rson.max11, lson.max11 + rson.max01, lson.max11 + rson.max11});
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    tr[u].l = l, tr[u].r = r;
    if(l == r) {
        tr[u].max11 = a[l];
        tr[u].max00 = 0;
        tr[u].max01 = tr[u].max10 = INFll;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

Node query(int u, int l, int r) {
    if(l <= tr[u].l && tr[u].r <= r) return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    
    if (r <= mid) return query(u << 1, l, r);
    if (l > mid) return query(u << 1 | 1, l, r);
    
    Node root, lson = query(u << 1, l, r), rson = query(u << 1 | 1, l, r);
    pushup(root, lson, rson);
    return root;
}

void solve2() {
    cin >> n >> k;

    for(int i = 1; i <= n; i ++ ) cin >> a[i];

    build(1, 1, n);
    ll ans = INFll;
    for(int i = 1; i <= n; i ++) {
        if(i + k - 1 <= n) ans = min(ans, query(1, i, i + k - 1).max11);
        if(i + k <= n) ans = min(ans, query(1, i, i + k).max11);
    }
    cout << ans << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve2();
    }
    return 0;
}
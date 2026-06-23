#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

ll fa[N],sz[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]); 
}

ll merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return 0;
    ll val = sz[x] * sz[y];
    fa[x] = y;
    sz[y] += sz[x];
    return val;
}
void init(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i, sz[i] = 1;
}

void solve()
{
    int n, m;cin >> n >> m;
    vector<array<ll, 3>> edge(m);
    for (int i = 0; i < m; i++) {
        cin >> edge[i][1] >> edge[i][2] >> edge[i][0];
    }
    sort(edge.begin(), edge.end());

    int l = 0, r = m - n + 1, res = 0;
    auto check = [&](int mid) -> bool {
        init(n);
        for (int i = mid; i < m; i++) {
            merge(edge[i][1], edge[i][2]);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) if (fa[i] == i) cnt++;
        return cnt == 1;
    };
    while (l <= r) { 
        int mid = l + r >> 1;
        if (check(mid)) res = mid,  l = mid + 1;
        else r = mid - 1;
    }
    init(n);
    vector<array<ll, 3>> tmp;
    for (int i = res; i < m; i++) {
        auto [w, u, v] = edge[i];
        if (merge(u, v)) tmp.emplace_back(edge[i]);
    }
    ll ans = 0;
    init(n);
    reverse(tmp.begin(), tmp.end());
    for (auto [w, u, v] : tmp) {
        ans += merge(u, v) * w;
    }
    cout << ans << '\n';




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
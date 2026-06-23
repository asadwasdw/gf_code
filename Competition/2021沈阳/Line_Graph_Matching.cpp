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

int w[N], cnt[N];
struct edge{
    int u, v, w;
}e[N];

ll f[N], now[N];
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void solve()
{
    int n, m;   
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) f[i] = i, now[i] = 0;
    for(int i = 1; i <= m; i ++) {
        int u, v, ww; cin >> u >> v >> ww;
        e[i] = {u, v, ww};
    }
    sort(e + 1, e + m + 1, [&](edge a, edge b){
        return a.w > b.w;
    });

    ll ans = 0;
    for(int i = 1; i <= m; i ++) {
        auto [u, v, w] = e[i];
        // cout << u << " " << v << " " << w << endl;
        u = find(u), v = find(v);
        if(u == v) {
            if(now[u] == 0) now[u] = w;
            else ans += w + now[u], now[u] = 0;
        } else {
            f[v] = u;
            if(now[u] == 0 && now[v] == 0) {
                now[u] = w;
            } else if(now[u] != 0 && now[v] != 0) {
                ans += w + max(now[u], now[v]);
                now[u] = min(now[u], now[v]);
            } else {
                ans += w + max(now[u],now[v]);
                now[u] = 0;
            }
        }
        // cout << ans << endl;
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
#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<PII>>adj(N);

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edg;
    for(int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edg.push_back({u,v,w});
    }

    auto dij = [&](int s) -> pair<vector<ll>, vector<ll>> {
        
        vector dis(n + 1, INFll);
        vector cnt(n + 1, 0ll);
        priority_queue<PII,vector<PII>, greater<PII>> q;
        q.push({0, s});
        dis[s] = 0, cnt[s] = 1;

        while(q.size()) {
            auto [W, u] = q.top(); q.pop();
            if(W > dis[u]) continue;
            for(auto [v, w] : adj[u]) {
                if(dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u];
                    q.push({dis[v], v});
                } else if(dis[v] == dis[u] + w) {
                    cnt[v] += cnt[u];
                }
                cnt[v]%=mod;
            }
        }

        // for(int i = 1; i <= n; i ++ ) {
        //     cout << dis[i] << endl;
        // }

        return {dis, cnt};
    };

    auto [dis1, cnt1] = dij(1);
    auto [disn, cntn] = dij(n);

    // for(int i = 1; i <= n; i ++) {
    //     cout << dis1[i] << " " << cnt1[i] << " " << disn[i] << " " << cntn[i] << endl;
    // }

    for(int i = 0; i < m; i ++) {
        auto [u, v, w] = edg[i];
        if( (dis1[u] + w + disn[v] == dis1[n] && cnt1[u] * cntn[v]%mod == cnt1[n]%mod) ||
            (dis1[v] + w + disn[u] == dis1[n] && cnt1[v] * cntn[u]%mod == cnt1[n]%mod) ) {
            cout << "Yes\n";
        } else cout << "No\n";
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
}
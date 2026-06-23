#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>PII;
const int N=1e4+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<PII>>adj(N);

ll dis[N][110];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    memset(dis, 0x3f, sizeof dis);
    priority_queue<PII,vector<PII>, greater<PII> >q;

    q.push({0, 1});
    dis[1][0] = 0;

    for(int i = 1; i <= m; i ++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    while(q.size()) {
        auto [t, u] = q.top(); q.pop();
        if(t > dis[u][t % k]) continue;
        for(auto [v, w] : adj[u]) {
            // ll tt = max(t, t % k + (w) / k * k) + 1;
            ll tt = max(t, (w-t+k-1)/k*k+t) + 1;
            // cout << u << " " << v << " " << w << " " << tt << endl;
            if(dis[v][tt % k] > tt) {
                dis[v][tt % k] = tt;
                q.push({tt, v});
            }
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 0; j < k; j ++) {
    //         cout << dis[i][j % k] << " \n"[j == k - 1];
    //     }
    // }

    if(dis[n][0] >= INF/2) cout << "-1" << endl;
    else cout << dis[n][0] << endl;

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
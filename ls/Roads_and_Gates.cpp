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
#define x first
#define y second

vector<vector<PII>>adj(N);
ll dis[N];

void solve()
{
    memset(dis, 0x3f, sizeof dis);
    int n, m, y;
    cin >> n >> m >> y;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for(int i = 1; i <= n; i ++) {
        int t; cin >> t;
        adj[0].push_back({i, t + y});
        adj[i].push_back({0, t});
    }

    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    dis[1] = 0;
    while(q.size()) {
        auto [d, u] = q.top(); q.pop();
        if(d > dis[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(dis[v] <= d + w) continue;
            dis[v] = d + w;
            q.push({dis[v], v}); 
        }
    }

    for(int i = 2; i <= n; i ++) cout << dis[i] << " ";





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
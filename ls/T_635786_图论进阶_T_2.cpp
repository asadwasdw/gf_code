#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

const int N=1e5+10;
typedef long long ll;
typedef pair<ll,int>PII;
vector<vector<PII>>adj(N);
vector<vector<PII>>adj2(N);
int n, m, l, p;
ll dis[N];
ll dij() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    priority_queue<PII,vector<PII>, greater<PII>> q;
    q.push({0, 1});

    while(q.size()) {
        ll d = q.top().first, u = q.top().second; 
        q.pop();
        
        if(d > dis[u]) continue;

        for(int i = 0; i < adj[u].size(); i ++) {
            int v = adj[u][i].first, w = adj[u][i].second;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    return dis[n];
}

ll dp[N][55];
int vis[N][55];
bool flag = false;
ll dfs(int u, int k) {
    if(k < 0 || k > l) return 0;
    if(flag) return -1;
    if(vis[u][k]) {
        flag = true;
        return 0;
    }
    if(dp[u][k] != -1) return dp[u][k];
    
    vis[u][k] = 1;
    
    ll res = 0;
    if(u == 1 && k == 0) res = 1;
    for(int i = 0; i < adj2[u].size(); i ++) {
        int v = adj2[u][i].first, w = adj2[u][i].second;
        res = (res + dfs(v, dis[u] - (dis[v] + w) + k)) % p;
    }

    vis[u][k] = 0;
    return dp[u][k] = res;
}

void solve()
{
    cin >> n >> m >> l >> p;

    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj2[v].push_back({u, w});
    }

    ll res = dij();

    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(int i = 0; i <= l; i ++) {
        ans = (ans + dfs(n, i)) % p;
    }
    if(flag) ans = -1;
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
    return 0;
}
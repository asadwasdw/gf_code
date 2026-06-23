#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);
vector<vector<int>>adj2(N);

int cnt = 0;
int vis[N];

void dfs(int u) {
    vis[u] = true;
    cnt ++;
    for(auto v : adj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

void dfs2(int u) {
    vis[u] = true;
    cnt ++;
    for(auto v : adj2[u]) {
        if(vis[v]) continue;
        dfs2(v);
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cnt = 0;
        memset(vis, 0, sizeof vis);
        dfs(i);
        dfs2(i);
        if(cnt == n + 1) ans ++;
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
    return 0;
}
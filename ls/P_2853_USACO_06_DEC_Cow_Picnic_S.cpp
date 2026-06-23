#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int a[N];
int vis[N];
int cnt = 0;
int k, n, m;

void dfs(int u) {
    vis[u] = true;
    cnt += a[u];

    for(auto v:adj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

void solve()
{
  
    cin >> k >> n >> m;
    for(int i = 1; i <= k; i ++) {
        int id; cin >> id;
        a[id] ++;
    }

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        memset(vis, 0, sizeof vis);
        cnt = 0;
        dfs(i);
        if(cnt == k) ans ++;
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
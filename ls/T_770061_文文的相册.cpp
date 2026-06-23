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

// vector<vector<int>>adj(N);

int adj[15][15];
bool vis[N];
int n, m;
int ans = 0;

void dfs(int id) {
    if(id == n + 1) {
        bool ky = true;
        for(int u = 1; u <= n; u ++) {
            for(int v = u + 1; v <= n; v ++) {
                if(!vis[u] || !vis[v]) continue;
                if(adj[u][v] == 0) ky = false;
            }
        }

        if(ky) {
            int res = 0;
            for(int i = 1; i <= n; i ++) res += vis[i];
            ans = max(ans, res);
        }   

        return;
    }

    dfs(id + 1);

    vis[id] = true;
    dfs(id + 1);
    vis[id] = false;
}



void solve()
{
    cin >> n >> m;
    // assert(n <= 5);
    // assert(m == 0);

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        assert(adj[u][v] == 0);
        assert(u != v);
        adj[u][v] = adj[v][u] = 1;
    }

    dfs(1);

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
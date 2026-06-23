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

vector<vector<int>>adj(N);

long long x[N], y[N];
bool vis[N];

long long U, D, L, R;

void dfs(int u) {
    // cout << u << endl;
    // cout << x[u] << " " << y[u] << endl;
    vis[u] = true;
    U = min(U, x[u]);
    D = max(D, x[u]);
    L = min(L, y[u]);
    R = max(R, y[u]);



    for(auto v : adj[u]) {
        if(vis[v]) continue;
        dfs(v); 
    }

}

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) cin >> x[i] >> y[i];

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    long long ans = 1e18;

    for(int i = 1; i <= n; i ++) {
        if(vis[i]) continue;
        U = L = 1e12;
        D = R = -1e12;
        
        dfs(i);

        ans = min(2 * (R - L + D - U), ans);
    }
    cout << ans;

    

    







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
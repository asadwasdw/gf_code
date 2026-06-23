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

vector<vector<int>>adj(N);
int sz[N], dep[N];

void dfs(int u, int fa) {
    sz[u] = 1;
    dep[u] = 1;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        dep[u] = max(dep[v] + 1, dep[u]);
    }
}
int w[N];
int step = 0;
void dfs2(int u, int fa) {
    // cout << u << endl;
    w[u] = step;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        ++step;
        dfs2(v, u);
        ++step;
    }
}

void solve()
{
    step = 0;
    int n; cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    dfs2(1,-1);
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        sum += w[i];
        // cout << w[i] << " \n"[i == n];
        adj[i].clear();
    }
    // cout << sum << endl;
    cout << (long double)sum/(n - 1) << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}   
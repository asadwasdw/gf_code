#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int n,m;
int dist[N];
int a[N];

int dep[N], fa[N][31];

vector<int> g[N];

void dfs(int u, int far){
    fa[u][0] = far;
    dep[u] = dep[far] + 1;
    for(int i=1; i<31; ++i)fa[u][i] = fa[fa[u][i-1]][i-1];
    for(auto v : g[u]){
        if(v == far)continue;
        dist[v] = dist[u] ^ a[v];
        dfs(v, u);
    }
}
int lca(int a, int b){
    if(dep[a] < dep[b])swap(a, b);
    for(int i=30; i>=0; --i){
        if(dep[fa[a][i]] >= dep[b])a = fa[a][i];
    }
    if(a == b)return a;
    for(int i=30; i>=0; --i){
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

void solve()
{
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> a[i];
    for(int i=1; i<n; ++i){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dist[1] = a[1];
    dfs(1, 0);
    
    // for(int i=1; i<=n; ++i){
    //     cout << dist[i] << endl;
    // }
    for(int i=1; i<=m; ++i){
        int u,v;
        cin >> u >> v;
        int lc = lca(u, v);
        cout << (dist[u] ^ dist[v] ^ a[lc]) << endl;
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
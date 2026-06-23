#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=10007;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int fa[N][25];
int deep[N];

void dfs(int u, int father) {
    
    deep[u] = deep[father] + 1;
    fa[u][0] = father;
    for(int i = 1; (1 << i) < deep[u]; i ++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    for(auto v : adj[u]) {
        if(v == father) continue;
        dfs(v, u);
    }
}

int lca(int x, int y) {
    if(deep[x] < deep[y]) swap(x, y);
    for(int i = 23; i >= 0; i --) {
        if(deep[x] - (1 << i) >= deep[y]) {
            x = fa[x][i];
        }
    }
    if(x == y) return x;

    for(int i = 23; i >= 0; i --) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

int len(int x, int y) {
    return deep[x] + deep[y] - 2 * deep[lca(x, y)];
}

int d[N];


void dfs2(int u, int father) {
    for(auto v : adj[u]) {
        if(v == father) continue;
        dfs2(v, u);
        d[u] += d[v];
    }
    // cout << u << ' ' << d[u] << endl;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        d[u] ++;
        d[v] ++;
        int l = lca(u, v);
        d[l] --;
        d[fa[l][0]] --;
    }


    dfs2(1, 0);

    int x, y;
    cin >> x >> y;
    int lcaxy = lca(x, y);
    
    int ans = 0;

    while(x != lcaxy) {
        if(d[x] == 0) ans ++;
        x = fa[x][0];
    }

    
    while(y != lcaxy) {
        if(d[y] == 0) ans ++;
        y = fa[y][0];
    }

    if(d[lcaxy] == 0) ans ++;

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
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

int ans = 0;
int n, m;
void dfs2(int u, int father) {
    for(auto v : adj[u]) {
        if(v == father) continue;
        dfs2(v, u);
        d[u] += d[v];        
    }

    if(u != 1) {
        if(d[u] == 0) ans += m;
        else if(d[u] == 1) ans += 1;
    }
    // cout << u << ' ' << d[u] << endl;
}

void solve()
{
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
        d[lca(u, v)] -= 2;
    }


    dfs2(1, 0);


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
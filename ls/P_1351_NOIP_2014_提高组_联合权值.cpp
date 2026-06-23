#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=10007;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);

int fa[N][20];
int deep[N];
ll w[N], w1[N], w2[N];

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
    for(int i = 19; i >= 0; i --) {
        if(deep[x] - (1 << i) >= deep[y]) {z
            x = fa[x][i];
        }
    }
    if(x == y) return x;

    for(int i = 19; i >= 0; i --) {
        if(fa[x][i] != fa[y][i]) {
            x = fa[x][i];
            y = fa[y][i];
        }
    }

    return fa[x][0];
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i ++) {
        cin >> w[i];
    }

    dfs(1, 0);

    ll ans = 0, mx = 0;
    for(int i = 1; i <= n; i ++) {
        if(fa[i][1] != 0) {
            int u = fa[i][1];
            ans += w[u] * w[i] % mod;
            mx = max(mx, w[u] * w[i]);
        }

        if(fa[i][0] != 0) {
            int u = fa[i][0];
            ans += w1[u] * w[i] % mod;

            mx = max(mx, w2[u] * w[i]);
            w1[u] += w[i];// u之前所有儿子的和
            w2[u] = max(w2[u], w[i]);//  u之前所有儿子的和
        }
        ans %= mod;
    }

    cout << mx << " " << ans * 2 % mod << endl;
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
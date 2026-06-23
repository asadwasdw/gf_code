#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e3 + 10, M = 1e4 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(M);

struct gfDSU {
    int n;
    vector<int> f, sz;

    void init(int _n) {
        n = _n;
        f.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 0; i <= n; i ++) f[i] = i, sz[i] = 0;
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        sz[y] += sz[x];
        f[x] = y;
    }
    void debug() {
        for(int i = 0; i <= n; i ++) cout << f[i] << " \n"[i == n];
        for(int i = 0; i <= n; i ++) cout << sz[i] << " \n"[i == n];
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
}dsu;

int W[M];
int n, m, k;
vector<int> dp[M];
int sz[M];
void dfs(int u, int fa) {
	dp[u].assign(1,INF);
	if(sz[u])
	{
		dp[u].push_back(0);
	}
    for(auto v : adj[u]) {
        dfs(v, u);
        vector<int> g(sz[u]+sz[v]+1, INF);
        for(int i = 1; i <= sz[u] + sz[v]; i ++) {
            for(int j = max(0ll, i - sz[u]); j <= min(i, sz[v]); j ++) {
                if(j == 0) {
                    g[i] = min(g[i], dp[u][i] + sz[v] * W[u]);
                } else if(i == j) {
                    g[i] = min(g[i], dp[v][j] + sz[u] * W[u]);
                } else {
                    g[i] = min(g[i], dp[u][i - j] + dp[v][j]);
                }
            }
        }
        dp[u] = g;
        // swap(g, dp[u]);
        sz[u] += sz[v];
    }
}

void solve()
{
    cin >> n >> m >> k;
    dsu.init(2 * n);
    for(int i = 0; i < k; i ++) {
        int x; cin >> x;
        sz[x]++;
    }

    vector<array<int,3>> edg;
    for(int i = 0; i < m ; i ++) {
        int u, v, w; cin >> u >> v >> w;
        edg.push_back({u, v, w});
    }

    sort(edg.begin(), edg.end(), [&](array<int, 3> a, array<int,3> b){
        return a[2] < b[2];
    });
    int root = n;
    for(auto [u, v, w] : edg) {
        if(dsu.same(u, v)) continue;
        W[++root] = w;
        adj[root].push_back(dsu.find(u));
        adj[root].push_back(dsu.find(v));
        dsu.merge(u, root);
        dsu.merge(v, root);
    }

    // cout << root << endl;
    dfs(root, -1);

    vector<int> ans(n + 1, INF);
    for(int i = 1; i <= root; i ++) {
        for(int j = 1; j < dp[root].size(); j ++) {
            ans[j] = min(ans[j], dp[root][j]);
        }
    }

    for(int i = 1; i <= min(k, n); i ++) {
        cout << ans[i] << " ";
    }
    for(int i = k + 1; i <= n; i ++) {
        cout << 0 << " ";
    } cout << endl;

    for(int i = 0; i <= root; i ++) {
        sz[i] = 0;
        adj[i].clear();
    }
    root = 0;


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


/*

void dfs(int u,int fa)
{
	dp[u].assign(1,inf);
	if(bz[u])
	{
		siz[u]=1;
		dp[u].push_back(0);
	}
	for(auto v:e[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		vector<int> dpn(siz[u]+siz[v]+1,inf);
		for(int i=1; i<=siz[u]+siz[v]; i++)  u 这课树上染了i个 
		{
			for(int j=max(0ll,i-siz[u]); j<=min(i,siz[v]); j++) 其中有j个是来自v这个子树 j >= (i - sz[u]) 相对于u满了，只能放在v
			{
				if(j==0) {
					dpn[i]=min(dpn[i],dp[u][i-j]+val[u]*siz[v]);  v 里面没有服务器， 那么里面需要网的所有电脑，都要经过u
				}
				else if(i==j) {
					dpn[i]=min(dpn[i],dp[v][j]+val[u]*siz[u]); u里面没有电脑 同上
				}
				else {
					dpn[i]=min(dpn[i],dp[u][i-j]+dp[v][j]);
				}
			}
		}
		siz[u]+=siz[v];
		dp[u]=dpn;
	}
}

*/
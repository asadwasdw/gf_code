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
int fa[N], dep[N];

void dfs(int u, int pa) {
    dep[u] = dep[pa] + 1;
    fa[u] = pa;

    for(auto v : adj[u]) {
        if(v == pa) continue;
        dfs(v, u);
    }
}

int f[N];
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
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
    for(int i = 1; i <= n; i ++) f[i] = i;
    dfs(1, 0);

    int q;
    cin >> q;
    int ans = n - 1;
    while(q --) {
        int x, y;
        cin >> x >> y;
        x = find(x), y = find(y);
        while(x != y) {
            if(dep[x] < dep[y]) swap(x, y);
            f[x] = fa[x];
            x = find(x);
            ans --;
        }
        cout << ans << endl;
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
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);

int a[N];
int f[N], dep[N], fa[N];

int find(int x) {
    if (x != f[x]) f[x] = find(f[x]);
    return f[x];
}



void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        f[fu] = fv;
        adj[u].push_back(v);
        adj[v].push_back(u);
        // cout << u << " " << v << endl;
    }

    int q; cin >> q;
    vector<PII> query;
    while(q --) {
        int u, v; cin >> u >> v;
        a[u] ^= 1, a[v] ^= 1;
        query.push_back({u, v});
    }

    int cnt = 0;
    for(int i = 1; i <= n; i ++) cnt += a[i];
    if(cnt){
        cout << "NO\n" << cnt/2 << endl;
        return;
    }

    auto dfs = [&](auto self , int x, int father) -> void{
        fa[x] = father;
        dep[x] = dep[father] + 1;
        for(auto v : adj[x]) {
            if (v == father) continue;
            self(self, v, x);
        }
    };

    dfs(dfs, 1, 0);
    cout << "YES\n";

    for(auto [x, y] : query) {
        vector<int> ansx, ansy;
        while(x != y) {
            if(dep[x] >= dep[y]) {
                ansx.push_back(x);
                x = fa[x];
            }
            else {
                ansy.push_back(y);
                y = fa[y];
            } 
        }
        ansx.push_back(x);
        cout << ansx.size() + ansy.size() << endl;

        for(int i = 0; i < ansx.size(); i ++) cout << ansx[i] << " ";
        for(int i = ansy.size() - 1; ~i; i --) cout << ansy[i] << " ";
        cout << endl;
        // break;
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
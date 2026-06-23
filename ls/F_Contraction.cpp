#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

set<int> adj[N];

int f[N];
PII edg[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

int ans = 0;

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(adj[u].size() > adj[v].size()) swap(u, v);
    adj[u].erase(v), adj[v].erase(u);
    f[u] = v;

    ans -= 1 + adj[u].size() + adj[v].size();
    for(auto t : adj[u]) {
        adj[t].erase(u);
        adj[v].insert(t);
    }
    ans += adj[v].size();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    ans = m;
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        edg[i] = {u, v};
        adj[u].insert(v);
        adj[v].insert(u);
    }


    int q; cin >> q;
    while(q --) {
        int x; cin >> x;
        merge(edg[x].first, edg[x].second);
        cout << ans << endl;

        // cerr << q << "--\n";
        // for(int i = 1; i <= n; i ++) {
        //     if(i == find(i)) {
        //         cerr << i << " --- ";
        //         for(auto t : adj[i]) cerr << t << " ";
        //         cerr << endl;
        //     }
        // }
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
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

// vector<vector<int>>adj(N);
map<ll,vector<ll>> adj;
map<ll,bool> vis;
ll ans = 0;

void dfs(ll u) {
    ans = max(u, ans);
    if(vis[u]) return;
    vis[u] = true;

    for(auto v : adj[u]) {
        dfs(v);
    }
}

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        ll x; cin >> x;
        if(i != 1) {
            ll u = x + i - 1;
            ll v = u + i - 1;
            adj[u].push_back(v);
        }
    }
    dfs(n);
    cout << ans << endl;
    ans = 0;
    adj.clear();
    vis.clear();
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
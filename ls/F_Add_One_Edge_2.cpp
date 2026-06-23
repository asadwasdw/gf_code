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

vector<vector<int>>adj(N);
ll cnt = 0;
int d[N], vis[N];

void dfs(int u, int fa) {
    if(d[u] == 2) {
        cnt ++;
    }
    // cout << d[u] << endl;
    if(d[u] != 3) return;
    // cout << u << endl;
    vis[u] = true;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }

}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u] ++, d[v] ++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(vis[i]) continue;
        if(d[i] != 3) continue;
        cnt = 0;
        dfs(i, i);
        // cout << i << " " << cnt << endl;
        ans += (cnt)*(cnt-1)/2;
    }
    cout << ans;







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
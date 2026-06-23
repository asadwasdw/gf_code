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

bool vis[N];
int cnt[N];

void dfs(int u) {
    cnt[u] ++;

    for(auto v : adj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

void solve()
{

    int n;
    cin >> n;

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i ++) {
        vis[i] = true;
        dfs(i);
        vis[i] = false;
    }
    int ans = INF;
    for(int i = 1; i <= n; i ++) {
        if(cnt[i] == n) ans = min(ans, i);
    }
    if(ans == INF) ans = -1;

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
    return 0;
}
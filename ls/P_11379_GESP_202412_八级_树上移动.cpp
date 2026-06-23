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

int c[N];

int dfs(int u, int fa,int k) {
    k -= c[u];
    if(k == -1) return 0;
    int res = 1;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        res = max(res, dfs(v, u, k) + 1);
    }
    // cout << u << " " << k << " " << res << endl;
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i ++) cin >> c[i];

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    // cout << dfs(1, 0, k) << endl;
    for(int i = 1; i <= n; i ++) {
        // cout << dfs(i, 0 ,k) << endl;
        ans = max(ans, dfs(i,0 ,k));
    }
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
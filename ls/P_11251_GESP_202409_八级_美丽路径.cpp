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
int dp[N];
int ans = 0 ;
void dfs(int u, int fa) {
    dp[u] = 1;
    int dis0 = 0, dis1 = 0;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
        if(c[u] != c[v]) {
            int t = dp[v] + 1;
            if(t >= dis0) {
                dis1 = dis0;
                dis0 = t;
            } else if(t > dis1) {
                dis1 = t;
            }
        }
    }
    dp[u] = max(dp[u], dis0);
    ans = max({ans, dis0 + dis1 - 1, dp[u]});
    // cout << u << " " << dis0 << " " << dis1 << endl;
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> c[i];

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

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
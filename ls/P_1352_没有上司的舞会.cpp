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

int r[N];
bool flag[N];
int root;
int dp[N][2];

void dfs(int u) {
    dp[u][1] = r[u];
    for(auto v : adj[u]) {
        dfs(v);
        dp[u][1] += dp[v][0];
        dp[u][0] += max(dp[v][1], dp[v][0]);
    }

    // cout << u << " " << dp[u][0] << " " << dp[u][1] << endl;
}

void solve()
{
    // memset(dp, -0x3f, sizeof dp);
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> r[i];
    }

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
        flag[u] = true;
    }

    for(int i = 1 ; i <= n; i ++) if(flag[i] == 0) root = i;

    dfs(root);

    cout << max(dp[root][1], dp[root][0]);




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
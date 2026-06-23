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
int dp[N], flag[N];

void dfs(int u, int fa) {
    flag[u] |= c[u];
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
        flag[u] |= flag[v];
        if(flag[v]) dp[u] += dp[v];
    }
    if(flag[u] && c[u] == 0) dp[u] ++;

    // cout << u << " " << dp[u] << " " << flag[u] << endl;

}

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 1;
    
    for(int i = 1; i <= n; i ++) {
        if(c[i] == 1) {
            dfs(i, 0);
            root = i;
            break;
        }
    }

    cout << dp[root];





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
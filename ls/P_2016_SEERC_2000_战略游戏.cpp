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

int dis[N];
int dp[N][2];

void dfs(int u, int fa) {
    dp[u][1] = 1;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0], dp[v][1]);
    }
}



void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int u, cnt;
        cin >> u >> cnt;
        while(cnt --) {
            int v;
            cin >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    dfs(0, 0);
    cout << min(dp[0][0], dp[0][1]) << endl;








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
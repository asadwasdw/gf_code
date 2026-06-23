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

int dp[N][2][2]; // u , c, cnt  

/*

void DFS(long long u,long long fa){
	dp[u][0][a[u]]=0;
	dp[u][1][1-a[u]]=1;
	for(int i=0;i<g[u].size();i++){
		long long v=g[u][i];
		if(v==fa)continue;
		DFS(v,u);
		long long a=dp[u][0][0],b=dp[u][0][1],c=dp[u][1][0],d=dp[u][1][1];
		dp[u][0][1]=min(b+dp[v][0][0],a+dp[v][1][0]);
		dp[u][0][0]=min(b+dp[v][1][0],a+dp[v][0][0]);
		dp[u][1][0]=min(c+dp[v][0][1],d+dp[v][1][1]);
		dp[u][1][1]=min(c+dp[v][1][1],d+dp[v][0][1]);
	}
}

*/

int a[N];

void dfs(int u, int fa) {
    int son = 0;
    dp[u][a[u]][0] = 0;
    dp[u][a[u] ^ 1][1] = 1;

    
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, fa);
        son ++;
    }






}

void solve()
{
    int n;
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= n; i ++) cin >> a[i];

    dfs(1, 0);









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
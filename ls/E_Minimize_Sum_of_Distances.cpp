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

vector<vector<int>>edg(N);

int w[N];
int n;

int sum[N],dp[N],dp2[N];
int SUM;


void dfs(int u,int fa){
    sum[u] = w[u];

    for(auto v : edg[u]) {
        if(v == fa) continue;
        dfs(v,u);
        sum[u] += sum[v];
        dp[u] += dp[v] + sum[v];
    }
}
int ans = INF;
void dfs2(int u,int fa){
    ans = min(ans, dp2[u]);
    // cout << u << " "<<dp2[u] << endl;
    for(auto v : edg[u]) {
        if(v == fa) continue;
        dp2[v] = dp[v] + (dp2[u] - dp[v] - sum[v]) + SUM - (sum[v]);
        dfs2(v,u);
       
    }
}


void solve()
{
    cin >> n;
    for(int i = 1; i < n; i ++ ) {
        int x, y; cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    for(int i = 1; i <= n; i ++) cin >> w[i], SUM += w[i];
    dfs(1, -1);
    dp2[1] = dp[1];
    dfs2(1,-1);
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
}
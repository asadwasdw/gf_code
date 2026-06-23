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

bool ish[N];
int dp[N][2];
int dp2[N][2];
// 0 没有
// 1 有

void dfs(int u, int fa){
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(auto v : edg[u]) {
        if(v == fa) continue;
        if(ish[v]) continue;
        dfs(v,u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][1], dp[v][0]);
    }
}



void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        ish[i] = true;
    }

    for(int i = 1; i <= n + m; i ++) {
        int u, v;
        cin >> u >> v;
        u++, v++;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    for(int i = 1; i <= n + m; i ++) {
        if(ish[i]){
            dfs(i,-1);
            // cout << i << " " << dp[i][0] <<" "<< dp[i][1] << endl;
        }
    }
    // 1必选 
    dp2[1][0] = INF;
    dp2[1][1] = dp[1][1];
    for(int i = 2; i <= n; i ++ ) {
        dp2[i][0] = (dp2[i - 1][1]) + dp[i][0];
        dp2[i][1] = min(dp2[i - 1][0], dp2[i - 1][1]) + dp[i][1]; 
    }

    int ans = min(dp2[n][0],dp2[n][1]);

    // 1不选

    dp2[1][0] = dp[1][0];
    dp2[1][1] = INF;
    for(int i = 2; i <= n; i ++ ) {
        dp2[i][0] = (dp2[i - 1][1]) + dp[i][0];
        dp2[i][1] = min(dp2[i - 1][0], dp2[i - 1][1]) + dp[i][1]; 
        // cout << dp2[i][0] << " " << dp2[i][1] << endl;
    }

    // cout << dp2[n][1] << endl;

    ans = min(dp2[n][1], ans);
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
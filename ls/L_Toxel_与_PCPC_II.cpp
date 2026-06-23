#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

using i64 = long long;
void solve()
{
    int n, m; cin >> n >> m;    
    vector<int> vis(n + 1);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        vis[x] = true;
    }
    constexpr int B = 50;
    constexpr i64 inf = 1e18;
    vector dp(n + 1, vector<i64> (B + 1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            for (int j = B; j >= 1; j--) dp[i][j] = dp[i - 1][j - 1];
        } else {
            for (int j = B; j >= 0; j--) dp[i][j] = dp[i - 1][j];
        }
        for (int j = 0; j <= B; j++)
        for (int k = 1; k + j <= B; k++) {
            dp[i][j] = min(dp[i][j], dp[i][j + k] + i + k * k * k * k);
        }
    }
    cout << dp[n][0] << "\n";




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
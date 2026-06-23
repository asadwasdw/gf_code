#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

ll dp[N][N][2][2];
int x[N], y[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    // memset(dp, -0x3f, sizeof dp);

    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            for(int z = 0; z < 2; z ++) {
                for(int k = 0; k < 2; k ++) {
                    dp[i][j][z][k] = -INF;
                }
            }
        }
    }
    dp[0][0][0][0] = dp[0][0][0][1] = 0;

    for(int i = 1; i <= n; i ++) cin >> x[i];
    for(int j = 1; j <= n; j ++) cin >> y[j];

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            for(int z = 0; z < 2; z ++) {
                for(int k = 0; k < 2; k ++) {
                    if(z == 0 && j < m) dp[i][j + 1][1][k] = max(dp[i][j + 1][1][k], dp[i - 1][j][0][k]);
                    if(k == 0) dp[i][j][0][1] = max(dp[i][j][0][1], dp[i - 1][j][z][0] + x[i]);
                    if(k == 1) dp[i][j][0][0] = max(dp[i][j][0][0], dp[i - 1][j][z][1] + y[i]);
                }
            }
        }
    }

    for(int z = 0; z < 2; z ++) {
        for(int k = 0; k < 2; k ++) ans = max(ans, dp[n][m][z][k]);
    }
    cout << ans << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}
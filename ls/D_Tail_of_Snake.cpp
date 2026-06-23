#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> PII;
const int N = 3e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int a[N][4];
long long dp[N][4];

void solve() {
    int n;
    cin >> n;
    for(int j = 1; j <= 3; j ++)
        for(int i = 1; i <= n; i ++) 
            cin >> a[i][j];
            
        
    memset(dp, 0x8f, sizeof dp);
    dp[0][1] = 0;
    // dp[0][2] = dp[0][3] = -INF;

    for(int i = 1; i <= n; i ++) {
        // dp[i][1] = dp[i - 1][1] + a[i][1];
        for(int j = 1; j <= min(i, 3ll); j ++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }

        // cout << dp[i][1] << " " << dp[i][2] << " " << dp[i][3] << endl;
    }
    // cout << max({dp[n][1], dp[n][2], dp[n][3]});
    cout << dp[n][3] << endl; 
    // cout << 12 + 19 + 19 << endl;


}

signed main() {

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
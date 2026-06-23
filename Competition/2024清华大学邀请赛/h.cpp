#include<bits/stdc++.h>
using i64 = long long;
constexpr i64 P = 1e9 + 7;
constexpr int N = 500, M = 5000;

i64 dp[N + 1][M + 1];
void solve() {
    dp[1][0] = 1;
    for (int i = 2; i <= N; i++)
    for (int j = 0; j <= M; j++) {
        for (int k = 1; k <= i; k++) {
            if (j - (i - k) >= 0)
            (dp[i][j] += dp[i - 1][j - (i - k)]) %= P;
        }
    }
    int t; std::cin >> t;
    while (t--) {
        int n, m; std::cin >> n >> m;
        i64 ans = 0;
        for (int j = 0; j <= m; j++) {
            (ans += dp[n][j]) %= P;
        }
        std::cout << ans << "\n";
    }
}


signed main() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(0), std::cin.tie(0);
    int t = 1;
    // std::cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
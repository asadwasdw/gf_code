#include<bits/stdc++.h>
using i64 = long long;
constexpr int B = 500;
constexpr i64 inf = 1e18;
void solve() {
    int n, m, x, y; std::cin >> n >> m >> x >> y;
    std::vector<i64> d(x + 1);
    for (int i = 1; i <= x; i++) std::cin >> d[i];
    std::vector<std::array<int, 2>> p(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> p[i][0] >> p[i][1];
    std::vector<std::array<i64, 3>> g(m + 1);
    for (int i = 1; i <= m; i++) std::cin >> g[i][0] >> g[i][1] >> g[i][2];
    std::vector<int> dep(x + 1);
    for (int i = 1; i <= m; i++) dep[g[i][1]]++;
    std::vector<bool> big(x + 1);
    for (int i = 1; i <= x; i++) if (dep[i] >= B) big[i] = true;
    std::vector<std::vector<std::array<i64, 2>>> edge1(y + 1), edge2(x + 1);
    for (int i = 1; i <= m; i++) {
        auto [p, q, c] = g[i];
        if (big[q]) {
            edge1[p].push_back({q, c});
        } else {
            edge2[q].push_back({p, c});
        }
    }
    std::vector<i64> dp1(y + 1, -inf);
    std::vector<i64> dp2(x + 1);
    i64 mx = 0;
    dp1[0] = 0;
    for (int i = 1; i <= n; i++) {
        auto [a, b] = p[i];
        
        dp1[0] = std::max(dp1[0], mx + d[b]);
        if (big[b]) dp1[0]= std::max(dp1[0], dp2[b] + d[b]);
        else {
            for (auto [p, c] : edge2[b]) {
                dp1[0] = std::max(dp1[0], dp1[p] + c + d[b]);
            }
        }
        
        dp1[a] = std::max(dp1[a], mx);
        for (auto [q, c] : edge1[a]) {
            dp2[q] = std::max(dp2[q], c + dp1[a]);
        }

        mx = std::max(mx, dp1[0]);
    
        
    }
    std::cout << mx << "\n";
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
#include<bits/stdc++.h>
using i64 = long long;
constexpr int P = 998244353;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    
    int n; std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> mi(n + 1, -1);
    for (int i = n; i > 0; i--) {
        if (mi[a[i]] != -1) g[mi[a[i]]].push_back(i);
        else if (mi[a[i]] == -1) {
            g[a[i]].push_back(i);
        }
        mi[a[i]] = i;

    }
    std::vector<int> sz(n + 1);
    auto dfs = [&](auto self, int u, int fa) -> void {
        sz[u] = 1;
        for (auto v : g[u]) {
            if (v == fa) continue;
            // std::cerr << u << ' ' << v << "\n";
            self(self, v, u);
            sz[u] += sz[v];
        }
    };
    auto qpow = [&](i64 a, i64 b) -> i64 {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            b >>= 1;
            a = a * a % P;
        }
        return res;
    };
    dfs(dfs, 0, 0);

    i64 ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = ans * i % P;
    }
    // std::cerr << ans << ' ';
    for (int i = 1; i <= n; i++) {
        // std::cerr << sz[i] << ' ';
        ans = ans * qpow(sz[i], P - 2) % P;
    }
    std::cout << ans << "\n";
    return 0;
}


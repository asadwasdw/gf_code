#include<bits/stdc++.h>
using i64 = long long;
constexpr int B = 500;
constexpr int P = 1e9 + 7;
i64 qpow (i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res;
}
void solve() {
    int n; std::cin >> n;
    std::vector<i64> t(n);
    for (int i = 0; i < n; i++) std::cin >> t[i];
    std::vector<i64> w(n + 1);
    for (int i = 2; i <= n; i++) std::cin >> w[i];

    std::vector<std::vector<std::array<i64, 2>>> g(n);
    for (int i = 0; i < n; i++) {
        auto calc = [&] (i64 x) -> std::vector<std::array<i64, 2>> {
            std::vector<std::array<i64, 2>> res;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int cnt = 0;
                    while (x % i == 0) x /= i, cnt++;
                    res.push_back({i, cnt});
                }
            }
            if (x != 1) res.push_back({x, 1});
            return res;
        };
        g[i] = calc(t[i]);
        
    } 
    std::vector<std::vector<std::array<i64, 2>>> g1(1 << n);
    for (int bit = 1; bit < (1 << n); bit++) {
        auto merge = [&](std::vector<std::array<i64, 2>> a, std::vector<std::array<i64, 2>> b) -> std::vector<std::array<i64, 2>>{
            std::vector<std::array<i64, 2>> res;
            int i = 0, j = 0;
            while (i < a.size() && j < b.size()) {
                if (a[i][0] < b[j][0]) {
                    res.push_back(a[i++]);
                } else if (a[i][0] > b[j][0]) {
                    res.push_back(b[j++]);
                } else {
                    res.push_back({a[i][0], std::max(a[i][1], b[i][1])});
                    i++, j++;
                }
            }
            while (i < a.size()) res.push_back(a[i++]);
            while (j < b.size()) res.push_back(b[j++]);
            return res;
        };
        int s = 0;
        for (int j = 0; j < n; j++) {
            if (bit >> j & 1) {
                s = j;break;
            }
        }
        g1[bit] = merge(g1[bit - (1 << s)], g[s]);
    }
    std::vector<i64> lcm(1 << n);
    for (int bit = 0; bit < (1 << n); bit++) {
        lcm[bit] = 1;
        for (auto [x, y] : g1[bit]) {
            while (y) {
                lcm[bit] = lcm[bit] * x % P, y--;
            }
        }
    }
    i64 inv = qpow (2 * lcm[(1 << n) - 1] % P, P - 2);
    std::vector<i64> f(1 << n);
    for (int bit = 0; bit < (1 << n); bit++) {
        f[bit] = qpow(lcm[bit], P - 2) * 2 % P; 
        std::cerr << f[bit] << ' ' << bit << "\n";
    }
    for (int s = 0; s < (1 << n); s++) {
        for (int t = s + 1; t < (1 << n); t++) {
            if ((s & t) == s) {
                if (__builtin_popcount(t - s) % 2) f[s] -= f[t];
                else f[s] += f[t];
            }
        }
    }
    // for (int d = 1; d < n; d *= 2)
    // for (int i = 0, t = d * 2; i < n; i += t)
    // for (int j = 0; j < d; j++) {
    //     (f[i + j + d] -= f[i + j] - P) %= P;
    // }
    i64 res = 0;
    for (int bit = 0; bit < (1 << n); bit++)
        res = (res + f[bit] * w[__builtin_popcount(bit)] % P ) % P;
    // for (int i = 1; i <= 200; i++)
    // for (int j = 1; j <= 200; j++) {
    //     i64 t = 1ll * i * qpow(j, P - 2) % P;
    //     if (res == t) std::cerr << i << ' ' << j << "\n";
    // }
    std::cout << res<< "\n";
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
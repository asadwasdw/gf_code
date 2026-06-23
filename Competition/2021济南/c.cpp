#include<bits/stdc++.h>

constexpr int P = 998244353;
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cin.tie(nullptr);

    int n; std::cin >> n;
    // std::map<int, int> mp;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    sort(a.begin(), a.end());
    std::vector<std::array<int, 2>> s;
    for (int l = 0, r; l < n; l = r + 1) {
        r = l;
        while (r + 1 < n && a[r + 1] == a[l]) r++;
        s.push_back({a[l], r - l + 1});
    }
    std::vector<i64> fac(n + 1), invfac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % P;
    auto qpow = [&](i64 a, i64 b) -> i64 {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            b >>= 1;
            a = a * a % P;
        }
        return res;
    };
    invfac[n] = qpow (fac[n], P - 2);
    for (int i = n; i > 0; i--) invfac[i - 1] = invfac[i] * i % P;

    auto C = [&](i64 n, i64 m) -> i64 {
        if (n < m || m < 0) return 0;
        return fac[n] * invfac[n - m] % P * invfac[m] % P;
    };
    
    i64 res = 1;
    i64 sum = n;
    for (int i = s.size() - 1; i >= 0; i--) {
        res = res * fac[s[i][1]] % P;
        if (s[i][1] % 2 == 1) sum--, s[i][1]--;
        if (i) res = res * C(sum - s[i][1] / 2, s[i][1] / 2) % P;
        sum -= s[i][1]; 
    }
    std::cout << res << "\n";

    return 0;
}
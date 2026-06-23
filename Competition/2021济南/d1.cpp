#include<bits/stdc++.h>

constexpr int P = 998244353;
using i64 = long long;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cin.tie(nullptr);

    int n; std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) a[i] -= a[0];
    int cnt = 0;
    for (int i = 1; i < n; i++) cnt += a[i] < 0;
    if (cnt >= n / 2) {
        for (int i = 1; i < n; i++) a[i] = -a[i];
        // cnt = n - 1 - cnt;
    }
    std::vector<i64> tmp;
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) tmp.push_back(0);
        else tmp.push_back((a[i] + i - 1) / i);
    }
    sort(tmp.begin(), tmp.end());
    i64 d1 = tmp[(n - 1) / 2], d2 = tmp[(n - 1) / 2 + 1];
    i64 res = 8e18;
    for (int j = d1; j <= d2; j++) {
        i64 ans = 0;
        for (int i = 0; i < n; i++) ans += abs(a[i] - 1ll * j * i);
        res = std::min(res, ans);
        // a[i] -= d1 * i;
    }
    // for (int i = 0; i < n; i++) res += abs(a[i]);
    std::cout << res << "\n";
    return 0;
}
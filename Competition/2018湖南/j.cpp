#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 2e6+10, INF = 0x3f3f3f3f, mod = 1e9+7;

constexpr int P = 1e9 + 7;
using i64 = long long;

void solve() {
    int n, m, l, r;
    while (cin >> n >> m >> l >> r) {
        vector<i64> a(n + 1);
        vector<i64> b(m + 1);
        for (int i = 0; i <= n; i++) cin >> a[i];
        for (int j = 0; j <= m; j++) cin >> b[j];
        for (int j = 1; j <= m; j++) (b[j] += b[j - 1]) %= P;
        i64 ans = 0;
        for (int i = 0; i <= n; i++) {
            int u = l - i, v = r - i;
            if (u > m || v < 0) continue;
            u = max(u, 0);
            v = min(v, m);
            ans += a[i] * (b[v] - (u == 0 ? 0 : b[u - 1])) % P;

            ans = (ans % P + P) % P;
        }
        cout << ans << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
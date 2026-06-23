#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
#define endl "\n"
constexpr i64 P = 1e9 + 7;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res;
}
void solve() {
    int n, m, k; 
    while(cin >> n >> m >> k){
        i64 ans = 0;
        vector<i64> bit3(k + 1);
        for (int i = 0; i < k; i++) {
            bit3[i] = qpow(3, 1 << i);
        }
        for (int t = 0; t < n; t++) {
            vector<i64> a(m);
            for (int i = 0; i < m; i++) cin >> a[i];
            vector<i64> dp(1 << m);
            dp[0] = 1;
            for (int i = 0; i < k; i++) {
                auto nx = dp;
                for (int s = 0; s < (1 << m); s++) {
                    int nxs = s;
                    for (int j = 0; j < m; j++) {
                        if ((a[j] >> i & 1)) {
                            nxs ^= (1 << j);
                        }
                    }   
                    nx[nxs] = (nx[nxs] + dp[s] * bit3[i] % P) % P;
                }
                swap(dp, nx);
            }
            ans = (ans + dp[(1 << m) - 1]) % P;
        }
        cout << ans << "\n";
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}
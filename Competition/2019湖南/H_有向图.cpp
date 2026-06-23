#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
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
    int n, m;
    while (cin >> n >> m) {
        vector a(n + m, vector<i64> (n + m));
        i64 inv = qpow(10000, P - 2);
        for (int i = 0; i < n; i++)
        for (int j = 0; j < n + m; j++) {
            cin >> a[i][j];
            a[i][j] = a[i][j] * inv % P;
        }
        auto b = a;
        for (int i = 0; i < n + m; i++)
        for (int j = 0; j < n + m; j++) {
            b[i][j] = (-b[i][j] + P + (i == j)) % P;
        }
        for (int i = 0; i < n + m; i++) {
            b[i].resize(2 * (n + m));
            b[i][i + n + m] = 1;
        }
        auto gauss = [&](vector<vector<i64>> a) -> vector<vector<i64>> {
            int n = a.size();
            int m = (int)a[0].size() - 1;
   
            vector<int> where(m, -1);
            for (int col = 0, row = 0; col < m && row < n; ++col) {
                int sel = row;
                for (int i = row; i < n; i++) {
                    if (a[i][col] > a[sel][col]) {
                        sel = i;
                    }
                }
                if (a[sel][col] == 0) continue;
                for (int i = col; i <= m; i++) {
                    swap(a[sel][i], a[row][i]);
                }
                where[col] = row;
                for (int i = 0; i < n; i++) {
                    if (i != row) {
                        i64 c = a[i][col] * qpow(a[row][col], P - 2) % P;
                        for (int j = col; j <= m; j++) {
                            a[i][j] = (a[i][j] - a[row][j] * c % P + P) % P;
                        }
                    }
                }
                ++row;
            }
    
            vector ans(n, vector<i64> (n));
            for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                ans[i][j] = a[i][j + n] * qpow(a[i][i], P - 2) % P;
                
            }

            return ans;
        };
        auto c = gauss(b);
        auto mul = [&](auto a, auto b) -> vector<vector<i64>>{
            vector ans(n + m, vector<i64> (n + m));
            for (int i = 0; i < n + m; i++)
            for (int j = 0; j < n + m; j++) {
                if (a[i][j] == 0) continue;
                for (int k = 0; k < n + m; k++) {
                    ans[i][k] = (ans[i][k] + a[i][j] * b[j][k] % P) % P;
                }
            }
            return ans;
        };

        auto ans = mul(a, c);
        for (int i = n; i < n + m; i++) cout << ans[0][i] << " \n"[i == n + m - 1];
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
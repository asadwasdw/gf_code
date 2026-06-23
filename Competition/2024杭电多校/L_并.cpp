#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using db = double;
constexpr i64 P = 998244353, inf = 1e9;

void solve(){
    int N; cin >> N;
    vector<int> x, y;
    x.push_back(0), y.push_back(0);
    x.push_back(inf), y.push_back(inf);
    vector<array<int, 4>> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        x.push_back(a[i][0]);
        x.push_back(a[i][2]);

        y.push_back(a[i][1]);
        y.push_back(a[i][3]);
    }    


    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    int n = x.size(), m = y.size();
    vector<vector<short>> sum(n + 1, vector<short> (m + 1));
    for (int i = 0; i < N; i++) {
        auto &[x1, y1, x2, y2] = a[i];
        x1 = lower_bound(x.begin(), x.end(), x1) - x.begin();
        x2 = lower_bound(x.begin(), x.end(), x2) - x.begin();
        y1 = lower_bound(y.begin(), y.end(), y1) - y.begin();
        y2 = lower_bound(y.begin(), y.end(), y2) - y.begin();
        // cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        sum[x1][y1]++, sum[x1][y2]--, sum[x2][y1]--, sum[x2][y2]++;
    }
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        sum[i][j] += sum[i][j - 1];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        sum[i][j] += sum[i - 1][j];

    vector<i64> val(N + 1);
    for (int i = 1; i < n - 1; i++)
    for (int j = 1; j < m - 1; j++) {
        val[sum[i][j]] = (val[sum[i][j]] + 1ll * (x[i + 1] - x[i]) * (y[j + 1] - y[j]) % P) % P; 
    }
    auto qpow = [&](i64 a, i64 b) -> i64 {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            b >>= 1;
            a = a * a % P;
        }
        return res;
    };
    vector<i64> fac(N + 1), invfac(N + 1);
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i % P;
    invfac[N] = qpow(fac[N], P - 2);
    for (int i = N - 1; i >= 0; i--) invfac[i] = invfac[i + 1] * (i + 1) % P;
    auto C = [&](int n, int m) ->i64 {
        if (n < m) return 0;
        return fac[n] * invfac[m] % P * invfac[n - m] % P;
    };
    // for (int i = 1; i <= N; i++) cout << val[i] << " \n"[i == N];
    for (int i = 1; i <= N; i++) {
        i64 ans = 0;
        for (int j = 1; j <= N; j++) {
            ans = (ans + (1 - C(N - j, i) * fac[i] % P * fac[N - i] % P * invfac[N] % P + P) % P * val[j] % P) % P;
        }
        ans = (ans % P + P) % P;
        cout << ans << "\n";
    }
    // cout << 5 * qpow(3, P - 2) % P << endl;
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}

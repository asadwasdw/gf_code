#include<bits/stdc++.h>
#define endl '\n'
using ll = long long;
using i64 = long long;
using namespace std;
constexpr int N = 2e6 + 10;
constexpr int P = 998244353;
i64 qpow(i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res;
}
i64 fac[N], invfac[N];
void init1() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % P;
    invfac[N - 1] = qpow (fac[N - 1], P - 2);
    for (int i = N - 1; i > 0; i--) invfac[i - 1] = invfac[i] * i % P;
}

int mu[N], p[N], pe[N];
std::vector<int> pr;
void compute(int n, function<void(int)> calcpe) {
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i == pe[i]) calcpe(i);
        else mu[i] = mu[pe[i]] * mu[i / pe[i]];
    }
}
void init2(int n) {
    p[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!p[i]) p[i] = i, pe[i] = i, pr.push_back(i);
        for (auto j : pr) {
            if (i * j > n) break;
            p[i * j] = j;
            if (p[i] == j) {
                pe[i * j] = pe[i] * j;
                break;
            } else {
                pe[i * j] = j;
            }
        }
    }
    compute(n, [&](int x) {
        if (p[x] == pe[x]) mu[x] = -1;
        else mu[x] = 0;
    });
}
i64 C(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac[n] * invfac[n - m] % P * invfac[m] % P;
}
int check(int m, int n) {
    int ans = 0;
    auto dfs = [&](auto self, vector<int> s, int idx) {
        if (s.size() == n) {
            while(s.size()) {
                int gd = 0;
                for (auto x : s) gd = __gcd(x, gd);
                if (gd == *s.begin()) {
                    s.erase(s.begin());
                } else {
                    break;
                }
            }
            ans += s.size();
            return;
        }
        if (idx > m) {
            return;
        }
        self(self, s, idx + 1);
        s.push_back(idx);
        self(self, s, idx + 1);
        return;
    };
    dfs(dfs, vector<int> (), 1);
    return ans;
}
void solve(){
    init1();
    init2(N - 1);
    int m, n; std::cin >> m >> n;
    // if (n == 1) {
    //     std::cout << 0 << "\n";
    //     return;
    // }
    // std::cout << check(m, n) << ' ';
    i64 ans = n * C(m, n) % P;
    std::vector<i64> f(m + 1, 1);
    f[0] = 0;
    std::vector<std::vector<int>> gd(m + 1);
    for (int i = 1; i <= m; i++)
    for (int j = i; j <= m; j += i) {
        gd[j].push_back(i);
    }

    for (int T = 1; T <= min(n, 20); T++) {
        // std::cerr << ans << "\n";

        for (int i = 1; i <= m; i++) {
            if (!f[i]) continue;
            i64 tmp = C(m / i - 1, n - T);
            // for (int j = i; j <= m; j += i) {
            //     tmp = (tmp + mu[j / i] * C(m / j - (i == j), n - T) % P) % P;
            // }
            // for (auto d : gd[m / i]) {
            //     // std::cerr << mu[d] << ' ' << C(m / i / d - 1, n - T) << '\n';
            //     tmp = (tmp + mu[d] * C(m / i / d - 1, n - T) % P) % P;
            // }
            
            // std::cerr << i << ' ' << tmp << "\n"; std::cerr << "\n";
            ans = ((ans - tmp * f[i] % P) % P + P) % P;
        }

        std::vector<i64> g(m + 1);
        for (int i = 1; i <= m; i++) {
            if (!f[i]) continue;
            for (int j = i + i; j <= m; j += i) {
                g[j] = (g[j] + f[i]) % P;
            }
        }
        std::swap(f, g);
    }
    std::cout << ans << "\n";
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
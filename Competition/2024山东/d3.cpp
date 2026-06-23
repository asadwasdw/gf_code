#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 2e6 + 10, mod = 1e9+7;

using i64 = long long;
constexpr int B = 2e5;
void solve(){
    i64 p, a, b, q, c, d, m, t;
    cin >> p >> a >> b >> q >> c >> d >> m >> t;
    if (m < p) {
        cout << m << "\n";
        return;
    }

    __int128_t ans = m;
    __int128_t cnt = m;
    __int128_t sumk = 0, sumcnt = 0;
    while (1) {
        auto calc_next = [&](__int128_t x) -> array<__int128_t, 2> {
            __int128_t lenk = 0, nxcnt = 0;
            lenk = (p + (__int128_t)(q - p) * (x / p) - 1 ) / ((q - p) * (x / p));
            nxcnt = x + (q - p) * (x / p) * lenk;
            return {lenk, nxcnt};
        };
        auto [lenk, nxcnt] = calc_next(cnt);
        // cerr << lenk << ' ';
        __int128_t lk = sumk + 1, rk = lk + lenk;
        bool ok = false;
        auto calc = [&](__int128_t l, __int128_t r, __int128_t k2, __int128_t b2) -> __int128_t {
            if ((t - l * (b + d)) / (a + c) <= 0) ok = true;
            if ((t - l * (b + d)) / (a + c) <= k2 * l + b2) return (t - l * (b + d)) / (a + c);
            if ((t - r * (b + d)) / (a + c) >= k2 * r + b2) return k2 * r + b2;
            __int128_t lo = l, ro = r;
            ok = true;
            while (lo < ro) {
                __int128_t m = lo + ro >> 1;
                if ((t - m * (b + d)) / (a + c) <= k2 * m + b2) ro = m;
                else lo = m + 1;
            }
            lo = max(l, lo - 10);
            __int128_t ans = -1e18;
            for (__int128_t i = lo; i <= lo + 20; i++) {
                ans = max(ans, min((t - i * (b + d)) / (a + c), k2 * i + b2));
            }
            return ans;
        };
        ans = max(ans, calc(lk, rk, cnt / p, sumcnt) * (q - p) + m);
        if (ok) break;

        sumcnt += lenk * (cnt / p);
        cnt = nxcnt;
        sumk += lenk;
    }
    cout << (i64)ans << "\n";

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
// #define int long long
typedef pair<int,int> PII;
constexpr int N = 5000;
const int mod = 998244353;



using i64 = long long;
void solve() {
    string k; cin >> k;
    int P, x;cin >> P >> x;
    
    vector C(N + 1, vector<i64> (N + 1));
    C[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
        }
    }
    vector<i64> cnt(P);
    for (int a = 0; a < P; a++)
    for (int b = 0; b <= a; b++) {
        cnt[C[a][b]]++;
    }
    vector<i64> a(P);
    vector<i64> ans(P);
    a = cnt;
    ans[1] = 1;
    auto mul = [&](auto &x, auto y) -> void {
        vector<i64> c(P);
        for (int j = 1; j < P; j++) {
            if (!x[j]) continue;
            for (int k = 1; k < P; k++) {
                c[j * k % P] = (c[j * k % P] + x[j] * y[k] % mod) % mod;
            }
        }
        x = c;
    };
    for (int i = k.size() - 1; i >= 0; i--) {
        if (k[i] == '1') {
            mul(ans, a);
        }
        mul(a, a);
    }
    cout << ans[x] << '\n';
} 

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
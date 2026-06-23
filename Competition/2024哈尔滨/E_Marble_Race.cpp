#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(),x.end()
typedef long long i64;
typedef pair<i64, i64> pii;

const int mod = 1000000007;
i64 inv(i64 x) {
    i64 ret = 1, p = mod - 2;
    while(p) {
        if(p & 1) ret = ret * x % mod;
        x = x * x % mod; p >>= 1;
    } return ret;
}
i64 n, m, x[501], v[501], invv[501], invi[501];
i64 dp[501], pi[501];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        invi[i] = inv(i);
    }
    for(int i = 1; i <= m; i++) {
        cin >> v[i];
        invv[i] = inv(v[i]);
    }
    vector<pii> t;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            t.push_back({j, i});
    sort(all(t), [](const pii &A, const pii &B){
        // tA < tB : -x[A.second] * v[B.first] < -x[B.second] * v[A.first]
        return -x[A.second] * v[B.first] < -x[B.second] * v[A.first];
    });
    dp[0] = 1; i64 ans = 0, in = invi[n];
    for(auto p : t) {
        int ball = p.first, pos = p.second;
        for(int i = 0; i < m; i++) {
            dp[i] = dp[i] * n % mod * invi[n - pi[ball]] % mod;
            dp[i + 1] = (dp[i + 1] - dp[i] * pi[ball] % mod * in % mod + mod) % mod;
        }
        i64 time = (-x[pos]) * invv[ball] % mod;
        ans = (ans + dp[m / 2] * time % mod) % mod;
        pi[ball] += 1;
        for(int i = m - 1; i >= 0; i--) {
            dp[i + 1] = (dp[i + 1] + dp[i] * pi[ball] % mod * in % mod) % mod;
            dp[i] = dp[i] * (n - pi[ball]) % mod * in % mod;
        }
    }
    cout << ans * in % mod << endl;
    return 0;
}
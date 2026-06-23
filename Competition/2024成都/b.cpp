#include<bits/stdc++.h>
using i64 = long long;
constexpr int P = 1e9 + 7;
void solve() {
    int n, q; std::cin >> n >> q;
    std::string s; std::cin >> s;
    std::vector dp(3, std::vector (n + 1, std::vector<i64> (n + 1)));
    if (s[0] == '?') dp[0][1][0] = dp[1][0][1] = dp[2][0][0] = 1;
    else if (s[0] == 'a') dp[0][1][0]++;
    else if (s[0] == 'b') dp[1][0][1]++;
    else if (s[0] == 'c') dp[2][0][0]++;
    for (int id = 1; id < s.size(); id++) {
        std::vector ndp(3, std::vector (n + 1, std::vector<i64> (n + 1)));
        if (s[id] == 'a' || s[id] == '?') {
            for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++) {
                (ndp[0][i + 1][j] += dp[1][i][j] + dp[2][i][j]) %= P;
            }
        }
        if (s[id] == 'b' || s[id] == '?') {
            for (int i = 0; i <= n; i++)
            for (int j = 0; j < n; j++) {
                (ndp[1][i][j + 1] += dp[0][i][j] + dp[2][i][j]) %= P;
            }
        }
        if (s[id] == 'c' || s[id] == '?') {
            for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) {
                (ndp[2][i][j] += dp[0][i][j] + dp[1][i][j]) %= P;
            }
        }
        std::swap(ndp, dp);
    }
    std::vector ans(n + 1, std::vector<i64> (n + 1));
    int cnta = std::count(s.begin(), s.end(), 'a');
    int cntb = std::count(s.begin(), s.end(), 'b');
    int cntc = std::count(s.begin(), s.end(), 'c');
    for (int i = cnta; i <= n; i++)
    for (int j = cntb; j <= n; j++){
        ans[i][j] = (dp[0][i][j] + dp[1][i][j] + dp[2][i][j]) % P;
    }
    // for (int i = 0; i <= n; i++)
    // for (int j = 0; j <= n; j++) std::cerr << ans[i][j] << " \n"[j == n];
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= n; j++)
        (ans[i][j] += ans[i - 1][j]) %= P;
    // for (int i = 0; i <= n; i++)
    // for (int j = 1; j <= n; j++)
    //     (ans[i][j] += ans[i][j - 1]) %= P;

    while (q--) {
        int a, b, c; std::cin >> a >> b >> c;
        a += cnta, b += cntb, c += cntc;
        a = std::min(a, n);
        b = std::min(b, n);
        c = std::min(c, n);
        
        i64 res = 0;
        for (int j = cntb; j <= b; j++) {
            int l = std::max(cnta, n - j - c), r = std::min(a, n - j - cntc);
            // std::cerr << l << ' ' << r << "\n";
            if (l <= r) res += ans[r][j];
            if (l <= r && l != 0) res -= ans[l - 1][j];
            res = (res % P + P) % P;
        }

        // for (int i = cnta; i <= a; i++)
        // for (int j = cntb; j <= b; j++) {
        //     if (n - i - j >= cntc && n - i - j <= c) {
        //         res += ans[i][j];
        //     }
        // }
        std::cout << res << "\n";
        // std::cout << ans[std::min(n, a + cnta)][std::min(n, b + cntb)] << "\n";
    }
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    int t;t=1;
    // std::cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
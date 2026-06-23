#include<bits/stdc++.h>
using i64 = long long;

void solve() {
    int n; std::cin >> n;
    i64 m; std::cin >> m;
    std::vector<std::array<i64, 3>> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a.begin(), a.end());
    i64 ans = 0;
    {
        i64 cnt = m, res = 0;
        for (int i = 0; i < n - 1; i++) {
            res += a[i][0] * a[i][1];
            cnt -= a[i][1];
        }
        res += a[n - 1][0] * cnt;
        ans = std::max(ans, res);
    }
    {
        i64 cnt = m, res = 0;
        for (int i = 0; i < n; i++) {
            res += a[i][0] * a[i][1];
            cnt -= a[i][1];
        }
        std::vector<std::array<i64, 4>> suf;
        for (int i = n - 1; i >= 0; i--) {
            auto it = lower_bound(suf.begin(), suf.end(), std::array<i64, 4>{a[i][1] + cnt, 0ll, 0ll, 0ll});

            if (it == suf.end()) {
                if (it != suf.begin()) {
                    it--;
                    ans = std::max(ans, res - a[i][0] * a[i][1] + (*it)[3] + (*it)[1] * (*it)[2]);
                }
            }else {
                ans = std::max(ans, res - a[i][0] * a[i][1] + (*it)[3] + (a[i][1] + cnt - ((*it)[0] - (*it)[2]))* (*it)[1]);
            }            

            if (suf.empty()) {
                suf.push_back({a[i][2] - a[i][1], a[i][0], a[i][2] - a[i][1], 0});
            } else {
                suf.push_back({suf.back()[0] + a[i][2] - a[i][1], a[i][0], a[i][2] - a[i][1],suf.back()[1] * suf.back()[2] + suf.back()[3]});
            }
        }
    }
    std::cout << ans << "\n";
}


signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    std::cout << std::setprecision(11) << std::fixed;
    int t;t=1;
    // std::cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
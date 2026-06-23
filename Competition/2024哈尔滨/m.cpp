#include<bits/stdc++.h>
using i64 = long long;
void solve()
{
    int n; std::cin >> n;
    std::vector<int> a, b;
    for (i64 i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            if (i * i != n) b.push_back(n / i);
        }
    }
    // sort(a.begin(), a.end());
    a.insert(a.end(), b.rbegin(), b.rend());
    a.push_back(n + 1);
    i64 ans = 0;
    for (int i = 0; i < (int)a.size() - 1; i++) {
        ans += (1ll * n / a[i]) * (a[i + 1] - a[i]);
    }
    std::cout << ans << "\n";
}


signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
    std::cout << std::setprecision(11) << std::fixed;
    int t;t=1;
    std::cin>>t;
    for(int i=1;i<=t;i++){
        solve();
    }
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<double> c(n);
    vector<vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        int x;
        cin >> x;
        int zero = 0;
        for (int j = 0; j < x; ++j) {
            int p;
            cin >> p;
            if (p)
                a[i].push_back(p);
            else
                ++zero;
        }
        c[i] = 1. * c[i] * x / (x - zero);
    }
    vector<double> dp(m, 0);
    for (int i = m - 1; i >= 0; --i) {
        double ans = 1e18;
        for (int j = 0; j < n; ++j) {
            double tmp = 0;
            for (auto& k : a[j]) {
                tmp += (i + k >= m ? 0 : dp[i + k]) + c[j];
            }
            tmp /= a[j].size();
            ans = min(ans, tmp);
        }
        dp[i] = ans;
        cout<<i<<" "<<dp[i]<<endl;
    }
    cout << fixed << setprecision(10) << dp[0] << '\n';
 
    return 0;
}
 
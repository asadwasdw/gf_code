#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e6+10, mod = 1e9+7;


using i64 = long long;
void solve(){
    string s;
    while (cin >> s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        vector dp(n, vector<i64> (2));
        if (s[0] == '0') {
            dp[0][0] = 1;
        } else if (s[0] == '1') {
            dp[0][1] = 1;
        } else if (s[0] == '?') {
            dp[0][0] = dp[0][1] = 1;
        }
        auto add = [&](i64 &x, i64 y) -> void {
            x += y;
            if (x > mod) x -= mod;
        };
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                dp[i] = dp[i - 1];
            } else if (s[i] == '1') {
                dp[i] = dp[i - 1];
                if ((i & (n - 1)) == i) {
                    swap(dp[i][0], dp[i][1]);
                }
            } else {
                dp[i] = dp[i - 1];
                if ((i & (n - 1)) == i) {
                    add(dp[i][0], dp[i - 1][1]);
                    add(dp[i][1], dp[i - 1][0]);
                } else {
                    add(dp[i][0], dp[i - 1][0]);
                    add(dp[i][1], dp[i - 1][1]);    
                }
            }
        }
        cout << dp[n - 1][1] << "\n";
    }

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
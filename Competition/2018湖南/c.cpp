#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 2e6+10, INF = 0x3f3f3f3f, mod = 1e9+7;

void chmax(int &x, int y) {
    if (x < y) x = y;
}
// int dp[10][10], ndp[10][10];
// string s[1005];
void solve() {
    int n, m;
    while (cin >> n >> m) {
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        int mx1 = 0, mx2 = 0;
        auto calc = [&](string s1, string s2, const char &c1, const char &c2) -> int {
            int n = s1.size();
            int mx = 0;
            for (int i = 0; i < n - 2; i++) {
                if (s1[i] == c1 && s1[i + 2] == c1 && s2[i + 1] == c2) {
                    s1[i] = s1[i + 2] = s2[i + 1] = '-';
                    mx++;
                } 
                if (s2[i] == c2 && s2[i + 2] == c2 && s1[i + 1] == c1) {
                    s2[i] = s2[i + 2] = s1[i + 1] = '-';
                    mx++;
                } 
            }
            return mx;
        };
        
        for (int i = 1; i < n; i++)
            mx1 += calc(s[i - 1], s[i], '^', 'v');
        for (int j = 1; j < m; j++) {
            string s1, s2;
            for (int i = 0; i < n; i++) {
                s1 += s[i][j - 1];
                s2 += s[i][j];
            }
            mx2 += calc(s1, s2, '<', '>');
        }
        cout << mx1 + mx2 << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
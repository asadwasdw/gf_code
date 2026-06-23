#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 2e6+10, INF = 0x3f3f3f3f, mod = 1e9+7;

using i64 = long long;

void solve() {
    int n, m, q;
    while (cin >> n >> m >> q) {
        vector<array<int, 2>> a(m + 1);
        for (int i = 1; i <= m; i++) {
            cin >> a[i][0] >> a[i][1];
        }
        vector p(m + 1, vector<int> (n + 1));
        vector fa(m + 1, vector<int> (n + 1));
        iota(p[0].begin(), p[0].end(), 0);
        iota(fa[0].begin(), fa[0].end(), 0);
        for (int i = 1; i <= m; i++) {
            p[i] = p[i - 1];
            for (int l = a[i][0], r = a[i][1]; l < r; l++, r--) {
                swap(p[i][l], p[i][r]);
            }
            for (int j = 1; j <= n; j++) {
                fa[i][j] = p[i][j];
            }
        }
        vector<int> vis(n + 1);
        vector<int> val(n + 1);
        int cnt = 0;
        vector<int> be(n + 1);
        vector mp(m + 1, vector<int> (n + 1));
        for (int t = 1; t <= n; t++) {
            if (vis[t]) continue;
            int u = t;
            vector<int> tmp;
            do {
                tmp.push_back(u);
                vis[u] = true;
                u = p[m][u];
            } while (u != t);
            int beg = 0;
            cnt++;
            for (auto x : tmp) {
                val[x] = beg++;
                be[x] = cnt;
            }
            int len = tmp.size();
            for (int i = 0; i < m; i++) {
                for (auto x : tmp) {
                    if (be[x] == be[fa[i][x]]) {
                        int y = val[x] - val[fa[i][x]];
                        if (y <= 0) y += len;
                        mp[i][y]++;
                    }
                }
            }
        }
        
        vector<vector<array<int, 2>>> res(m + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 1; j <= n; j++) {
                if (mp[i][j]) res[i].push_back({j, mp[i][j]});
            }
        }
        for (int i = 0; i <= m; i++)
        for (int j = 1; j <= n; j++)
        for (int k = j + j; k <= n; k += j) {
            mp[i][k] += mp[i][j];
        }
        
        while (q--) {
            int k; cin >> k;
            int x = (k % m), y = (k - x) / m;
            int ans = 0;
            if (y <= n) ans = mp[x][y];
            else {
                for (auto [z, t] : res[x]) {
                    if (y % z == 0) ans += t;
                }
            }
            cout << ans << "\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
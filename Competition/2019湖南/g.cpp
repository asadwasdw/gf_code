#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
#define endl "\n"

void solve() {
    int n, m;
    while (cin >> n >> m) {
        
        vector a(n, vector<int> (m));
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

        vector<set<int>> s(m);
        vector<vector<int>> t(n);
        
        for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] > a[i + 1][j]) {
                s[j].insert(i);
                t[i].push_back(j);
            }
        }
        
        vector<int> ans;
        vector<int> p(m);
        vector<int> vis(m);
        vector<int> del(n);
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < m; i++) {
            sort(p.begin(), p.end(), [&](int i, int j) {
                if (vis[i] && !vis[j]) return false;
                if (!vis[i] && vis[j]) return true;
                if (s[i].size() == s[j].size()) return i < j;
                return s[i].size() < s[j].size();
            });
            // for (auto x : p) {
            //     cout << x << ' ';
            // }cout << "\n";
            // for (int i = 0; i < m; i++) {
            //     cerr << vis[i] << " \n"[i == m - 1];
            // }
            // for (int i = 0; i < m; i++) {
            //     cerr << s[i].size() << " \n"[i == m - 1];
            // }
            if (s[p[0]].empty()) {
                ans.push_back(p[0]);
                vis[p[0]] = true;
                for (int j = 0; j < n - 1; j++) {
                    if (a[j][p[0]] < a[j + 1][p[0]]) {
                        auto dele = [&](int x) -> void {
                            if (del[x]) return;
                            del[x] = true;
                            for (auto id : t[x]) {
                                s[id].erase(x);
                            }
                        };
                        dele(j);
                    }
                }
            } else {
                break;
            }
        }
        if (ans.size() == m) {
            for (auto x : ans) cout << x + 1 << " "; cout << "\n";
        } else {
            cout << "-1\n";
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; 
    // cin >> t;
    while (t--) {
        solve();
    }
}
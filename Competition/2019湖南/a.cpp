#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using i64 = long long;
#define endl "\n"

void solve() {
    int n, m;
    while (cin >> n >> m) {
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        int lx = -1, ly = -1, rx = -1, ry = -1;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '1') {
                if (lx == -1) lx = i, ly = j;
                rx = i, ry = j;
            }
        }
        bool ok =  true;
        for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (i < lx || i > rx || j < ly || j > ry) {
                if (s[i][j] == '1') ok = false;
            } else {
                if (s[i][j] == '0') ok = false;
            }
        }
        if (ok && lx != -1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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
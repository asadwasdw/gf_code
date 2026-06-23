#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
using i64 = long long;
const int mod = 1e9 + 7;
#define endl "\n"



void solve() {
    int n, m, k; std::cin >> n >> m >> k;
    std::vector<int> vis(k + 1);
    int cnt = 0;
    std::map<std::array<int, 2>, int> edge;
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        vis[x]++;
    }
    std::vector<int> dep(k + 1);
    for (int i = 0; i < m; i++) {
        int u, v; std::cin >> u >> v;
        if (u > v) std::swap(u, v);
        if (vis[u] && vis[v]) {
            cnt++;
        } else if (vis[u]) {
            dep[v]++;
        } else if (vis[v]) {
            dep[u]++;
        } else {
            if (u == v) {
                dep[u]++;
                continue;
            }
            edge[{u, v}]++;
        }
    }
    auto tmp = dep;
    sort(tmp.rbegin(), tmp.rend());
    int res = 0;
    if (k == 1) {
        res = cnt + tmp[0];
    } else {
        res = cnt + tmp[0] + tmp[1];
    }
    for (auto [_, val] : edge) {
        auto [u, v] = _;
        res = std::max(cnt + dep[u] + dep[v] + val, res);
    }
    std::cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t --) {
        solve();
    }
}
#include<bits/stdc++.h>
#define endl '\n'
using ll = long long;
using i64 = long long;
using namespace std;
constexpr int N = 2e6 + 10;



void solve(){
    
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    std::vector<int> d(n+1);
    for (int i = 1; i < n; i++) {
        int u, v; std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        d[v]++;
        d[u]++;
    }
    int mx = -1, rt = 1, rtt = -1;
    for(int i=1; i<=n; ++i){
        if(mx < d[i])mx = d[i], rt = i;
        if(d[i] % 2 == 0)rtt = i;
    }
    std::vector<std::array<int, 2>> ans;
    std::vector<int> last(n + 1);
    bool ok = true;
    auto dfs = [&](auto self, int u, int fa) -> void {
        std::vector<std::array<int, 2>> tmp;
        for (auto v : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
            tmp.push_back({last[v], v});
        }
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i + 1< tmp.size(); i += 2) {
            int u = tmp[i][0] == 0 ? tmp[i][1] : tmp[i][0];
            int v = tmp[i + 1][0] == 0 ? tmp[i + 1][1] : tmp[i + 1][0];
            ans.push_back({u, v});
        }
        if (tmp.size() % 2) {
            if (tmp.back()[0] == 0) last[u] = tmp.back()[1];
            else last[u] = tmp.back()[0];
        }
        if (fa == 0) {
            if (last[u]) {
                if (last[u] != tmp.back()[1]) {
                    ans.push_back({u, last[u]});
                } else {
                    ok = false;
                }
            }
        }
    };
    dfs(dfs, (rtt != -1 ? rtt : rt), 0);
    if (ok) {
        std::cout << ans.size() << "\n";
        for (auto [u, v] : ans) {
            std::cout << u << ' ' << v << "\n";
        }
    } else {
        std::cout << -1 << "\n";
    }

    // [&](){
    //     vector<int> dep(n+1);
    //     auto dfs = [&](auto dfs, int u, int fa) -> void {
    //         st[u] = true;
    //         for(auto v : g[u]){
    //             if(v == fa)continue;

    //         }
    //     };
    // }();
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
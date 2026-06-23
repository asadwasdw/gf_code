#include<bits/stdc++.h>
using i64 = long long;

constexpr i64 inf = 1e18;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::vector<i64>> a(n, std::vector<i64>(n, inf));
    for (int i = 0; i < n; i++) a[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w; std::cin >> u >> v >> w;
        u--, v--;
        a[u][v] = a[v][u] = std::min(a[u][v], (i64)w);
    }
    i64 k, t; std::cin >> k >> t;
    std::vector<int> d(k);
    for (int i = 0; i < k; i++) {
        std::cin >> d[i];
        d[i]--;
        for (int j = 0; j < i; j++) {
            a[d[i]][d[j]] = a[d[j]][d[i]] = std::min(a[d[i]][d[j]], (i64)t);
        }
    }

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    for (int k = 0; k < n; k++)
        a[i][j] = std::min(a[i][j], a[i][k] + a[k][j]);

    std::priority_queue<std::array<i64, 3>> que;


    int q; std::cin >> q;
    
    while (q--) {
        int op; std::cin >> op;
        if (op == 1) {
            i64 u, v, w; std::cin >> u >> v >> w;
            u--, v--;
            if (a[u][v] > w) {
                que.push({-w, u, v});
                a[u][v] = a[v][u] = std::min(a[u][v], w);
            }
        } else if (op == 2) {
            int x; std::cin >> x;
            x--;
            for (int j = 0; j < d.size(); j++) {
                if (a[x][d[j]] > t){
                    a[x][d[j]] = a[d[j]][x] = std::min(a[x][d[j]], (i64)t);
                    que.push({-t, x, d[j]});

                }
            }
            d.push_back(x);
        } else {
            while (que.size()) {
                auto [w, u, v] = que.top(); que.pop();
                w = -w;
                if (a[u][v] < w) continue;
                for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (a[i][j] > a[i][u] + a[u][v] + a[v][j]) {
                        a[i][j] = a[j][i] = std::min(a[i][j], a[i][u] + a[u][v] + a[v][j]);
                        que.push({-a[i][j], i, j});

                    }
                }
            }
            i64 ans = 0;
            for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (a[i][j] == inf) continue;
                ans += a[i][j];
            }
            std::cout << ans << "\n";
        }
    }

    return 0;
}


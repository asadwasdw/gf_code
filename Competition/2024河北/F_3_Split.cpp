#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::cin >> a[i][j];
            a[j][i] = a[i][j] ^ 1;
        }
    }
    
    int x = 0;
    std::vector<int> vis(n);
    vis[0] = 1;
    for (int y = 1; y < n; y++) {
        if (vis[y]) {
            continue;
        }
        for (int z = 1; z < n; z++) {
            if (vis[z]) {
                continue;
            }
            if (y == z) {
                continue;
            }
            if (!a[x][y] || !a[y][z] || !a[z][x]) {
                continue;
            }
            vis[y] = vis[z] = 1;
            std::vector<int> f(n);
            for (int i = 0; i < n; i++) {
                if (a[x][i] && a[i][z]) {
                    f[i] = 1;
                } else if (a[y][i] && a[i][x]) {
                    f[i] = 2;
                } else {
                    f[i] = 0;
                }
            }
            int ok = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if ((f[i] + 1) % 3 == f[j] && a[j][i]) {
                        ok = 0;
                    }
                }
            }
            if (ok) {
                std::vector<int> ans[3];
                for (int i = 0; i < n; i++) {
                    ans[f[i]].push_back(i);
                }
                for (int i = 0; i < 3; i++) {
                    std::cout << ans[i].size() << " \n"[i == 2];
                }
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < ans[i].size(); j++) {
                        std::cout << ans[i][j] + 1 << " \n"[j == ans[i].size() - 1];
                    }
                }
                return 0;
            }
        }
    }
    
    std::cout << 0 << " " << 0 << " " << 0 << "\n";
    
    return 0;
}
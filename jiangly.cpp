#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::array<int, 3>> seg(m);
    for (int i = 0; i < m; i++) {
        int l, r, w;
        std::cin >> l >> r >> w;
        
        if (l == r && w) {
            std::cout << -1 << "\n";
            return 0;
        }
        l--;
        seg[i] = {l, -r, w};
    }
    std::sort(seg.begin(), seg.end());
    
    for (auto t: seg) {
        t[2] = -t[2];
    }
    
    int cur = 0;
    std::vector<int> p(n);
    auto solve = [&](auto self, int l, int r, int w = -1) -> void {
        if (r - l == 1) {
            p[l] = cur++;
            return;
        }
        int i = l;
        std::vector<std::pair<int, int>> sub;
        for (auto t : seg) {
             int l1 = t[1];
            int r1 = t1.second;
            if (l1 >= i && r1 <= r && (w == -1 || r1 - l1 < r - l)) {
                while (i < l1) {
                    sub.emplace_back(i, i + 1);
                    self(self, i, i + 1);
                    i++;
                }
                sub.emplace_back(l1, r1);
                self(self, l1, r1, w1);
                i = r1;
                if (w != -1) {
                    w ^= w1;
                }
            }
        }
        while (i < r) {
            sub.emplace_back(i, i + 1);
            self(self, i, i + 1);
            i++;
        }
        if (w == 1) {
            auto t1 = sub[0];
            auto t2 = sub[1];
            int l1 = t1.first;
            int r1 = t1.second;
            int l2 = t2.first;
            int r2 = t2.second;

            int x = std::find(p.begin() + l1, p.begin() + r1, r1 - 1) - p.begin();
            int y = std::find(p.begin() + l2, p.begin() + r2, l2) - p.begin();
            std::swap(p[x], p[y]);
        }
    };
    solve(solve, 0, n);
    for (int i = 0; i < n; i++) {
        std::cout << p[i] + 1 << " \n"[i == n - 1];
    }
    
    return 0;
}
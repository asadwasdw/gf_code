#include <bits/stdc++.h>
#define LL long long
const int kN = 2e5 + 10;
//=============================================================
int n, m, q, a[kN], b[kN], map[kN];
std::set<int> s[kN];
int cnt;
//=============================================================
bool check(int p_) {
  if (p_ <= 0 || p_ >= n) return 0;
  return (*s[a[p_]].begin()) <= (*s[a[p_ + 1]].begin());
}
bool query() {
  return cnt == n - 1;
}
void modify(int p_, int t_) {
  cnt -= check(map[b[p_]]) + check(map[b[p_]] - 1);
  s[b[p_]].erase(p_);
  cnt += check(map[b[p_]]) + check(map[b[p_]] - 1);
  
  cnt -= check(map[t_]) + check(map[t_] - 1);
  s[t_].insert(p_), b[p_] = t_;
  cnt += check(map[t_]) + check(map[t_] - 1);
}
void init() {
  cnt = 0;
  for (int i = 1; i < n; ++ i) cnt += check(i);
}
//=============================================================
int main() {
  // freopen("1.txt", "r", stdin);
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int T; std::cin >> T;
  while (T --) {
    std::cin >> n >> m >> q;
    for (int i = 1; i <= n; ++ i) std::cin >> a[i], map[a[i]] = i;
    for (int i = 1; i <= n; ++ i) s[i].clear(), s[i].insert(m + 1);
    for (int i = 1; i <= m; ++ i) std::cin >> b[i], s[b[i]].insert(i);
    init();
    std::cout << (query() ? "YA" : "TIDAK") << "\n";
    
    while (q --) {
      int p, t; std::cin >> p >> t;
      modify(p, t);
      std::cout << (query() ? "YA" : "TIDAK") << "\n";
    }
  }
  return 0;
}
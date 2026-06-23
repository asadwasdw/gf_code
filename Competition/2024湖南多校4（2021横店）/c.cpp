#include <bits/stdc++.h>

using PII = std::pair<int, int>;
using LL = long long;
using namespace std;

const int N = 510;
int n;

bool ck1[N][10][10], ck2[N][10][10];
int f[N][N];
bool v[N][N];
char ss[N];

int dfs(int l, int r) {
  if(l == n && r == n) return f[l][r] = 0;
  if(v[l][r]) return f[l][r];
  v[l][r] = 1;
  f[l][r] = 1e9;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(!i && !j) {
        if(l < n && r < n && ss[l + 1] == '0' && ss[n - r] == '0') {
          f[l][r] = min(f[l][r], dfs(l + 1, r + 1) + 1);
        }
      }
      else if(!i) {
        if(l < n && ss[l + 1] == j + '0') {
          f[l][r] = min(f[l][r], dfs(l + 1, r) + 1);
          // cout << l << ' ' << r << ' ' << f[l][r] << '\n';
        }
      }
      else if(!j) {
        if(r < n && ss[n - r] == i + '0') {
          f[l][r] = min(f[l][r], dfs(l, r + 1) + 1);
        }
      }
      else {
        if(ck1[l][i][j] && ck2[r][i][j]) {
          f[l][r] = min(f[l][r], dfs(l + j, r + i) + 1);
        }
      }
    }
  }
  return f[l][r];
}

void getans(int l, int r) {
  // cout << l << ' ' << r << ' ' << f[l][r] << '\n';
  if(l == n && r == n) return ;
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      if(!i && !j) {
        if(l < n && r < n && ss[l + 1] == '0' && ss[n - r] == '0') {
          if(f[l][r] == f[l + 1][r + 1] + 1) {
            cout << i << j;
            getans(l + 1, r + 1);
            return ;
          }
        }
      }
      else if(!i) {
        if(l < n && ss[l + 1] == j + '0') {
          if(f[l][r] == f[l + 1][r] + 1) {
            cout << i << j;
            getans(l + 1, r);
            return ;
          }
        }
      }
      else if(!j) {
        if(r < n && ss[n - r] == i + '0') {
          if(f[l][r] == f[l][r + 1] + 1) {
            cout << i << j;
            getans(l, r + 1);
            return ;
          }
        }
      }
      else {
        if(ck1[l][i][j] && ck2[r][i][j]) {
          if(f[l][r] == f[l + j][r + i] + 1) {
            cout << i << j;
            getans(l + j, r + i);
            return ;
          }
        }
      }
    }
  }
}

void solve() {
  cin >> ss + 1;
  n = strlen(ss + 1);
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j < 10; j++) {
      for(int k = 1; k < 10; k++) {
        if(i + k > n || i - j < 0) continue;
        ck1[i][j][k] = 1;
        for(int h = 1; h <= k; h++) {
          ck1[i][j][k] &= ss[i + h] == ss[i + h - j];
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < 10; j++) {
      for(int k = 1; k < 10; k++) {
        if(n - i - k - j < 0) continue;
        ck2[i][j][k] = 1;
        for(int h = 0; h < j; h++) {
          ck2[i][j][k] &= ss[n - i - h] == ss[n - i - h - k];
        }
      }
    }
  }
  dfs(0, 0);
  getans(0, 0);
  cout << '\n';
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }
  return 0;
}

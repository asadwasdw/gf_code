#include<bits/stdc++.h>
#define ll long long
using namespace std;
// #define int long long
typedef pair<int,int> PII;
const int N = 1e6 + 10;
const int mod = 998244353;



using i64 = long long;
void solve() {
    i64 n; cin >> n;
    i64 ans = 1;
    vector<i64> p;
    for (i64 i = 2; i * i <= n; i ++) {
        if (n % i == 0) {
            i64 cnt = 0;
            while (n % i == 0) n /= i, cnt++;
            p.push_back(cnt);
        }
    }
    if (n != 1) p.push_back(1);
    i64 last = 0;
    for (auto x : p) {
        ans = ans + x + last * 2 * x;
        last = last + last * 2 * x + x;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
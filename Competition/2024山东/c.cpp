#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 5e6 + 10, mod = 1e9+7;

using i64 = long long;
constexpr i64 P = 998244353;

int tr[N];
void add(int x, int d) {
    for (int i = x; i < N; i += (i & -i)) {
        tr[i] += d;
    }
}
int ask(int x) {
    int ans = 0;
    for (int i = x; i; i -= (i & -i)) {
        ans += tr[i];
    }
    return ans;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<array<int, 2>> a(n);
    vector<int> x;
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        x.push_back(a[i][0]);
        x.push_back(a[i][1]);
        x.push_back(a[i][1] + 1);
    }
    x.push_back(0);
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    int m = x.size();
    vector<vector<int>> g(m);
    for (auto &[u, v] : a) {
        u = lower_bound(x.begin(), x.end(), u) - x.begin();
        v = lower_bound(x.begin(), x.end(), v) - x.begin();
        g[u].push_back(v);
    }    
    i64 ans = 1;
    for (int i = 0; i < m; i++) {
        sort(g[i].rbegin(), g[i].rend());
        for (auto x : g[i]) {
            i64 cnt = ask(i);
            ans = ans * max(0ll, k - cnt) % P;
            add(i, 1);add(x+1, -1);
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto x : g[i]) {
            add(i, -1);add(x+1, 1);
        }
    }

    cout << ans << "\n";



}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
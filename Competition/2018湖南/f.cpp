#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 2e6+10, INF = 0x3f3f3f3f, mod = 1e9+7;

int p[N];
PII edg
int ans, res;
vector<vector<int>> adj(N);

void clacswap(int x, int y) {


}

void solve() {
    ans = res = 0;
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i <= n; i ++) {
        int x, y; cin >> x >> y;
        if(x > y) swap(x, y);
        adj[x].push_back(y);
        res += abs(p[x] - p[y]);
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
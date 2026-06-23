#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ll long long
using namespace std;
constexpr int N = 2e6+10, INF = 0x3f3f3f3f, mod = 1e9+7;

int a[N],f[N],sum[N],num[N],cnt;
vector<vector<int>> adj(N);

void dfs(int u, int ans) {
    
    f[u] = ans;
    num[a[u]] ++;
    if(num[a[u]] == 1) cnt ++;

    for(auto v : adj[u]) {
        int t = cnt - sum[a[v]];
        sum[a[v]] += t;
        dfs(v, t + ans);
        sum[a[v]] -= t;

    }

    num[a[u]] --;
    if(num[a[u]] == 0) cnt --;
    
}

void solve() {
    int n; 
    while(cin >> n) {
        for(int i = 2; i <= n; i ++) {
            int x; cin >> x;
            adj[x].push_back(i);
        }

        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
        }

        dfs(1, 0);
        for(int i = 2; i <= n; i ++) cout << f[i] << endl;    

        for(int i = 0; i <= n; i ++) {
            adj[i].clear();
            a[i] = sum[i] = num[i] = 0;
            cnt = 0;
        }
    }

}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) solve();
}
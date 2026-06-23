#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 




void solve()
{
    int n, m;  cin >> n >> m;
    vector<array<int,3>> e;
    vector<vector<PII>>adj(n + 1);
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int ans = 0;


    auto check = [&](int mid) -> bool {
        vector<int> d(n + 1, 0);
        for(auto [u, v, w] : e) {
            if(w > mid) continue;
            d[u] ++;
            d[v] ++;
        }
        queue<int> q;
        for(int i = 1; i <= n; i ++) {
            if(d[i] == 1) q.push(i);
        }
        while(q.size()) {
            int u = q.front(); q.pop();
            for(auto [v, w] : adj[u]) {
                if(w > mid) continue;
                if(d[v] == 0) continue;
                --d[v];
                --d[u];
                if(d[v] == 1) q.push(v);
            }
        }
        for(int i = 1; i <= n; i ++) {
            // cout << d[i] << " \n"[i == n];
            if(d[i]) return true;
        }
        return false;
    };

    // check(1);

    int l = 0, r = n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;








}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<PII>>edg(N);

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v, w});
        edg[v].push_back({u, w});
    }
    vector<vector<int>>ans(n + 1, vector<int> (2));
    auto dj = [&](int S, int id) -> vector<int> {

        vector<int> dis(n + 1, INF * 2);
        vector<bool> st(n + 1, 0);
        priority_queue<PII,vector<PII>, greater<PII> >q;
        q.push({0, S});
        dis[S] = 0;

        while(q.size()) {
            auto [d, u] = q.top(); q.pop();
            if(st[u]) continue;
            st[u] = true;
            for(auto [v, w] : edg[u]) {
                if(st[v]) continue;
                if(max(d, w) >= dis[v]) continue;
                dis[v] = max(d, w);
                q.push({dis[v], v});
            }
        }
        return dis;
    };
    auto d1 = dj(1, 0);
    auto dn = dj(n, 1);

    int res = INF * 2;

    for(int u = 1; u <= n; u ++) {
        for(auto [v, w] : edg[u]) {
            if(max(d1[u],dn[v]) <= w) res = min(res, w + max(d1[u], dn[v]));
            if(max(d1[v],dn[u]) <= w) res = min(res, w + max(d1[v], dn[u]));
        }
    }
    cout << res << endl;
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
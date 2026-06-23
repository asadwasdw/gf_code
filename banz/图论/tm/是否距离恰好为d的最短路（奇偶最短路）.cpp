#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m, k;
int a[N];


void solve()
{
    cin >> n >> m >> k;
    vector<vector<array<int,2>>> ans(n + 1);
    vector<vector<int>> adj(n + 1);

    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >>  v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto dijkstra = [&](int s) {
        priority_queue<array<int,3>> q;
        vector<array<int,2>> dis(n + 1, {INF, INF});
        vector<array<bool,2>> st(n + 1, {0, 0});
        q.push({0,s,0});
        dis[s][0] = 0;

        while(q.size()) {
            auto [d, u, t] = q.top(); q.pop();
            if(st[u][t]) continue;
            st[u][t] = true;

            for(auto v : adj[u]) {
                if(st[v][t ^ 1]) continue;
                if(dis[v][t ^ 1] <= d + 1) continue;

                dis[v][t ^ 1] = d + 1;
                q.push({dis[v][t ^ 1], v, t ^ 1});
            }
        }

        // ans[s] = dis;
        // for(int i = 1; i <= n; i ++) cout << dis[i][0] << " \n"[i == n];
        // for(int i = 1; i <= n; i ++) cout << dis[i][1] << " \n"[i == n];
        // cout << endl;
        swap(dis, ans[s]);
    };

    for(int i = 1; i <= n; i ++) {
        dijkstra(i);
    }

    while(k --) {
        int u, v, w;
        cin >> u >> v >> w;
        if(w >= ans[u][v][w%2] && adj[u].size()) cout << "TAK\n";
        else cout << "NIE\n";
    }



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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>PII;
const int N=3e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
vector<PII> g[N];
ll dist[N], dist2[N];

void bfs(){
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while(q.size()){
        auto [_, u] = q.top();q.pop();
        for(auto [v, w] : g[u]){
            if(dist[v] > max(dist[u], w)){
                dist[v] = max(dist[u], w);
                q.push({dist[v], v});
            }
        }
    }
}
void bfs2(){
    dist2[n] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, n});
    while(q.size()){
        auto [_, u] = q.top();q.pop();
        for(auto [v, w] : g[u]){
            if(dist2[v] > max(dist2[u], w)){
                dist2[v] = max(dist2[u], w);
                q.push({dist2[v], v});
            }
        }
    }
}


void solve()
{
    cin >> n >> m;
    vector<array<int, 3>> p;
    for(int i=1; i<=m; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        p.push_back({w, u, v});
    }
    memset(dist, 0x3f, sizeof dist);
    memset(dist2, 0x3f, sizeof dist2);
    bfs();bfs2();
    sort(p.begin(), p.end());
    ll res = 1e18;
    for(auto &[w, u, v] : p){
        ll s = max(dist[u], dist2[v]);
        if(s < w)
        res = min(res, s + w);
        s = max(dist[v], dist2[u]);
        if(s < w)
        res = min(res, s + w);
    }
    
    cout << res;

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
#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<ll,int>PII;
const int N=2e5+10;
const int mod=998244353;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

int h[N], ne[N], e[N], idx = 1;
ll w[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

ll dis[N];
bool vis[N];

inline void dij() {
    priority_queue<PII,vector<PII>, greater<PII>> q;
    q.push({0, 1});
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    while(q.size()) {
        auto [W, u] = q.top(); q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                q.push({dis[v], v});
            }
        }
    }
}

int f[N];
int n, m, Q;
queue<int> q[N];
inline void bfs(int num) {
    for(int i = 1; i <= n; i ++) f[i] = INFll;
    f[1] = 0;
    // vector<queue<int>> q(n + 1);
    q[0].push(1);

    int mx = 0;
    for(int i = 0; i <= mx; i ++) {
        while(q[i].size()) {
            int u = q[i].front(); q[i].pop();
            if(f[u] < i) continue;

            for(int j = h[u]; ~j; j = ne[j]) {
                int v = e[j];
                ll W = dis[u] - dis[v] + w[j]; 

                if(f[v] > f[u] + W) {
                    f[v] = f[u] + W;
                    // cout << "f[v] : " << f[v] << endl; 
                    if(f[v] <= min(num, n - 1)) {
                        q[f[v]].push(v);
                        mx = max(mx, f[v]);
                    }
                }
            }
        }
    }
    // cout << "max : " << mx << endl;
}


void solve()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> Q;
    for(int i = 1; i <= m; i ++) {
        int u, v, w; cin >> u >> v >> w;
        add(u, v, w);
    }
    dij();

    // for(int i = 1; i <= n; i ++) cout << dis[i] << " \n"[i == n];
    while(Q--) {
        int opt, v;
        cin >> opt >> v;
        if(opt == 1) {
            if(dis[v] >= INFll) {
                cout << "-1" << endl;
            } else cout << dis[v] << endl;
        } else {
            for(int i = 1; i <= v; i ++) {
                int x; cin >> x;
                w[x] ++;
            }
            bfs(v);
            for(int i = 1; i <= n; i ++) {
                // cout << f[i] << " \n"[i == n];
                dis[i] = min(INFll, dis[i] + f[i]);
            }
        }
    }
    // cout << "S" << endl;
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
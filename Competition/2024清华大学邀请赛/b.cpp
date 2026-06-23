#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10, M = N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N], cur[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = h[S];

    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i ; i = ne[i]) {
            int v = e[i];
            if(d[v] == -1 && f[i]) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if(v == T) {
                    return true;
                }
                q.push(v);
            }
        }
    }

    return false;
}

int find(int u, int limit) {
    if(u == T) return limit;
    int flow = 0;
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;
        if(d[v] == d[u] + 1 && f[i]) {
            int t = find(v, min(f[i], limit - flow));
            if(!t) cur[u] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

ll dinic() {
    ll ans = 0, flow;
    while(bfs()) {
        if(flow = find(S, INF)) {
            ans += flow;
        } 
    }
    return ans;
}

int cnt, js[N], js2[N], cp[N];
int F[N], H[N], G[N];

void solve()
{
    memset(h, -1, sizeof h);
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    S = 0, T = ++ cnt;
    for(int i = 1; i <= n; i ++) {
         cin >> F[i];
        js[i] = ++ cnt;
        js2[i] = ++ cnt;
        add(S, js[i], F[i]); // 购买技术
        add(js[i],js2[i],INF); // 购买技术
    }

    
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> H[i];
        if(F[i] > H[i]) {
            add(js2[i], T, F[i] - H[i]);
            ans += F[i] - H[i];
        }
    } // 研发收益

    for(int i = 1; i <= m; i ++) {
        int x; cin >> x;
        cp[i] = ++ cnt;
        add(cp[i], T, x); // 产品收益
        ans += x;
    }

    for(int i = 1; i <= p; i ++) {
        int u, v;
        cin >> u >> v;
        add(js[u], cp[v], INF); // 技术->产品依赖
    }

    for(int i = 1; i <= q; i ++) {// 技术->技术依赖
        int u, v;
        cin >> u >> v;
        add(js[u], js2[v], INF);
    }

    cout << ans - dinic() << endl;

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
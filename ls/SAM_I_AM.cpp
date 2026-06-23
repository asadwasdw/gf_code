#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 



//vector<vector<int>>adj(N);
const int N=3e3+10, M = N * N + 10;
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];


void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    // memset(d, -1, sizeof(int) * (T + 10));
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = h[S];

    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(d[v] == -1 && f[i]) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                if(v == T) return true;
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
    while(bfs())
        if(flow = find(S, INF))
            ans += flow;
    return ans;
}

bool vis[N],ishave[N];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = true;

    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(!f[i]) continue;
        if(vis[v]) continue;
        dfs(v);
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    int n, m, k;
    cin >> n >> m >> k;
    if(n == 0 && m == 0 && k == 0) {
        exit(0);
    }

    S = 0, T = n + m + 1;
    for(int i = 1; i <= k; i ++) {
        int x, y; cin >> x >> y;
        add(x, n + y, 1);
        ishave[x] = ishave[y + n] = true;
    }
    for(int i = 1; i <= n; i ++) add(S, i, 1);
    for(int i = 1; i <= m; i ++) add(i + n,T, 1);

    cout << dinic();
    dfs(S);

    for(int i = 1; i <= n; i++)if(ishave[i] && !vis[i])cout << " r" << i;
    for(int i = n + 1; i <= n + m; i++)if(ishave[i] && vis[ i])cout << " c" << i - n;
    cout << endl;

    for(int i = 1; i <= n + m; i ++) {
        cout << vis[i] << " \n"[i == n + m];
    }

    // for(auto t : ans) cout << t << " "; cout << endl; 
    for(int i = 0; i <= n + m + 1; i ++) {
        vis[i] = ishave[i] = false;
    }
    idx = 0;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i = i){
        //printf("Case %d: ",i);
        solve();
    }
}
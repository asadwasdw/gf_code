#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

const int N=1e6+10, M = 2e6 + 10;
vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];



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

int id[N][2], cnt;

void add(int a, int b, int c) {
    // cout << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

int rd[N];
vector<int> adj[N];

void solve()
{
    cin >> n >> m;
    S = cnt ++, T = cnt ++;
    for(int i = 1; i <= n; i ++) {
        id[i][0] = cnt ++, id[i][1] = cnt ++;
        add(S, id[i][0], 1);
        add( id[i][1], T,1);        
    }

    for(int j = 1; j <= m; j ++) {
        int u, v; cin >> u >> v;
        add(id[u][0], id[v][1], 1);
    }

    int ans = n - dinic();
    for(int i = 0; i <= idx; i += 2) {
        int u = e[i ^ 1], v = e[i], w = f[i ^ 1];
        if(u == S || v == T) continue;
        if(w) {
            u /= 2, v /= 2;
            // cerr << u << " " << v << endl;
            adj[u].push_back(v);
            rd[v] ++;
        }
    }


    for(int i = 1; i <= n; i ++) {
        if(rd[i]) continue;
        int u = i;
        while(adj[u].size()) {
            cout << u << " ";
            u = adj[u][0];
        }
        cout << u << " ";
        cout << endl;
    }
    cout << ans << endl;
}


signed main()
{
    memset(h, -1, sizeof h);
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
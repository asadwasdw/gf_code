#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<char,char>PII;
const int N=1e6+10, M = 1e6;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second


vector<vector<int>>adj(N);
int dfn[N], low[N], dfncnt, in_s[N], in[N];
stack<int>s;
int scc[N], sc, sz[N];

void tarjan(int u) {
    low[u] = dfn[u] = ++dfncnt;
    s.push(u), in_s[u] = 1;

    for(auto v : adj[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(in_s[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if(dfn[u] == low[u]) {
        ++sc;
        while(s.top() != u) {
            scc[s.top()] = sc;
            sz[sc] ++;
            in_s[s.top()] = 0;
            s.pop();
        }

        scc[s.top()] = sc;
        sz[sc] ++;
        in_s[s.top()] = 0;
        s.pop();
    }
}

int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];
int id[N][6][2], cnt;

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
int E[27*27][27*27]={0};
void solve()
{
    memset(h, -1, sizeof h);
    map<char,int> id;
    int n = 0, m; cin >> m;
    vector<PII> edg;
    for(int i = 1; i <= m; i ++) {
        char a, b; cin >> a >> b;
        edg.push_back({a, b});
    }

    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= m; j ++) {
            // if(i == 3 && j == 5) cout << edg[i - 1].y << " " << edg[j - 1].x << endl;
            if(edg[i - 1].y == edg[j - 1].x) {
                // cout << i << " " << j << endl;
                adj[i].push_back(j);
            } 
        }
    }

    for(int i = 1; i <= m; i ++) {
        if(!dfn[i]) tarjan(i);
    }


    // for(int i = 1; i <= m; i ++) {
    //     cout << scc[i] << " \n"[i == m]; 
    // }

    for(int u = 1; u <= m; u ++) {
        for(auto v : adj[u]) {
            // cout << scc[u] << " " << scc[v] << endl;
            if(scc[v] == scc[u]) continue;
            E[scc[u]][scc[v]] = 1;
        }
    }

    // for(int i = 1; i <= sc; i ++) {
    //     for(int j = 1; j <= sc; j ++) {
    //         cout << E[i][j] << " \n"[j == sc];
    //     }
    // }
    
    for (int k = 1; k <= sc; ++k)
        for (int i = 1; i <= sc; ++i)
            for (int j = 1; j <= sc; ++j)
                if (E[i][k] && E[k][j])
                    E[i][j] = 1;
    
    S = 0, T = 2 * sc + 1;
    for(int i = 1; i <= sc; i ++) {
        for(int j = 1; j <= sc; j ++) {
            if(E[i][j]) {
                add(i, j + sc, 1);
            }
        }
    }

    for(int i = 1; i <= sc; i ++) {
        add(S, i, 1);
        add(i + sc, T, 1);
    }

    cout << sc - dinic() << endl;
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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10, M = 6e6 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];
int id[1010][1010], cnt;

void add(int a, int b, int c) {
    // cout << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = c, ne[idx] = h[b], h[b] = idx ++;
}

inline bool bfs() {
    // int D =  min( sizeof d, sizeof(int) * (cnt + 1) );
    // memset(d, -1, D);
    memset(d, -1, sizeof(int) * (cnt + 10));
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

inline int find(int u, int limit) {
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

inline ll dinic() {
    ll ans = 0, flow;
    // bfs();
    while(bfs())
        if(flow = find(S, INF))
            ans += flow;
    return ans;
}



void solve()
{
    int n, m;
    cin >> n >> m;

    S = cnt;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            id[i][j] = ++ cnt;
        }
    }
    T = ++ cnt;
    add(S, id[1][1], INF);
    add(id[n][m], T, INF);

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j < m; j ++) {
            int x; cin >> x;
            add(id[i][j], id[i][j + 1], x);
        }
    }

    for(int i = 1; i < n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x; cin >> x;
            add(id[i][j], id[i + 1][j], x);
        }
    }

    for(int i = 1; i < n; i ++) {
        for(int j = 1; j < m; j ++) {
            int x; cin >> x;
            add(id[i][j], id[i + 1][j + 1], x);
        }
    }


    int flow = dinic();
    cout << flow << endl;
    

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
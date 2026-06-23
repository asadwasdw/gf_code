#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

const int N=1e6+10, M = 2e6 + 10;
vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];
int cnt;

void add(int a, int b, int c) {
    // cout << a << " " << b << " " << c << endl;
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

int a[110][110];
int id[110][110];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

void solve()
{
    memset(h, -1, sizeof h);
    S = ++ cnt, T = ++ cnt;
    int ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x; cin >> x;
            id[i][j] = ++ cnt;
            add(S, id[i][j], x);
            ans += x;
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x; cin >> x;
            add(id[i][j], T, x);
            ans += x;

        }
    }

   for(int i = 1; i < n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x; cin >> x;
            int t = ++ cnt;
            add(S, t, x);
            add(t, id[i][j], INF);
            add(t, id[i + 1][j], INF);
            ans += x;

        }
    }

   for(int i = 1; i < n; i ++) {
        for(int j = 1; j <= m; j ++) {
            int x; cin >> x;
            int t = ++ cnt;
            add(t, T, x);
            add(id[i][j], t, INF);
            add(id[i + 1][j], t, INF);
            ans += x;

        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j < m; j ++) {
            int x; cin >> x;
            int t = ++ cnt;
            add(S, t, x);
            add(t, id[i][j], INF);
            add(t, id[i][j + 1], INF);
            ans += x;

        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j < m; j ++) {
            int x; cin >> x;
            int t = ++ cnt;
            add(t, T, x);
            add(id[i][j], t, INF);
            add(id[i][j + 1], t, INF);
            ans += x;
        }
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
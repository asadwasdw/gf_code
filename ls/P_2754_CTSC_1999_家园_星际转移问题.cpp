#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

const int N=1e5+10, M = 2e5 + 10;
vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];

void add(int a, int b, int c) {
    // cerr << a << " " << b << " " << c << endl;
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

int id[1010][15], cnt;
int w[N];
queue<int> q[N];

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    S = ++ cnt, T = ++ cnt;

    for(int i = 1; i <= m; i ++) {
        cin >> w[i];
        int x; cin >> x;
        while(x --) {
            int y; cin >> y; q[i].push(y);  
        } 
    }

    int ans = 0;
    for(int i = 0; i <= 1000; i ++) {
        for(int j = 0; j <= n + 1; j ++) id[i][j] = ++ cnt;

        if(i == 0) {
            add(S, id[i][0], k);
        } else {
            add(id[i][n + 1], T, k);
            for(int j = 0; j <= n + 1; j ++) add(id[i - 1][j], id[i][j], k);
        }


        for(int j = 1; j <= m; j ++) {
            if(i == 0) continue;
            int u = q[j].front(); q[j].pop();
            q[j].push(u);
            int v = q[j].front();
            if(u == v) continue;
            if(u == -1) continue;
            if(v == -1) v = n + 1;
            // cout << u << " " << v << endl;
            add(id[i - 1][u], id[i][v], w[j]);
        }


        ans += dinic();
        
        if(ans >= k) {
            cout << i << endl;
            break;
        }
    }

    if(ans < k) {
        cout << 0 << endl;
    }
}


signed main()
{
    cout << 1600.0 + 212.67 + 102.00 + 295.0 << endl;

    
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
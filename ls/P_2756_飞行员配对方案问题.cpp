#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 



//vector<vector<int>>adj(N);
const int N=4e3+10, M = 2 * 2 * 300 * 300 + N * 2 + 10;
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

int id[N][4], cnt;


void solve()
{
    memset(h, -1, sizeof h);


    int m, n;
    cin >> m >> n;
    S = 0, T = n + 1;

    for(int i = 1; i <= n; i ++) {
        if(i <= m) add(S, i, 1);
        else add(i, T, 1);
    }

    int u, v;
    while(cin >> u >> v) {
        if(u == -1 && v == -1) continue;
        add(u, v, 1);
    }

    cout << dinic() << endl;

    for(int i = 0; i < idx; i += 2) {
        int u = e[i^1], v = e[i];
        if(S < u && u <= m && m < v && v < T && f[i ^ 1]) {
            cout << u << " " << v << endl;
        }
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
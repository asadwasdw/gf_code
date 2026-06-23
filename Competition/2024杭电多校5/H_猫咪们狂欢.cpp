#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e4+10, M = 1e5 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
vector<vector<int>>edg(N);
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

void solve()
{
    memset(h, -1, sizeof h);
    idx = 0;

    int n, k; cin >> n >> k;
    vector<int> ish(n + 1, 0);
    for(int i = 1; i <= k; i ++) {
        int x; cin >> x;
        ish[x] = true;
    }
    S = 0, T = n + 1;
    int cnt = T + 1;
    int sum = 0;
    for(int i = 1; i < n; i ++) {
        int x, y, w; cin >> x >> y >> w;
        if(ish[x] && ish[y]) {
            add(cnt, x, INF);
            add(cnt, y, INF);
            add(S, cnt, w);
            cnt++;
            sum += w;
        }
    }
    for(int i = 1; i < n; i ++) {
        int x, y, w; cin >> x >> y >> w;
        if(ish[x] && ish[y]) {
            add(x, cnt, INF);
            add(y, cnt,INF);
            add(cnt, T, w);
            cnt++;
            sum += w;
        }
    }

    cout << sum - dinic() << endl;

    
}


signed main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
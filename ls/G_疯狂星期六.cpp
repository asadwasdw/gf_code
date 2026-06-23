#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10, M = 2e6 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

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
int a[N], V[N], x[N], y[N],w[N];

void solve()
{
    int sum = 0, sumw = 0;;
    cin >> n >> m;
    T = n + m + 1, S = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i] >> V[i];
    }
    sum += V[1];
    for(int i = 1; i <= m; i ++) {
        cin >> x[i] >> y[i] >> w[i];
        // cout << x[i] << y[i] << w[i] << endl;
        if(x[i] == 1 || y[i] == 1) sum += w[i];
        add(x[i], n + i, w[i]);
        add(y[i], n + i, w[i]);
        add(n + i,    T, w[i]);
        sumw += w[i];
    }

    // cout << sum << endl;
    sum = min(sum, a[1]);

    add(S, 1, a[1] - V[1]);


    for(int i = 2; i <= n; i ++) {
        a[i] = min(a[i], sum - 1);
        if(a[i] < V[i]) {
            cout << "NO\n";
            return;
        }

        add(S, i, a[i] - V[i]);
    }
    if(dinic() != sumw) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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
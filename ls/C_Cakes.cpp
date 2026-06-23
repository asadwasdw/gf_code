#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10,M = N;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m, S, T;
int a[N];
ll h[N], e[M], ne[M], f[M], idx;
int d[N], cur[N];


void add(int a, int b, int c) {
    // cout << a << " " << b << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    memset(d, -1, sizeof(int) * T * 4);
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

int find(int u, ll limit) {
    if(u == T) return limit;
    ll flow = 0;

    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;
        if(d[v] == d[u] + 1) {
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

void clear() {
    memset(h, -1, sizeof h);
    idx = 0;
}


int w[N];
int g[N],c[N],t[N];

PII edge[N];

void solve()
{
    int G, C, TT;
    cin >> G >> C >> TT;
    S = 0, T = C + TT + 1;
    for(int i = 1; i <= C; i ++) cin >> c[i];
    for(int i = 1; i <= G; i ++) cin >> g[i];
    for(int i = 1; i <=TT; i ++) {
        cin >> t[i];
        add(C + i, T, t[i]);
    }

    int sum = 0;
    for(int i = 1; i <= C; i ++) {
        for(int j = 1; j <= G; j ++) {
            int x; cin >> x;
            c[i] -= x * g[j];
        }
        if(c[i] > 0) {
            add(S, i, c[i]);
            sum += c[i];
        }
    }

    for(int i = 1; i <= C; i ++) {
        int n; cin >> n;
        for(int j = 1; j <= n; j ++) {
            int x; cin >> x;
            add(i, x + C, INF);
        }
    }

    cout << sum - dinic() << endl;
}


signed main()
{
    clear();   
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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n,m,S,T;
ll h[N], ne[N], e[N], idx, f[N];
int d[N], cur[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a]=idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b]=idx++;
}


bool bfs() {
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(S);
    d[S] = 0;
    cur[S] = h[S];
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && d[v] == -1) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                q.push(v);
                if(v == T) return true;
            }
        }
    }
    return false;
}


ll find(int u, int limit) {
    if(u == T) return limit;
    ll flow = 0;
    
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;

        if(f[i] && d[v] == d[u] + 1) {
            int t = find(v, min(f[i], limit - flow));
            if(!t) d[v] = -1;
            f[i] -= t,f[i ^ 1] += t,flow += t;
        }
    }
    return flow;
}

ll dinic() {
    ll ans = 0;
    ll flow;

    while(bfs()) while(flow = find(S,INF)) ans += flow;
    return ans;

}

void solve()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> S >> T;
    for(int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << dinic() << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
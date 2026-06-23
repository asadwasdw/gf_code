#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m;
int h[N], e[N], f[N],ne[N], idx;
int cur[N], d[N];
int S, T;

void add(int a, int b, int c) {
    // cout << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    queue<int> q;
    for(int i = 1; i <= 2 * n + 1; i ++) d[i] = - 1; 
    d[S] = 0, cur[S] = h[S], q.push(S);

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
        cur[u] = i;
        int v = e[i];
        if(f[i] && d[v] == d[u] + 1) {
            int t = find(v, min(f[i], limit - flow));
            if(!t) d[v] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t; 
        }
    }
    return flow;
}

int dinic() {
    int ans = 0,t;
    while(bfs()) if(t = find(S,INF)) ans += t;
    return ans;
}


void solve()
{
   
    cin >> n >> m;
    for(int i = 0; i <= 2 * n + 1 ; i ++) h[i] = -1;
    idx = 0;

    for(int i = 1; i <= m; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b + n, 1);
    }
    S = 0, T = 2 * n + 1;

    for(int i = 1; i <= n; i ++) {
        add(S, i, 1);
        add(i + n, T, 1);
    }

   int ans = dinic();
//    cout << ans << endl;

    auto bfs2 = [&](int S, int l, int r, int w) -> int{
        queue<int> q;
        vector<int> st(n * 2 + 1, 0);
        q.push(S);
        st[S] = true;
        int cnt = 0;
        while(q.size()) {
            int u = q.front(); q.pop();
            if(l <= u && u <= r) cnt ++;
            for(int i = h[u]; ~i; i = ne[i]) {
                int v = e[i];
                if(st[v]) continue;
                if(w != f[i]) continue;
                q.push(v);
                st[v] = true;
            }
        }
        // cout << cnt << endl;
        return cnt;
    };
    int t1 = bfs2(S, 1, n, 1);
    int t2 = bfs2(T, n + 1, 2 * n, 0);
    cout << 1ll * t1 * t2 << endl;
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
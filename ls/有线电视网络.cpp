#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3 + 10, M = 1e6 + 10;
const int mod=998244353;
const int INF  = 9999;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n, m, S, T;
int a[N];
int h[N], e[M], ne[M], f[M], idx;
int id[N][2], cnt;
int d[N], cur[N];

void add(int a, int b, int c) {
    // cout << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++; 
}


bool bfs() {
    memset(d, -1, sizeof(int) * cnt * 4);
    queue<int>q;
    q.push(S), d[S] = 0, cur[S] = h[S];

    while(q.size()) {
        int u = q.front(); q.pop();

        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && d[v] == -1) {
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

int dinic(){
    int ans = 0, t;
    while(bfs())
        if(t = find(S, INF)) ans += t;
    return ans;
}

int ind[N], oud[N];

void solve()
{
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i = 0; i < n; i ++) {
                id[i][0] = ++ cnt;
                id[i][1] = ++ cnt;
            }

            vector<PII> e;

            while(m --) {
                int u, v;
                scanf(" (%d,%d)", &u, &v);
                e.push_back({u, v});
            }

            int ans = INF;

            for(int s = 0; s < n; s ++) {
                for(int t = 0; t < n; t ++) {
                    if(s == t) continue;
                    S = id[s][0];
                    T = id[t][1];
                    // cout << S << " " << T << endl;
                    memset(h, -1, sizeof h);
                    idx = 0;

                    for(int i = 0; i < n; i ++) {
                        if(i == s || i == t) add(id[i][0], id[i][1], INF);
                        else add(id[i][0], id[i][1], 1);
                    }

                    for(auto [u, v] : e) {
                        add(id[u][1], id[v][0], INF);
                        add(id[v][1], id[u][0], INF);
                    }

                    // cout << dinic() << endl;

                    ans = min(ans,dinic());
                }
            }
        cout << min(n, ans) << endl;
    }
}


signed main()
{
    
    // ios::sync_with_stdio(false);
    // cin.tie(0),cout.tie(0);
    // cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
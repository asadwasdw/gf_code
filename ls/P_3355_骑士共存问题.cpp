#include<bits/stdc++.h>
#define int long long
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

const int N=1e6+10, M = 1e7 + 10;
vector<vector<int>>edg(N);
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];
int cnt;

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

int a[510][510];
int id[510][510];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};


map<PII,bool> st;
void solve()
{
    memset(h, -1, sizeof h);
    int n, m; cin >> n >> m;
    S = ++ cnt, T = ++ cnt;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            id[i][j] = ++ cnt;
            ans += 1;
        }
    }

    ans -= m;

    for(int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        st[{x, y}] = true;
    }



    for(int i = 1; i <= n; i ++)  {
        for(int j = 1; j <= n; j ++){
            if(st[{i, j}]) continue;
            if((i + j) % 2  == 1) {
                add(S, id[i][j], 1);
            } else {
                add(id[i][j], T, 1);
                for(int k = 0; k < 8; k ++) {
                    int tx = i + dx[k];
                    int ty = j + dy[k];

                    if(tx < 1 || tx > n || ty > n || ty < 1) continue;
                    add(id[tx][ty], id[i][j], INF);
                }
            }
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
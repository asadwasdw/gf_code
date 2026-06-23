#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10, M = 2e6 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


// 选择点权最小的集合，使得每条边都至少有一个端点被选
/*
仅仅适用二分图
原图上的点划分为左部点和右部点，（可能要拆点构造出二分图）
原图上的边为流量为INF的，防止被割
左部点连接S,容量为点权
右部点连接T,容量为点权
哪条点被割，对应着哪个点被选
*/

int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];
int id[N][2], cnt;

void add(int a, int b, int c) {
    // cout << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    memset(d, -1, sizeof(int) * (cnt + 10));
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

int w1[N], w2[N];


void solve()
{
    cin >> n >> m;
    
    S = cnt;
    for(int i = 1; i <= n; i ++) {
        id[i][0] = ++ cnt;
        id[i][1] = ++ cnt;
    }
    T = ++ cnt;

    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        add(S, id[i][0], x);
    }

    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        add(id[i][1], T, x);
    }

    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v; 
        add(id[v][0], id[u][1], INF);
    }


    int flow = dinic();
    cout << flow << endl;
    vector<int> ans;

    for(int i = 0; i < idx; i += 2) {
        int a = e[i ^ 1], b = e[i];
        if(d[a] != -1 && d[b] == -1) {
            if(a == S) {
                ans.push_back((b + 1) / 2);
            }
            else ans.push_back(-(a/2));
        } 
    }

    cout << ans.size() << endl;
    for(auto t :ans) {
        cout << abs(t);
        if(t > 0) cout << " +\n";
        else cout << " -\n";
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
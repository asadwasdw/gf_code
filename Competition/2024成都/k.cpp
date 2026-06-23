#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
using i64 = long long;
typedef long long ll;


const int N = 400 * 1200 + 10, M = 1e7 + 10;
int n, m, S, T;
int idx, h[N], ne[M], e[M], f[M], w[M];
bool vis[N];
int dis[N], cur[N];

void add(int a, int b, int c, int d) {
    e[idx] = b, f[idx] = c, w[idx] = d, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, w[idx] =-d, ne[idx] = h[b], h[b] = idx ++;
}

bool SPFA(void) //用 SPFA 代替 BFS
{
    queue<int> q;
    memset(dis, 0x3f, sizeof dis);
    q.emplace(S);
    dis[S] = 0;
    cur[S] = h[S];
    while (q.size()) {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if (f[i] && dis[v] > dis[u] + w[i]) {
                dis[v] = dis[u] + w[i];
                cur[v] = h[v];
                if (!vis[v]) {
                    vis[v] = 1;
                    q.emplace(v);
                }
            }
        }
    }
    return dis[T] != 0x3f3f3f3f;
}
int find(int u, int limit, int &cost)
{
    if (u == T) {
        cost += dis[T] * limit;
        return limit;
    }
    vis[u] = 1; //特判
    int flow = 0;
    for (int i = cur[u]; flow < limit && ~i; i = ne[i]){
        int v = e[i];
        // 最短路分层图
        if (f[i] && dis[v] == dis[u] + w[i] && !vis[v]) { //还是这个特判，并且求的增广路必须同时是最短路
            cur[u] = i;
            int t = find(v, min(f[i], limit - flow), cost);
            if (!t) dis[v] = INF;
            flow += t, f[i] -= t, f[i ^ 1] += t;
        }
    }
    vis[u] = 0;
    return flow;
}
int flow, cost;
int dinic()
{
    flow = 0, cost = 0;
    while (SPFA())
        flow += find(S, INF, cost);
    return 0;
}

map<int,int> ID,ID2;
unordered_map<int,int> FF;
unordered_map<int,bool> vis2;
int cnt1 = 0;

int id(int x) {
    if(!ID[x]) ID[x] = ++ cnt1;
    return ID[x];
}
 
int id2(int x) {
    if(!ID2[x]) ID2[x] = ++ cnt1;
    return ID2[x];
}

bool st[N];
int pri[N];
int cnt;

int F(int x) {
    if(FF.count(x)) return FF[x];
    int res = 1;
    if(x <= 1) {
        return 0;
    }
    for(int i = 0; i < cnt; i ++) {
        if(x%pri[i] == 0) {
            res = F(x/pri[i]) + 1;
            break;
        }
    }
    return FF[x] = res;
}

vector<int> adj[310];
vector<int> V, V2;

void dfs(int x) {
    if(vis2[x]) return;
    vis2[x] = true;
    
    vector<int> v;
    for(int i = 1; i * i <= x; i ++) {
        if(x % i) continue;
        int j = x / i;
        v.push_back(i);
        v.push_back(j);
    } 

    sort(v.begin(), v.end(),[&](int a, int b) {
        return a > b;
    });
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 0; i < v.size(); i ++) {
        // cout << x << " " << v[i] << " " << F(x) - F(v[i]) << endl;
        add(id(x), id2(v[i]), 1, -(F(x) - F(v[i])));
    }
}


void qie_p(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])pri[cnt++]=i;
        
        for(int j=0;i*pri[j]<=n;j++)
        {
            st[pri[j]*i]=true;
            if(i%pri[j]==0)
            {
                break;
            }
        }
    }
    
}

void solve() {
    memset(h, -1, sizeof h);
    qie_p(1e5);
    S = ++ cnt1, T = ++cnt1;
     cin >> n;
       for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        add(S, id(x), 1, 0);
        dfs(x);
    }
    for(auto [_, v] : ID2) {
        add(v, T, 1, 0);
    }

    dinic();
    // cout << flow << endl;
    cout << -cost << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}
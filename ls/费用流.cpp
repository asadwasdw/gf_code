#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e5 + 10, M = 2e6 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int idx;
int newnode() {
    return idx ++;
}

vector<vector<int>>adj(N);
int sccnt;
int low[N], num[N], dfn;
int sccno[N];
stack<int> sta;

void dfs(int u) {
    sta.push(u);
    low[u] = num[u] = ++ dfn;

    for(auto v : adj[u]) {
        if(!num[v]) {
            dfs(v);
            low[u] = min(low[v], low[u]);
        } else if (!sccno[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if(low[u] == num[u]) {
        sccnt ++;
        while(1) {
            int v = sta.top(); sta.pop();
            sccno[v] = sccnt;
            if(u == v) break;
        }
    }
}
int k;

PII E[N];

struct edge {
  int v, f, c, next;
} e[M];

struct node {
  int v, e;
} p[N];

struct mypair {
  int dis, id;

  bool operator<(const mypair& a) const { return dis > a.dis; }

  mypair(int d, int x) { dis = d, id = x; }
};

int head[N], dis[N], vis[N], h[N];
int n, m, s, t, cnt = 1, maxf, minc;

void addedge(int u, int v, int f, int c) {
  e[++cnt].v = v;
  e[cnt].f = f;
  e[cnt].c = c;
  e[cnt].next = head[u];
  head[u] = cnt;
}

bool dijkstra() {
  priority_queue<mypair> q;
  for (int i = 0; i <= idx; i++) dis[i] = INF;
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  q.push(mypair(0, s));
  while (!q.empty()) {
    int u = q.top().id;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v, nc = e[i].c + h[u] - h[v];
      if (e[i].f && dis[v] > dis[u] + nc) {
        dis[v] = dis[u] + nc;
        p[v].v = u;
        p[v].e = i;
        if (!vis[v]) q.push(mypair(dis[v], v));
      }
    }
  }
  return dis[t] != INF;
}

void spfa() {
  queue<int> q;
  memset(h, 63, sizeof(h));
  h[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (int i = head[u]; i; i = e[i].next) {
      int v = e[i].v;
      if (e[i].f && h[v] > h[u] + e[i].c) {
        h[v] = h[u] + e[i].c;
        if (!vis[v]) {
          vis[v] = 1;
          q.push(v);
        }
      }
    }
  }
}



int id2[N][2];
int idw[N];

void add(int u, int v, int f, int c) {
    // cout << u << " " << v << " " << f << endl;
    addedge(u, v, f, c);
    addedge(v, u, 0, -c);
}

void solve()
{
    s = newnode();
    int tt = newnode();
    t = newnode();
   
    cin>> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int a,b;cin>>a>>b;
        adj[a].push_back(b);
        E[i] = {a, b};
    }

    for(int i = 1; i <= n; i ++) {
        if(!num[i]) 
            dfs(i);
    }
    // dfs(1);
    
    for(int i = 1; i <= n; i ++) {
        // cout << sccno[i] << endl;/
        int x; cin >> x; idw[sccno[i]] += x;
    }
    
    for(int i = 1; i <= sccnt; i ++) {
        id2[i][0] = newnode();
        id2[i][1] = newnode();
        add(id2[i][0], id2[i][1], k, 0);
        add(id2[i][0], id2[i][1], 1, -idw[i]);
        add(id2[i][1], tt, k, 0);
    }

    add(s, id2[sccno[1]][0], k, 0);
    add(tt, t, k, 0);
    for(int i = 1; i <= m; i ++) {
        auto [u, v] = E[i];
        if(sccno[u] == sccno[v]) continue;
        add(id2[sccno[u]][1], id2[sccno[v]][0], k, 0);
    }

    spfa();  // 先求出初始势能
    while (dijkstra()) {
        int minf = INF;
        for (int i = 0; i <= idx; i++) h[i] += dis[i];
        for (int i = t; i != s; i = p[i].v) minf = min(minf, e[p[i].e].f);
        for (int i = t; i != s; i = p[i].v) {
            e[p[i].e].f -= minf;
            e[p[i].e ^ 1].f += minf;
        }
        maxf += minf;
        minc += minf * h[t];
    }
    // printf("%d %d\n", maxf, minc);
    cout << -minc << endl;

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
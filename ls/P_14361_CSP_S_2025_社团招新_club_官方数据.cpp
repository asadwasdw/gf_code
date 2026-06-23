#include <algorithm>
#include <cstdio>
#include <cstring>
#include<iostream>
#include <queue>
constexpr int INF = 0x3f3f3f3f;
using namespace std;

struct edge {
  int v, f, c, next;
} e[500005];

struct node {
  int v, e;
} p[500005];

struct mypair {
  int dis, id;

  bool operator<(const mypair& a) const { return dis > a.dis; }

  mypair(int d, int x) { dis = d, id = x; }
};

int head[500005], dis[500005], vis[500005], h[500005];
int n, m, s, t, cnt = 1, maxf, minc;
int cntt = 0;

void addedge(int u, int v, int f, int c) {
  e[++cnt].v = v;
  e[cnt].f = f;
  e[cnt].c = c;
  e[cnt].next = head[u];
  head[u] = cnt;
}


void add(int u, int v, int f, int c) {
    cerr << u << " " << v << endl;
    addedge(u, v, f, c);
    addedge(v, u, 0, -c);
}


bool dijkstra() {
  priority_queue<mypair> q;
  for (int i = 0; i <= cntt; i++) dis[i] = INF, vis[i] = 0;
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

const int N = 1e5 + 10;

int newnode() { return cntt ++; }


int id[N][2];
int a[N];

void solve() {

    

    cntt = 0;
    cnt = 0;
    cin >> n;
    s = newnode();
    for(int i = 1; i <= n; i ++) id[i][0] = newnode();
    for(int i = 1; i <= 3; i ++) id[i][1] = newnode();
    t = newnode(); 

    for(int i = 1; i <= n; i ++) {
        add(s, id[i][0], 1, 0);
    }

    for(int i = 1; i <= 3; i ++) {
        add(id[i][1], t, n/2, 0);
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= 3; j ++) {
            int x; cin >> x;
            add(id[i][0], id[j][1], 1, x);
        }
    }


    spfa();  // 先求出初始势能
    // dijkstra();
    // cout << dis[t] << endl;
    int ttt = 0;
    while (dijkstra()) {
        int minf = INF;
        for (int i = 1; i <= n; i++) h[i] += dis[i];
        ttt ++;
        cerr << ttt << " " << t << " " << p[t].v << endl;
        for (int i = t; i != s; i = p[i].v) {
            if(ttt == 5) {
                cerr << " -- " << i << endl;
            }
            minf = min(minf, e[p[i].e].f);
        }

        ttt ++;
        cerr << ttt << " " << t << " " << p[t].v << endl;

        for (int i = t; i != s; i = p[i].v) {
            e[p[i].e].f -= minf;
            e[p[i].e ^ 1].f += minf;
        }
        maxf += minf;
        minc += minf * h[t];
    }
    printf("%d %d\n", maxf, minc);
}

int main() {

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
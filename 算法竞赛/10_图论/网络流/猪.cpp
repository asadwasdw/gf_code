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
int h[N],ne[N],e[N],f[N],idx;
int cur[N],d[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++; 
}

bool bfs() {
    queue<int> q;
    memset(d, -1, sizeof d);
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

int mark[N];
int a[N];
void solve()
{
    memset(h, -1, sizeof h);
    int m, n;
    cin >> m >> n;
    S = 0, T = n + m + 1;
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        a[i] = x;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int keys,w;
        cin >> keys;
        for(int j = 1; j <= keys; j++) {
            int x; cin >> x;
            if(mark[x] == 0) {
                add(S, i, a[x]);
               
            }
            else {
                add(mark[x] , i, INF);
            }
             mark[x] = i;
        }
        cin >> w;
        add(i, T, w);
       // ans += dinic();
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
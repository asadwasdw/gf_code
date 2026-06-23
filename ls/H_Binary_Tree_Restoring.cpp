#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;

typedef pair<int,int>PII;
const int N= 4e5 + 10, M = 2e6 + 10;
int k; PII E[N];
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
int n, m;

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

int id2[N][2];
int idw[N];

int cnt = 0;
int newnode() {
	return cnt ++;
}
int S, T;

namespace PD
{
    int h[N], ne[M], e[M], f[M], w[M], idx = 2;
    void add(int x, int y, int z, ll cc) {
		e[idx] = y, f[idx] = z, w[idx] = cc, ne[idx] = h[x], h[x] = idx++;
	}
    void adde(int x, int y, int z, ll cc) {add(x, y, z, cc); add(y, x, 0, -cc);}
	
    int deg[N];
    ll d[N], pot[N];
	int ans = 0;

    void init()
    {
	
        bool vis[N] = {};
        queue<int> q; q.push(S); vis[S] = 1;
        while(q.size())
        {
            int u = q.front(); q.pop();
            for(int i = h[u]; i; i = ne[i])
            {
				int v = e[i];
                if(!f[i]) continue;
                deg[v] ++;
                if(vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        while(q.size()) q.pop();
        q.push(S);
        memset(pot, 0x3f, sizeof pot);
        pot[S] = 0;
        while(q.size())
        {
            int u = q.front(); q.pop();
            for(int i = h[u]; i; i = ne[i])
            {
				int v = e[i];
                if(!f[i]) continue;
                pot[v] = min(pot[v], pot[u] +  w[i]);
                if(!--deg[v]) q.push(v);
            }
        }
    }
    int pre[N], incf[N];
    int find(int x)
    {
        int flow = incf[T];
        for(int u = T; u != S; u = e[pre[u] ^ 1])
        {
            f[pre[u]] -= flow;
            f[pre[u] ^ 1] += flow;
            ans += flow *  w[pre[u]];
        }
        return flow;
    }
    bool dij()
    {
        using PII = pair<ll, int>;
        priority_queue<PII, vector<PII>, greater<PII>> q;
        bool vis[N] = {};
        memset(d, 0x3f, sizeof d);
        d[S] = 0;
        q.push({0, S});
        incf[S] = 1e9;
        while(q.size())
        {
            int u = q.top().second; q.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = h[u]; i; i = ne[i])
            {
				int v = e[i];
                ll c0 =  w[i] + pot[u] - pot[v];
                if(!f[i]) continue;
                if(d[v] <= d[u] + c0) continue;
                pre[v] = i, incf[v] = min(incf[u], f[i]);
                d[v] = d[u] + c0;
                q.push({d[v], v});
            }
        }
        for(int i = 0; i <= cnt; i ++) pot[i] += d[i];
        return d[T] <= 1e16;
    }
    int dinic()
    {
        init();
        int ans = 0;
        while(dij()) ans += find(S);
        return ans;
    }
}


void solve()
{
    S = newnode();
    T = newnode();
   
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
    
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x; idw[sccno[i]] += x;
    }

	for(int i = 1; i <= sccnt; i ++) {
        id2[i][0] = newnode();
        id2[i][1] = newnode();
	}

    
    for(int i = 1; i <= sccnt; i ++) {
        PD::adde(id2[i][0], id2[i][1], k, 0);
        PD::adde(id2[i][0], id2[i][1], 1, -idw[i]);
        PD::adde(id2[i][1], T, k, 0);
    }

    PD::adde(S, id2[sccno[1]][0], k, 0);
    for(int i = 1; i <= m; i ++) {
        auto [u, v] = E[i];
        if(sccno[u] == sccno[v]) continue;
        PD::adde(id2[sccno[u]][1], id2[sccno[v]][0], k, 0);
    }
	PD::dinic();
	cout << -PD::ans << endl;
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
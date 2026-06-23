#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
const int N = 3e2 + 1, M = 100 * N;
namespace PD
{
    int S, T;
    int h[N], ne[M], e[M], f[M], w[M], idx = 2;
    void adde(int x, int y, int z, ll cc) {
		e[idx] = y, f[idx] = z, w[idx] = cc, ne[idx] = h[x], h[x] = idx++;
	}
    void add(int x, int y, int z, ll cc) {adde(x, y, z, cc); adde(y, x, 0, -cc);}
	int cnt = 0;


    int deg[N];
    ll d[N], pot[N];
	int ans = 0;
    
    int newnode() {
        return cnt ++;
    }
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

using namespace PD;

int id[15][15][2];

void solve()
{
    int n;
    cin >> n;
    S = newnode();
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            id[i][j][0] = newnode();
            id[i][j][1] = newnode();
            add(id[i][j][0], id[i][j][1], 2, 0);
            if(i != 1) add(id[i - 1][j][1], id[i][j][0], 2, 0);
            if(j != 1) add(id[i][j - 1][1], id[i][j][0], 2, 0);
        }
    }

    T = newnode();

    while(1) {
        int x, y, w;
        cin >> x >> y >> w;
        if(x == 0) break;
        add(id[x][y][0], id[x][y][1], 1, -w);
    }

    add(S, id[1][1][0], 2, 0);
    add(id[n][n][1], T, 2, 0);

    dinic() ;
    cout << -ans << endl;
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
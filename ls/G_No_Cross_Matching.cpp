#include<bits/stdc++.h>
using namespace std;
typedef long double ll;
typedef pair<int,int>PII;

#define endl "\n" 
#define x first
#define y second

const int N= 4e5 + 10, M = 2e6 + 10;
int k; PII E[N];
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;



int n, m;
namespace PD
{
    int S, T;
    int h[N], ne[M], e[M], f[M],  idx = 2;
    ll w[M];
    void add(int x, int y, int z, ll cc) {
		e[idx] = y, f[idx] = z, w[idx] = cc, ne[idx] = h[x], h[x] = idx++;
	}
    void adde(int x, int y, int z, ll cc) {
        add(x, y, z, cc); add(y, x, 0, -cc);
    }
	int cnt = 0;

    int deg[N];
    ll d[N];
    ll pot[N];
	ll ans = 0;
    
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

        for(int i = 0; i < N; i ++) pot[i] = INF;
        pot[S] = 0;
        while(q.size())
        {
            int u = q.front(); q.pop();
            for(int i = h[u]; i; i = ne[i])
            {
				int v = e[i];
                if(!f[i]) continue;
                pot[v] = min(pot[v], pot[u] + w[i]);
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
        for(int i = 0; i <= cnt; i ++) d[i] = INFll;
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

PII P[N],Q[N];
int idp[N],idq[N];

double len(int i, int j) {
    int x = P[i].x - Q[j].x;
    int y = P[i].y - Q[j].y;
    return sqrtl(x*x + y*y);
}

void solve()
{
    PD::S = PD::newnode();
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        idp[i] = PD::newnode();
        cin >> P[i].x >> P[i].y;

    }

    for(int i = 1; i <= n; i ++) {
        idq[i] = PD::newnode();
        cin >> Q[i].x >> Q[i].y;
    }

    PD::T = PD::newnode();

    for(int i = 1; i <= n; i ++) {
        PD::adde(PD::S, idp[i], 1, 0);
        PD::adde(idq[i], PD::T, 1, 0);
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            // cout << i << " " << j << " " << len(i, j) << endl;
            PD::adde(idp[i],idq[j],1,len(i,j));
        }
    }
    PD::dinic();

    for(int i = 1; i <= n; i ++) {
        for(int j = PD::h[idp[i]];~j; j= PD::ne[j]) {
            int v = PD::e[j];
            if(v > n && v <= 2*n) {
                if(PD::f[j^1]) {
                    cout << v - n << " ";
                    break;
                }
            }
        }
    }

    


}


signed main()
{
    memset(PD::h, -1,sizeof PD::h);
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
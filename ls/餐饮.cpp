#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int S,T;
struct cow
{
    int in,to;
}c[110];

int e[N],ne[N],f[N],idx,h[N];
int d[N],cur[N];

void add(int a, int b, int c) {
    //cout<<a<<" "<<b<<endl;
    e[idx] = b, ne[idx] = h[a], f[idx] = c,h[a] = idx++;
    e[idx] = a, ne[idx] = h[b], f[idx] = 0,h[b] = idx++;
}

bool bfs() {
    queue<int> q;
    memset(d, -1, sizeof d);
    d[S] = 0, cur[S] = h[S],q.push(S);

    while(q.size()) {
        int u = q.front(); q.pop();

        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(f[i] && d[v] == -1) {
                cur[v] = h[v];
                d[v] = d[u] + 1;
                if(v == T) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int find(int u, int limit) {
    if(u == T)return limit;

    int flow = 0;
    for(int i = cur[u]; ~i && flow < limit; i = ne[i]) {
        int v = e[i];
        cur[u] = i;

        if(f[i] && d[v] == d[u] + 1) {
            int t = find(v, min(f[i], limit - flow));
            if(t == 0) d[v] = -1;
            f[i] -= t,f[i ^ 1] += t,flow += t;
        }
    }
    return flow;
}


int dinic() {
    int ans = 0, flow;
    while(bfs()) if(flow = find(S,INF)) ans += flow;
    return ans;
}



void solve()
{
    memset(h, -1, sizeof h);
    int n,f,d;
    cin >> n >> f >> d;
    S = N - 2,T = N - 1;

    for(int i = 1;i <= f;i++) {
        add(S, 2 * n + i, 1);
    }

    for(int i = 1;i <= d; i++) {
        add( 2 * n + i + f, T, 1);
    }

    for(int i = 1 ; i <= n ; i++){
        c[i]={2 * i - 1 , 2 * i};
        add(c[i].in, c[i].to, 1);

        int a ,b;
        cin >> a >> b;
        while(a--) {
            int t;cin>>t;
            add(2 * n + t, c[i].in, 1);
        }

        while(b--) {
            int t;cin>>t;
            add( c[i].to, 2 * n + f + t, 1);
        }
    }
    
    cout << dinic() <<endl;
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
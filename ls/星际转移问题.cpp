#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n, m, k,S,T;
int p[N];
int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}
int get(int day, int x){
    return day * (n + 2) + x;
}

struct Ship{
    int h, r, id[300];
}ships[300];

int h[N],ne[N],e[N],f[N],idx;
int d[N],cur[N];

void add(int a,int b,int c)
{
    //cout << a << " " << b << " " << c << endl;
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx++;
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
    cin >> n >> m >> k;
    S = N - 2, T = N - 1;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n + 1; i++) p[i] = i;
    for(int i = 1; i <= m; i++) {
        cin >> ships[i].h >> ships[i].r;
        for(int j = 0;j < ships[i].r; j++) {
            int x; cin >> x;
            if(x == -1) x = n + 1;
            ships[i].id[j] = x;

            if(j) {
                int y = ships[i].id[0];
                int fx = find(x), fy = find(y);
                if(fx == fy)continue;
                p[fx] = fy; 
            }
        }
    }

    if(find(0) != find(n + 1)) cout<<"0";
    else {
        int ans = 0,day = 0;
        //cout << "\nday: " <<day<<endl;
        add(S, get(0, 0), k);
        add(get(0, n + 1), T, INF);
        
        while(ans < k) {
            day ++ ;
           // cout << "\nday: " <<day<<endl;
            for(int i = 0; i <= n + 1; i++) {//留在空间站的
                add(get(day - 1, i),get(day, i),INF);
            }

            for(int i = 1; i <= m; i++) {
                int x = ships[i].id[(day - 1) % ships[i].r];
                int y = ships[i].id[(day) % ships[i].r];
                add(get(day - 1, x), get(day, y), ships[i].h);
            }

            add(get(day, n + 1), T, INF);
            ans += dinic();
        }

        cout << day << "\n";
    }

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
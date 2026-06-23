#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 



//vector<vector<int>>adj(N);
const int N=4e3+10, M = 2 * 2 * 300 * 300 + N * 2 + 10;
int n, m, S, T;
int h[N], ne[M], e[M], f[M], idx;
int d[N],cur[N];

void add(int a, int b, int c) {
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++;
}

bool bfs() {
    // memset(d, -1, sizeof(int) * (T + 10));
    memset(d, -1, sizeof d);
    queue<int> q;
    q.push(S), d[S] = 0, cur[S] = h[S];

    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(d[v] == -1 && f[i]) {
                d[v] = d[u] + 1;
                cur[v] = h[v];
                q.push(v);
            }
        }
    }
    return d[T] != -1;
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




void solve()
{
    memset(h, -1, sizeof h);
    int m, n;
    cin >> m >> n;
    S = 0, T = n + m + 1;
    int sum = 0;
    for(int i = 1; i <= m; i ++) {
        int x; cin >> x;
        sum += x;
        add(S, i, x);
    }
    for(int i = 1; i <= n; i ++) {
        int p;
        cin >> p;
        while(p --) {
            int x; cin >> x;
            add(x, i + m, 1);
        }
        add(i + m, T, 1);
    }
    // cout << dinic() << endl;

    if(dinic() == sum) {
        vector<vector<int>> V(m + 1, vector<int>(0));
        for(int i = 0; i < idx; i += 2) {
            int v = e[i], u = e[i ^ 1];
            if(u == S || v == T) continue;
            if(f[i]) continue;
            // cout << u << " " << v - m << endl; 
            V[u].push_back(v - m);
        }

        for(int i = 1; i <= m; i ++) {
            cout << i << ": ";
            sort(V[i].begin(), V[i].end());
            for(auto t : V[i]) {
                cout << t << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No Solution!";
    }


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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10, M = 2e6 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int h[N], ne[M], e[M], idx;
int d1[N], d2[M];
int n, m, s;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
    e[idx] = a, ne[idx] = h[b], h[b] = idx ++;
}


void bfs1() {
    queue<int> q;
    for(int i = 1; i <= n; i ++) d1[i] = INF;
    vector vis(n + 1, false);
    d1[s] = 0, q.push(s), vis[s] = true;
    
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(v == 1) continue;
            if(vis[v]) continue;
            vis[v] = true;
            d1[v] = d1[u] + 1;
            q.push(v);
        }
    }
}

ll ans = INF;

void bfs2() {
    queue<int> q;
    vector vis(idx + 1, false);
    vector sum(n + 1, 0);
    for(int i = 0; i <= idx; i ++) d2[i] = INF;
    for(int i = h[n]; ~i; i = ne[i]) {
        // cout << i << endl;
        q.push(i);
        d2[i] = 0;
    }

    while(q.size()) {
        int i = q.front(); q.pop();
        if(vis[i]) continue;
        int u = e[i ^ 1];
        int fi = i ^ 1;

        if(u == 1) {
            ans = min(1ll * d1[e[i]] + d2[i], ans);
        }

        vis[i] = true;

        ++sum[u];
        if(sum[u] > 2) continue;
        
        for(int j = h[u]; ~j; j = ne[j]) {
            int v = h[j];
            int fj = j ^ 1;
            if(j == i) continue;
            if(vis[fj]) continue;
            if(d2[fj] > d2[i] + 1) {
                d2[fj] = d2[i] + 1;
                q.push(fj);
            }
        }
    }
}


void solve()
{
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        add(u, v);
    }

    bfs1();
    // for(int i = 1; i <= n; i ++) cout << d1[i] << " \n"[i == n];

    bfs2();
    // for(int i = 0; i < idx; i ++) {
    //     cout << i << " : " << e[i ^ 1] << "->" << e[i] << " " << d2[i] << endl;
    // }
    if(ans < INF / 2) {
        cout << "Vegetable fallleaves" << endl;
        cout << ans << endl;
    } else {
        cout << "Boring Game" << endl;
    }

    ans = INF;
    for(int i = 1; i <= n; i ++) h[i] = -1; idx = 0;
}


signed main()
{
    memset(h, -1, sizeof h);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
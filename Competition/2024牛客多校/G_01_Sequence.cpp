#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int h[N], ne[N], e[N], w[N], idx;

void add(int a, int b, int c) {
    // cout << a << " " << b << " " << c << endl;
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) add(0, i, 0), add(i - 1, i, 0), add(i, i - 1, -1);
    for(int i = 1; i <= m; i ++) {
        int l, r, c; cin >> l >> r >> c;
        add(l - 1, r, c);
    }

    // priority_queue<PII, vector<PII>, vector<PII>> q;
    stack<int> q;
    q.push(0);
    vector dis(n + 1, -INF), vis(n + 1, 0);
    dis[0] = 0, vis[0] = 1;

    while(q.size()) {
        int u = q.top(); q.pop();
        vis[u] = 0;

        for(int i = h[u]; ~i; i = ne[i]) {
            int v = e[i];
            if(dis[u] + w[i] > dis[v]) {
                dis[v] = dis[u] + w[i];
                if(vis[v]) continue;
                // cout << v << endl;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    
    for(int i = 1; i <= n; i ++) {
        cout << dis[i] - dis[i - 1] << " \n"[i == n];
    }

}


signed main()
{
    memset(h, -1, sizeof h);
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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<int>>adj(N);
int c[N];
int dis[N][2];
int ans = 0;

void dfs(int u, int fa) {
    dis[u][0] = c[u];
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs(v, u);
        int t = dis[v][0] + c[u];
        if(t >= dis[u][0]) {
            dis[u][1] = dis[u][0];
            dis[u][0] = t;
        } else if(t > dis[u][1]) {
            dis[u][1] = t;
        }
    }

    // cout << u << ' ' << dis[u][0] << " " << dis[u][1] << endl;
    ans = max(ans, dis[u][0] + dis[u][1] - c[u]);
}

void solve()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
        cnt += c[i];
    }

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    if(ans == cnt) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    ans = 0;
    for(int i = 1; i <= n; i ++) {
        dis[i][0] = dis[i][1] = 0;
        adj[i].clear();
    }






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}
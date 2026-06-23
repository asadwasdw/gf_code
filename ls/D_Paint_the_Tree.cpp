#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
int n,m;
int a[N];
int s,t;
int sz[N];
int l = 0;
int r = 0;
void dfs(int u, int fa, int dep) {
    sz[u] = 1;
    if(u == t) l = dep;
    r = max(r, dep);
    for(auto v : edg[u]) {
        if(v == fa) continue;
        dfs(v, u, dep + 1);
        sz[u] += sz[v];
    }
}

bool st[N];
int dis[N];
int dis2[N];

int ans = 0;
int root;
void js(int s, int t) {
    if(s == t) {
        root = s;
        return;
    }

    for(int i = 1; i <= n; i++) st[i] = 0,dis[i] = dis2[i] = 0;
    queue<int> q;
    q.push(t);
    dis[t] = 0; 
    st[t] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto v : edg[u]) {
            if(st[v]) continue;
            dis[v] = dis[u] + 1;
            st[v] = true;
            q.push(v);
        }
    }

    // for(int i = 1; i <= n; i ++) cout << dis[i] << " \n"[i == n];

    for(int i = 1; i <= n; i++) st[i] = 0;
    q.push(s);
    dis2[s] = 0; 
    st[s] = true;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(auto v:edg[u]) {
            if(st[v]) continue;
            st[v] = true;
            dis2[v] = dis2[u] + 1;
            if(dis2[v] >= dis[v]) {
                // cout << v << " " << dis[v] << " " << dis2[v] << endl;
                if(dis[v] == dis2[v]) ans = dis[v];
                else ans = dis[v] + 2;
                root = v;
                return;
            }
            q.push(v);
        }
    }
}

void solve()
{
    l = r = 0;root = 0;
    int res = INF;
    cin >> n;
    cin >> s >> t;
    ans = 0;
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    {
        js(s, t);
        dfs(root, 0, 0);
        // cout << root << " " << r << " " << ans << endl;
        res = min(res,(sz[root] - 1) * 2 - r + ans);
    }

    {
        r = 0;
        dfs(s,0,0);
        res = min(res, (sz[s] - 1) * 2 - r + l);
    }

    cout << res << endl;

    for(int i = 1; i <= n; i++) {
        edg[i].clear();
        sz[i] = 0;
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
}
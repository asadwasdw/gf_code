#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);
int n, m, low[N], dfn[N],tim,dcc_cnt,id[N];
int a[N];
stack<int> stk;

int f[N];
int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    f[u] = v;
}

void tarjan(int u,int fa)
{
    dfn[u]=low[u]=++tim;
    stk.push(u);

    for(auto v:adj[u]){
        if(!dfn[v]){
            tarjan(v,u);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=fa)
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        dcc_cnt++;
        while(1)
        {
            int v = stk.top();stk.pop();
            id[v] = dcc_cnt;
            merge(v, u);
            if(u==v)break;
        }
    }
}



vector<array<int, 3>> edg;

void solve()
{

    cin >> n >> m;
    for(int i = 1; i <= n; i ++) f[i] = i;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        string s;
        cin >> u >> v >> s;
        if(s == "Lun") w = 1;
        else w = 0;
        if(w){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        edg.push_back({u, v, w});

    }

    
    for(int i = 1; i <= n; i ++) {
        if(low[i] == 0) tarjan(i, -1);
        // cout << i << " " << find(i) << endl;
    }

    vector<PII> ans;
    for(auto [u, v, w] : edg) {
        if(w && id[u] == id[v]) ans.push_back({u, v});

        if(w == 0) {
            int fu = find(u), fv = find(v);
            if(fu != fv) {
                merge(u, v);
                ans.push_back({u, v});
            }
        }
    }

    // cout << "-\n";

    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        // cout << i << " " << find(i) << endl;
        if(find(i) == i) cnt ++;
    }

    if(cnt != 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ans.size() << endl;
    for(auto [u, v] : ans) {
        cout << u << " " << v << endl;
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
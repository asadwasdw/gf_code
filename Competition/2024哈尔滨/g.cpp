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
vector<vector<int>> ans;
int vis[N], bj[N];
int now = 0;
void dfs(int u) {
    vis[u] = 1;
    if(bj[u]) return;
    int dfn = ++ now;
    vector<int> t;
    t.push_back(u);
    for(auto v : adj[u]) {
        if(vis[v]) continue;
        dfs(v);
        t.push_back(v);
    }
    if(t.size() > 1)ans.push_back(t);
    return;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1; i <= k; i ++) {
        int x; cin >> x; bj[x] = 1;
    }

    for(int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i = 1; i <= n; i ++) {
        if(!bj[i]) {
            dfs(i);
            break;
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(vis[i] == 0) {
            cout << "No";
            return;
        }
    }
    cout << "Yes\n";
    cout << ans.size() << endl;

    for(int i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i][0] << " ";
        cout << ans[i].size() - 1 << " ";
        for(int j = 1; j < ans[i].size(); j ++) cout << ans[i][j] << " ";
        cout << endl; 
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
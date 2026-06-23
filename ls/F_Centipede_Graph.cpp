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

int ans = 0;
int dfs(int u, int fa) {
    int res = 0;
    vector<int> tt;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        int t = dfs(v, u);
        tt.push_back(t);
        if(adj[u].size() >= 3) ans = max(ans, t + 1);
        if(adj[u].size() >= 4) res = max(t + 1, res);
    }
    if(res == 0 && adj[u].size()>= 2)  ans = max(ans, 1);
    if(res == 0 && adj[u].size() >= 3) res = 1;

    sort(tt.begin(), tt.end(), [&](int a, int b){
        return a > b;
    });

    if(adj[u].size() >= 4) {
        ans = max(ans, tt[0] + tt[1] + 1);
    }

    ans = max(res, ans);

    return res;
}

void solve()
{
    int n;
    cin >> n;

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans << endl;
    // cout << "S" << endl;

    for(int i = 1; i <= n; i ++) adj[i].clear();
    ans = 0;
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
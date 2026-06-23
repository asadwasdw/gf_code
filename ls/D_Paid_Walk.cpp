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

vector<vector<PII>>adj(N);

int n, m, l, s, t;
map<ll,bool> st;
void dfs(int u, int l, ll dis) {
    // cout << u << endl;
    if(l == 0) {
        // cout << u << " " << l << " " << dis << endl; 
        if(s <= dis && dis <= t) {
            // cout << u << " " << dis << endl;
            st[u] = true;
        }

        return ;
    }


    for(auto [v, w] : adj[u]) {
        dfs(v, l - 1, dis + w);
    }
}

void solve()
{
    cin >> n >> m >> l >> s >> t;

    for(int i = 1; i <= m; i ++) {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    dfs(1, l, 0);

    for(int i = 1; i <= n; i ++) if(st[i]) cout << i << " ";

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
    return 0;
}
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

int a[N];

int cnt[N];
int ans = 0;

int dfs(int u) {
    if(cnt[u] != -1) return cnt[u];
    cnt[u] = 1;
    for(auto v : adj[u]) {
        dfs(v);
        cnt[u] += dfs(v);
    }

    return cnt[u];
}


void solve()
{
    memset(cnt, -1, sizeof cnt);
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        if(a[u] > a[v]) {
            adj[u].push_back(v);
            // cout << u << " " << v << endl;
        }
        if(a[v] > a[u])  {
            adj[v].push_back(u);
            // cout << v << " " << u << endl;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, dfs(i));
    }
    cout << ans << endl;


    




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
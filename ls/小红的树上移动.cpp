#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
int ans = 0;
vector<vector<int>>adj(N);

ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}

void dfs(int u, int fa, int p, int dep) {
    if(adj[u].size() == 1 && u != 1) {
        // cout << p << " " << dep << endl;
        ans += p * dep % mod;
        ans %= mod;
    }

    for(auto v : adj[u]) {
        if(v == fa) continue;
        int num = adj[u].size();
        if(u != 1) num --;
        dfs(v, u, p * qmi(num, mod - 2) % mod, dep + 1);
    }
}




void solve()
{

    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n == 1) {
        cout << 1;
        return;
    }

    dfs(1, 0, 1, 1);
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
}
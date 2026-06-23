#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
int n, k;
vector<vector<int>>adj(N);
int sz[N];
int ans = 0;
void dfs1(int u, int fa) {
    sz[u] = 1;
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
    if(sz[u] >= k)ans++;
}

int mx = 0;
int tr[N];
void add(int k, int x) {
    for(int i = k; i < N; i += i&-i) tr[i] += x;
}

int get(int k) {
    int res = 0;
    for(int i = k; i ; i -= i&-i) res += tr[i];
    return res;
}



void dfs2(int u, int fa) {
    add(sz[u], 1);
    for(auto v : adj[u]) {
        if(v == fa) continue;
        int sum = get(N - 1);
        int cnt1 = sum - get(k - 1), cnt2 = sum - get(k + sz[v] - 1);
        mx = max(cnt1 - cnt2, mx);
        // cout << sz[v] << " : " << cnt1 << " " << cnt2 << endl; 
    }

    
    for(auto v : adj[u]) {
        if(v == fa) continue;
        dfs2(v, u);
    }
    add(sz[u], -1);
}



void solve()
{
    // int n, k;
    cin >> n >> k;
    k ++;
    for(int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans - mx<< endl;

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
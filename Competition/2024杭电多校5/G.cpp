#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);

struct gfDSU {
    int n;
    vector<int> f, sz;

    void init(int _n) {
        n = _n;
        f.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 0; i <= n; i ++) f[i] = i, sz[i] = 1;
    }

    int find(int x) {
        if(x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        sz[y] += sz[x];
        f[x] = y;
    }
    void debug() {
        for(int i = 0; i <= n; i ++) cout << f[i] << " \n"[i == n];
        for(int i = 0; i <= n; i ++) cout << sz[i] << " \n"[i == n];
    }
}dsu;

void solve()
{   
    int n, m;
    cin >> n >> m;
    dsu.init(n + 1);
    for(int i = 0; i <= n; i ++) adj[i].clear();
    map<PII,bool> mp;
    mp.clear();
    for(int i = 1; i < n; i ++) {
        int x, y; cin >> x >> y;
        if(x>y)swap(x, y);
        adj[x].push_back(y);
        
    }

    for(int i = 1; i <= m; i ++) {
        int x, y; cin >> x >> y;
        dsu.merge(x, y);
        if(x>y)swap(x, y);
        mp[{x, y}] = true;
    }
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(i == dsu.find(i)) ans ++;
    }
    vector<int> bjf(n + 1, 0);

    for(int u = 1; u <= n; u ++) {
        for(auto v : adj[u]){
            if(dsu.find(v) == dsu.find(u) && bjf[dsu.find(u)] == 0) {
                if(mp.count({u, v}) == 0) {
                    bjf[dsu.find(u)] = 1;
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}


signed main()
{
    // freopen("1007.out","w",stdout); 
    // freopen("1007.in","r",stdin); 

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
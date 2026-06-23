#include<bits/stdc++.h>
#define int long long
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
    int n, k;
    cin >> n >> k;
    dsu.init(n);
    vector<vector<int>>adj(100);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];

    int tar = 0;
    for(int i = 63; i >= 0; i --) {
        if((k >> i) & 1) {
            tar = i;
            break;
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 63; j > tar; j --) {
            if(a[i] >> j & 1) {
                adj[j].push_back(i);
            }
        }
    }
    vector<int> vis(n + 1, 1);
    for(int i = 1; i <= n; i ++) {
        for(int j = tar; j >= 0; j --) {
            if(((k >> j) & 1) == 0) {
                if(vis[i] && (a[i] >> j) & 1) {
                    adj[j].push_back(i);
                }
            }

            if(((k >> j) & 1) && vis[i] && ((a[i] >> j) & 1) == 0) vis[i] = 0;
        }
    }


    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            v.push_back(i);
        }
    }

    for (int i = 1; i < v.size(); i++) {
        dsu.merge(v[i], v[i - 1]);
    }

    for(auto v : adj) {
        cout << v.size() << endl;
        for(int i = 1; i  < v.size(); i ++) {
            // cout << v[i] << " " << v[i - 1] << endl;
            dsu.merge(v[i], v[i - 1]);
        }
    }
    int ans = 0;

    for(int i = 1; i <= n; i ++) {
        if(dsu.find(i) == i) ans = max(dsu.sz[i], ans);
    }
    cout << ans << endl;


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
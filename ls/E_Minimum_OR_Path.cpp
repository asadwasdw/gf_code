#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
struct gfDSU {
    int n;
    vector<int> f, sz, color, l;

    void init(int _n) {
        n = _n;
        f.resize(n + 1);
        sz.resize(n + 1);
        color.resize(n + 1);
        l.resize(n + 1);
        for(int i = 0; i <= n; i ++) f[i] = i, sz[i] = 1, color[i] = i, l[i] = i;
    }

    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }

    int findl(int x) {
        return l[find(x)];
    }

    int findcolor(int x) {
        return color[find(x)];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return; 
        sz[y] += sz[x];
        l[y] = l[x];
        f[x] = y;
    }
    void debug() {
        for(int i = 0; i <= n; i ++) cout << f[i] << " \n"[i == n];
        for(int i = 0; i <= n; i ++) cout << sz[i] << " \n"[i == n];
    }
}dsu;

struct edg
{
    int u, v, w;
}e[N];



void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
    }

    int ans = 0, t = 0;

    for(int i = 30; ~i; i --) {
        dsu.init(n);
        t ^= (1 << i);
        for(int j = 1; j <= m; j ++) {
            if(!(e[j].w & t)) dsu.merge(e[j].u, e[j].v);
        } 

        if(dsu.find(1) != dsu.find(n)) ans ^= (1 << i), t ^= (1 << i);
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
}
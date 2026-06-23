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

//vector<vector<int>>adj(N);

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

int a[N];

void solve()
{
    int n, q; cin >> n >> q;
    dsu.init(n + 10);
    map<int,int> num;
    for(int i = 1; i <= n ; i ++) {
        a[i] = i;
        dsu.color[i] = i;
        num[i] ++;  
    }

    while(q --) {
        int op, id, x;
        cin >> op;
        if(op == 1) {
            cin >> id >> x;
            
            int l = dsu.findl(id);
            int r = dsu.find(id); 

            num[dsu.findcolor(r)] -= dsu.sz[r];
            dsu.color[r] = x;
            num[x] += dsu.sz[r];

            if(dsu.findcolor(l - 1) == dsu.findcolor(r)) {
                dsu.merge(l - 1, l);
            }

            if(dsu.findcolor(r) == dsu.findcolor(r + 1)) {
                dsu.merge(r, r + 1);
            }
        } else {
            cin >> x;
            cout << num[x] << endl;
        }
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
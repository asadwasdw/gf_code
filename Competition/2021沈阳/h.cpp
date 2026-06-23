#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);
int h[N], ne[N], e[N], idx, iscut[N], w[N];

void add(int a, int b, int c) {
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}
int low[N], now, dfn[N], d[N], sz[N]; 
// dfs树上， 每个子树的点度数和

int mi = INF, totedg = 0;
void dfs(int u, int fa) {
    low[u] = dfn[u] = ++ now;
    sz[u] = d[u];
    int child = 0;
    for(int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if(!dfn[v]) {
            dfs(v, u);
            sz[u] += sz[v];
            low[u] = min(low[v], low[u]);
            if(low[v] > dfn[u]) { // v可以跑的最小的点在依旧小于u 所以这条边是桥
                if((sz[v] - 1)/2%2 == 0) {
                    // 下面是偶数 如果上面是奇数， 偶边图，不管
                    mi = min(mi, w[i]);
                }
            } else {
                mi = min(mi, w[i]);
            }
        } else if(dfn[v] < dfn[u] && v != fa) { //找到一条反祖边
            low[u] = min(low[u], dfn[v]);
            mi = min(mi, w[i]);
        }
        if(dfn[v] > dfn[u]) ++ totedg;
    }
}



void solve()
{
    int n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 1; i <= m; i ++) {
        int a, b, c; cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
        d[a] ++, d[b] ++;
        ans += c;
    }

    for(int i = 1; i <= n; i ++) {
        if(dfn[i] == 0) {
            mi = INF, totedg = 0;
            dfs(i, i);
            if(totedg & 1) ans -= mi;
        }
    }
    cout << ans << endl;
}


signed main()
{
    memset(h, -1, sizeof h);
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
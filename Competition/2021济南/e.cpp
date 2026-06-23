#include<bits/stdc++.h>
using namespace std;
#define int long long
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

int times[1010];

void solve()
{
    int n, m; cin >> n >> m;
    vector vis(n + 1, vector<ll> (n + 1));
    vector<PII> edge(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if(u > v) swap(u, v);
        edge[i] = {u, v};
        vis[u][v] = vis[v][u] = u + v;
    }
    // for (int i = 1; i <= n; i++)
    // for (int j = 1; j <= n; j++)
    //     cerr << vis[i][j] << " \n"[j == n];
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        vis[i][j] += vis[i - 1][j];

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
        vis[i][j] += vis[i][j - 1];

    vector<ll> res1(n + 1);

    auto js = [&](ll x1, ll y1, ll x2, ll y2) ->ll {
        // if(x2 < x1) return 0;
        // if(y2 < y1) return 0;
        return vis[x2][y2] - vis[x1 - 1][y2] - vis[x2][y1 - 1] + vis[x1 - 1][y1 - 1];
    };

    auto calc = [&](ll u, ll v) -> ll {
        if(js(u, v, u, v) == 0) return 0;
	    if(u > v) swap(u, v);
        ll x1 = u + 1, x2 = v - 1;
        ll y2 = v + 1, y1 = u - 1;
        return js(x1,1,x2,y1) + js(x1,y2,x2,n);
    };

    ll sum = 0;
    for (auto [u, v] : edge) {
        ll tmp = calc(u, v) * (u + v);
        // cerr << tmp << ' ' << u << ' ' << v << "\n";
        sum += tmp;
        res1[u] += tmp;
        res1[v] += tmp;

    }
    
    sum/=2;
    ll ans = 0;



    for(int u = 1; u <= n; u ++) {
        memset(times, 0, sizeof times);
        for(int j = 0; j < m; j ++) {
            if(edge[j].x == u || edge[j].y == u) continue;
            int sum = 0;
            



        }
    }

	for(int i = 1; i <= n; i++) { // 枚举点
		memset(times, 0, sizeof(times));
		for(int j = 0; j < m; j++) { // 枚举边
            if(edge[j].x != i && edge[j].y != i) { //去掉经过i的 
                int sum = 0;
                if(i > edge[j].x && i < edge[j].y) { // 查所有过i的点的边，但不和相交的
                    sum = js(i, 1, i, edge[j].x - 1) + js(i, edge[j].y + 1, i, n);
                } else {
                    sum = js(i, edge[j].x + 1, i, edge[j].y - 1);
                }
                times[edge[j].x] += sum * (edge[j].x + edge[j].y);// 把这些代价全存在点上
                times[edge[j].y] += sum * (edge[j].x + edge[j].y);
            }
        }
        // times[x] 所有代价中，不受i影响的部分

		for(int j = 1; j <= n; j++) if(i != j) {
			ans = max(ans, sum - res1[i] - res1[j] + times[j] + (i + j) * calc(i, j));
		}
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
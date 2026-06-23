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

int n;
ll a[2100];
ll b[20010][2100]; // 以i为跟一个端点，另一个端点在以i为根的子树中， 路径和为j的路径数
ll ans1, ans2;

void dfs(int u, int fa, int sum) {

    b[u][0] = 1;
    for(auto [v, w] : adj[u]) {
        if(v == fa) continue;
        int tsum = (sum + w) % 2019;
        a[tsum] ++;
        dfs(v, u, tsum);
        a[tsum] --;
        for(int i = 0; i < 2019; i ++) {
            int vi = ((2019 - i - w) % 2019 + 2019) % 2019;
            ans2 += (b[u][vi]) * b[v][i] % mod;
        }
    

        for(int i = 0; i < 2019; i ++) {
            b[u][(i + w)%2019] += b[v][i];
        }
    }


}

void solve()
{
    while(cin >> n) {
        ans1 = 0, ans2 = 0;
        for(int i = 1; i < n; i ++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        a[0] = 1;
        dfs(1, 0, 0);

        cout << ans1 + ans2 << endl;

        for(int i = 1; i <= n; i ++) {
            adj[i].clear();
            for(int j = 0; j < 2019; j ++) b[i][j] = 0, a[j] = 0;
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
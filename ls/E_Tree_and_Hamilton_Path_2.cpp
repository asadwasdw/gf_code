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

vector<vector<PII>>edg(N);
int n,m;
int a[N];
int dp[N];
int dis[N];


void dfs(int u, int fa) {

    for(auto [v, w] : edg[u]) {
        if(v == fa) continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
    }
}

void solve()
{
    cin >> n;
    int ans = 0;
    for(int i = 1; i < n; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v,w});
        edg[v].push_back({u,w});
        ans += w * 2;
    }

    dfs(1, 0);

    int p = 0, len = 0;
    for(int i = 1; i <= n; i ++) {
        if(dis[i] > len) {
            len = dis[i];
            p = i;
        }
    }
    memset(dis, 0, sizeof dis);
    dfs(p, 0);
    len = 0;
    for(int i = 1; i <= n; i ++) {
        if(dis[i] > len) {
            len = dis[i];
        }
    }
    cout << ans - len;


    





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
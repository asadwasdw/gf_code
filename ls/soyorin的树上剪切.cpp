#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<PII>>edg(N);
int c[N];
int n,s,t;
vector<int>dis;

int dp[N],deep[N];

void find(int u,int fa) {
    
    for(auto [v,w] : edg[u]) {
        if(v == fa) continue;
        if(c[v])continue;
        deep[v] = deep[u] + 1;
        dp[deep[v]] = min(dp[deep[v]],w);
        find(v,u);
    }
}

bool cmp (int a,int b ) {
    return a<b;
}

void solve()
{
    cin >> n >> s >> t;
    for(int i = 1; i < n; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v,w});
        edg[v].push_back({u,w});
    }
    c[t] = 1;

    auto dfs = [&](auto dfs, int u,int fa) {
        // cout << u << endl;
        if(c[u]) return;
        for(auto [v,w] : edg[u]) {
            if(v == fa) continue;
            dfs(dfs,v,u);
            if(c[v]) {
                c[u] = 1;
                dis.push_back(w);
            }
        }
    };


    memset(dp,0x3f,sizeof dp);

    dfs(dfs,s,0);


    for(int i=1;i<=n;i++) {
        if(c[i] && i != s) {
            for(auto [v,w] : edg[i]) {
                if(c[v])continue;
                edg[s].push_back({v,w});
            }
        }
    }
   find(s,0);

    int ans = 0;
    for(auto t:dis)ans += t;
    sort(dis.begin(),dis.end(),cmp);

    int k = dis.size();
    cout << ans << ' ';
    for(int i = 1;i < k;i ++) {
        ans -= dis.back();
        dis.pop_back();
        cout << ans << ' ';
    }
    for(int i = k; i <= n;i ++) {
        ans = min(dp[i - k], ans);
        cout << ans << ' ';
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
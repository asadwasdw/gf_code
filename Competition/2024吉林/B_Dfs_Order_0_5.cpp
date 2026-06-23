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

vector<vector<int>>edg(N);
int n,m;
int a[N];
int dp[N][2];
int sz[N];
bool son[N];
int ST[N][2];
void dfs(int u, int st ,int fa) {

    if(ST[u][st]) return;
    if(st == 0) dp[u][st] += a[u];
    vector<int> t;
    if(son[u]) {
        for(auto v:edg[u]) {
            if(v == fa) continue;
            dfs(v,st^1,u);
            dfs(v,st,u);
            if(sz[v] % 2  == 0 )
                dp[u][st] += max(dp[v][st],dp[v][st ^ 1]);
            else {
                t.push_back(dp[v][st ^ 1]-dp[v][st]);
                dp[u][st] += dp[v][st];
            }
        }


        sort(t.rbegin(),t.rend());
        int cnt = 0;
        for(auto T : t) {
            dp[u][st] += T;
            cnt++;
            if(cnt * 2 >= t.size()) break;
        } 

    }
    else {
        for(auto v:edg[u]) {
            if(v == fa) continue;
            dfs(v,st^1,u);
            dp[u][st] += dp[v][st ^ 1];
        }
    }

    // cout << u << " " << st << " " << dp[u][st] << endl;
    ST[u][st] = true;
}

void dfs1(int u,int fa) {
    ST[u][0] = ST[u][1] = false;
    dp[u][1] = dp[u][0] = 0;
    sz[u] = 1;
    son[u] = false;
    for(auto v : edg[u]) {
        if(v == fa) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[v] % 2) son[u] = true;
    }
}


void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }

    dfs1(1,0);
    dfs(1,1,0);
    cout << dp[1][1] << endl;
    // cout << "S";

    for(int i =  1; i <= n; i ++) {
        edg[i].clear();
    }

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
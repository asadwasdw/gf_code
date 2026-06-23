#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;

const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);
const int N=25+10;
int d[N][N];

int ans = 0;
int n, m;

void dfs(int u, int sum, vector<int> t) {
    ans = max(ans, sum);

    for(int v = 1; v <= n; v ++) {
        if(t[v]) continue;
        if(d[u][v] == 0) continue;
        vector<int> tt = t;
        tt[v] = 1;
        dfs(v, sum + d[u][v], tt);
    }   
}

void solve()
{

    cin >> n >> m;
    for(int j = 1; j <= m; j ++) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
    }
    

    for(int i = 1; i <= n; i ++) {
        vector<int> t(n + 1, 0);
        t[i] = 1;
        dfs(i, 0, t);
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
    return 0;
}
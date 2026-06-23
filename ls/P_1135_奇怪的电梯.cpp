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
int n, a, b;
int k[N];
int dis[N];
int ans = 1e9;

void dfs(int u) {
    for(int i = -1; i <= 1; i ++) {
        int v = u + i * k[u];
        if(v < 1|| v > n) continue;
        if(dis[v] <= dis[u] + 1) continue;
        dis[v] = dis[u] + 1;
        dfs(v);
    }
}

void solve()
{
    cin >> n;
    cin >> a >> b;
    for(int i = 1; i <= n; i ++) {
        cin >> k[i];
    }

    memset(dis, 0x3f, sizeof dis);
    dis[a] = 0;
    dfs(a);
    if(dis[b] == INF) dis[b] = -1;
    cout << dis[b];









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
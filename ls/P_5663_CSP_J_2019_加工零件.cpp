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

vector<vector<int>>adj(N);


int dis[N][2];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for(int i = 1;  i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dis, 0x3f, sizeof dis);

    priority_queue<PII,vector<PII>, greater<PII> >q;
    q.push({0, 1});
    dis[1][0] = 0; 

    while(q.size()) {
        auto [d, u] = q.top(); q.pop();
        int t = (d % 2) ^ 1;
        for(auto v : adj[u]) {
            if(dis[v][t] <= d + 1) continue;
            dis[v][t] = d + 1;
            q.push({dis[v][t], v});
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     cout << dis[i][0] << " " << dis[i][1] << endl;
    // }

    while(k --) {
        int x, l;
        cin >> x >> l;
        if(dis[x][l%2] <= l) cout << "Yes\n";
        else cout << "No\n";
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
    return 0;
}
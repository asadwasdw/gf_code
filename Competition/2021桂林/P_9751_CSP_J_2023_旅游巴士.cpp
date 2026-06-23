#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e4+10, M = 1e2 + 10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<PII>>edg(N);
int n,m,k;
int a[N];
int dis[N][M];
int st[N][M];

void solve()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= m ; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v,w});
    }

    priority_queue<PII,vector<PII>, greater<PII>> q;
    q.push({0, 1});
    memset(dis, 0x3f, sizeof dis);
    dis[1][0] = 0; 

    while(q.size()) {
        auto [d, u] = q.top(); q.pop();
        if(st[u][d % k]) continue;
        st[u][d % k] =  true; 

        for(auto [v, w] : edg[u]) {
            int t;
            if(d >= w) {
                t = d;
            }
            else {
                t = (w - d + k - 1) / k * k + d;
            }

            if(dis[v][(t + 1) % k] > t + 1) {
                dis[v][(t + 1) % k] = t + 1;
                q.push({t + 1, v});
            }
        }
    }

    // for(int i = 1; i <= n; i ++) cout << dis[i] << " \n"[i == n];
    
    if(dis[n][0] >= INF) {
        cout << "-1";
    }
    else cout << dis[n][0];

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
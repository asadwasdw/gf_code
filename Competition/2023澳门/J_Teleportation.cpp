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

vector<vector<PII>>adj(N);


void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(2 * n + 10, 0);
    vector<int> dis(2 * n + 10, INF);
    vector<int> st(2  * n + 10, 0);
    // dis[0] = 0;

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        adj[i].push_back({(i + a[i]) % n + n, 1});
        adj[i + n].push_back({(i + 1) % n + n, 1});
        adj[i + n].push_back({i, 0});
        a[i] = i ;
    }

    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0, 0});
    int cnt = 0;
    while(q.size()) {
        auto [d, u] = q.top(); q.pop();
   
        for(auto [v, w] : adj[u]) {
            // if(st[v]) continue;
            // if(u == 0 && v == 1) continue;
            if(d + w < dis[v]) {
                dis[v] = d + w;
                q.push({dis[v], v});
            }
        }
    }

    cout << dis[x] << endl;

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
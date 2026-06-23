#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

vector<vector<PII>>adj(N);

int t[N], x[N];

int id[N][2]; 
ll dis1[N], dis2[N];

void add(int u, int v, int w) {
    // cerr << u << " " << v << " " << w << endl;
    adj[u].push_back({v, w});
}

void solve()
{
    memset(id, -1, sizeof id);
    memset(dis1, 0x3f, sizeof dis1);
    memset(dis2, -1, sizeof dis2);

    int n, m; 
    cin >> n >> m;
    int cnt = 0;
    id[0][0] = cnt;
    for(int i = 1; i <= n; i ++){
        id[i][0] = ++ cnt, id[i][1] = ++ cnt;
    } 

    for(int i = 1; i <= m; i ++) {
        cin >> t[i] >> x[i];
        id[t[i]][x[i]] = -1;
    }

    for(int i = 0; i <= n; i ++) {
        for(int x = 0; x < 2; x ++) {
            if(id[i][x] == -1) continue;
            if(id[i + 1][x] != -1) add(id[i][x], id[i + 1][x], 0);
            if(id[i + 1][x ^ 1] != -1) add(id[i][x], id[i + 1][x ^ 1], 1);
        }
    }

    priority_queue<PII, vector<PII>, greater<PII> > pq1;
    pq1.push({0, 0});
    dis1[0] = 0;
    while(pq1.size()) {
        auto [d, u] = pq1.top(); pq1.pop();

        if(d > dis1[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(dis1[v] > dis1[u] + w) {
                dis1[v] = dis1[u] + w;
                pq1.push({dis1[v], v});
            }
        }
    }

    // for(int i = 1; i <= cnt; i ++) cout << i << " " << dis1[i] << endl; 

    priority_queue<PII> pq2;
    pq2.push({0, 0});
    dis2[0] = 0;
    while(pq2.size()) {
        auto [d, u] = pq2.top(); pq2.pop();
        if(d < dis2[u]) continue;
        // cerr << u << endl;
        for(auto [v, w] : adj[u]) {
            if(dis2[v] < dis2[u] + w) {
                // cerr << v << endl;
                dis2[v] = dis2[u] + w;
                pq2.push({dis2[v], v});
            }
        }
    }

    // for(int i = 1; i <= cnt; i ++) cout << i << " " << dis2[i] << endl; 
    // cout << n << " " << cnt << endl;
    // cout << dis1[cnt] << " " << dis2[cnt] << endl;

    int q;cin >> q;
    while(q --) {
        int x;
        cin >> x;
        if(x % 2 == 0) {
            if(dis1[cnt - 1] <= x && x <= dis2[cnt - 1]) cout << "Yes\n";
            else cout << "No\n";
        } else {
            if(dis1[cnt] <= x && x <= dis2[cnt]) cout << "Yes\n";
            else cout << "No\n";
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
    return 0;
}
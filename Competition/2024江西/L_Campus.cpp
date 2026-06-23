#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m,k;
int a[N];

vector<PII> g1[N], g2[N];
int d[16][N];
vector<PII> g[N];

void bfs(int st, int id){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    d[id][st] = 0;
    q.push({0, st});
    while(q.size()){
        auto [_, u] = q.top();q.pop();
        for(auto [v, w] : g[u]){
            if(d[id][v] > d[id][u] + w){
                d[id][v] = d[id][u] + w;
                q.push({d[id][v], v});
            }
        }
    }
}

void solve()
{
    int T;
    cin >> n >> m >> k >> T;
    for(int i=1; i<=n; ++i)cin >> a[i];
    for(int i=1; i<=k; ++i){
        int p,l,r;
        cin >> p >> l >> r;
        g1[l].push_back({p, i});
        g2[r+1].push_back({p, i});
    }
    memset(d, 0x3f, sizeof d);
    for(int i=1; i<=m; ++i){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    ll res = -1;
    int cnt = 0;
    for(int i=1; i<=T; ++i){
        bool f = false;
        for(auto [it, id] : g2[i]){
            --cnt;
            for(int j=1; j<=n; ++j)d[id][j] = INF;
            f = true;
        }
        for(auto [it, id] : g1[i]){
            bfs(it, id);
            ++cnt;
            f = true;
        }
        if(cnt == 0){
            cout << -1 << endl;
            continue;
        }
        if(f){
            res = 0;
            for(int j=1; j<=n; ++j){
                int mi = INF;
                for(int l=1; l<=k; ++l){
                    mi = min(d[l][j], mi);
                }
                res += 1ll * mi * a[j];
            }
        }
        cout << res << endl;
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
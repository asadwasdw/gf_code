#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<PII>>edg(N);
int n,m,k;
int dis[N];
bool st[N];
int c[N][N];
int ans = INF;

void solve()
{
    cin >> n >> m >> k;
    memset(c, 0x3f, sizeof c);
    bool ky = false;
    for(int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        edg[u].push_back({v, w});
        c[u][v] = min(c[u][v], w);
        ky |= (w <= k);
    }
    if(!ky) {
        cout << '0';
        return;
    }

    for(int i = 1; i <= n; i ++) {
        memset(dis, 0x3f, sizeof dis);
        dis[i] = 0;
        memset(st, 0, sizeof st);

        priority_queue<PII,vector<PII>, greater<PII>> q;
        q.push({0 ,i});
        while(q.size()) {
            auto [d, u] = q.top(); q.pop();
            if(st[u]) continue;
            st[u] = true;

            for(auto [v, w] : edg[u]) {
                int t = d + w;
                if(dis[v] > t) {
                    dis[v] = t;
                    q.push({t, v});
                }
            }
        }

        for(int j = 1; j <= n; j ++) {
            ans = min(ans, dis[j] + c[j][i]);
        }
        // cout << i << endl;
        // for(int j = 1; j <= n; j ++) cout << dis[j] << " \n"[j == n];
    }
    if(ans <= k) cout << '2';
    else cout << '1';
    







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
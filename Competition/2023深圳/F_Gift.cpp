#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);

int d[N], ish[N];
int n;

void init() {
    queue<int> q;
    for(int i = 1; i <= n; i ++) {
        if(ish[i] == 1) q.push(i);
    }

    while(q.size()) {
        int u = q.front(); q.pop();
        ish[u] --;
        for(auto v : adj[u]) {
            if(ish[v] == 0) continue;
            ish[v] --;
            if(ish[v] == 1) q.push(v);
        }
    }
}


int dfs(int x, int fa) {
    int res = 0;
    if(d[x] < 4) res ++;

    for(auto v : adj[x]) {
        if(v == fa) continue;
        if(ish[v]) continue;
        res += dfs(v, x);
    }
    return res;
}

void solve()
{
    vector<PII> edg;
    cin >> n;
    for(int i = 1; i <= n; i ++ ) {
        int a, b; cin >> a >> b;
        d[a] ++, d[b] ++;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edg.push_back({a, b});
    }
    int d5 = 0, d4 = 0;
    for(int i = 1; i <= n; i ++) {
        ish[i] = d[i];
        if(d[i] == 5) d5 ++;
        if(d[i] == 4) d4 ++;
    }

    init();
    // for(int i = 1; i <= n; i ++) {
    //     cout << ish[i] << " \n"[i == n];
    // }

    // cout << d4 << " " << d5 << endl;

    ll ans = 0;

    for(auto [a, b] : edg) {
        if(ish[a] && ish[b]) {
            if(d5 == 0) {
                int t = 0;
                if(d[a] == 4) t ++;
                if(d[b] == 4) t ++;
                ans += (n - d4) + t;
            }
            else if(d5 == 1) {
                if(d[a] == 5 || d[b] == 5) {
                    d[a] --, d[b] --;
                    for(int i = 1; i <= n; i ++) {
                        if(d[i] < 4) ans ++;
                    }
                    d[a] ++, d[b] ++;
                }
            }
            else if(d5 == 2) {
                if(d[a] == 5 && d[b] == 5) {
                    d[a] --, d[b] --;
                    for(int i = 1; i <= n; i ++) {
                        if(d[i] < 4) ans ++;
                    }
                    d[a] ++, d[b] ++;
                }
            }
        }
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
}
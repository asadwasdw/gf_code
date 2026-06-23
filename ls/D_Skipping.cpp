#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<PII>>adj(N);
ll a[N], b[N], s[N];

void solve()
{
    int n; cin >> n; 
    for(int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for(int j = 1; j <= n; j ++) cin >> b[j];

    vector<ll> dp(n + 1, INFll);
    dp[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push({a[1], b[1]});
    
    for(int j = 2; j <= n; j ++) {
        while(q.size() && q.top().second < j) q.pop();
        if(!q.size()) break;
        dp[j] = q.top().first;
        if(b[j] > j) q.push({dp[j] + a[j], b[j]});
    }
    ll ans = 0;
    for(int i = 1; i <= n; i ++) ans = max(ans, s[i] - dp[i]);
    cout << ans << endl;
}


void solve2()
{
    int n; cin >> n; 
    for(int i = 1; i <= n; i ++) adj[i].clear();
    for(int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for(int j = 1; j <= n; j ++) cin >> b[j];

    vector<ll> dis(n + 1, INFll);
    dis[1] = 0;
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push({0, 1});
    
    for(int i = 1; i <= n; i ++) {
        if(b[i] > i) adj[i].push_back({b[i], a[i]});
        if(i != 1)   adj[i].push_back({i - 1, 0});
    }

    while(q.size()) {
        auto [W , u] = q.top(); q.pop();
        if(W > dis[u]) continue;
        for(auto [v, w] : adj[u]) {
            if(W + w < dis[v]) {
                dis[v] = W + w;
                q.push({dis[v], v});
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i ++) ans = max(ans, s[i] - dis[i]);
    cout << ans << endl;
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
        solve2();
    }
}
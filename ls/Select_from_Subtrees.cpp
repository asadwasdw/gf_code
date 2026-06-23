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

vector<vector<int>>adj(N);


ll qmi(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll inf[N], fac[N];

void init() {
    fac[0] = 1;
    for(int i = 1; i < N; i ++) {
        fac[i] = fac[i - 1] * i % mod;
    }

    inf[N - 1] = qmi(fac[N - 1], mod - 2);

    for(int i = N - 2; i >= 0; i --) {
        inf[i] = inf[i + 1] * (i + 1) % mod;
    }
}

ll C(ll a, ll b) {
    if(a < 0 || b < 0) return 0;
    if(a < b) return 0;
    // return fac[a] * inf[b] % mod * inf[a - b] % mod;

    ll res = 1;
    for(ll i = a; i > a - b; i --) res = res * (i % mod) % mod;
    res = res * inf[b] % mod;
    return res;
}

ll sumc[N], sumd[N];
ll c[N], d[N];
ll ans = 1;
void dfs(int u) {
    sumc[u] += c[u];
    
    for(auto v : adj[u]) {
        dfs(v);

        sumc[u] += sumc[v];
        sumd[u] += sumd[v];
    }

    ans = (ans * C(sumc[u] - sumd[u], d[u])) % mod;
    sumd[u] += d[u];
}

void solve()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i ++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int j = 1; j <= n; j ++) cin >> d[j];

    dfs(1);
    cout << ans;
}


signed main()
{   init();
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
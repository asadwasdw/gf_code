#include<bits/stdc++.h>
#define int long long
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 2e5 + 10, mod = 998244353;
typedef pair<int, int> PII;

int n,k;
vector<int> g[N];
int sz[N];
ll f[N][5], temp[5];
// void dfs2(int u, int fa){
//     sz[u] = 1;
//     for(auto v : g[u])if(v != fa)dfs2(v, u), sz[u] += sz[v];
// }
void dfs(int u, int fa){
    int st = 0;
    sz[u] = 0;
    for(auto v : g[u]){
        if(v == fa)continue;
        dfs(v, u);
        if(!st){
            st = 1;
            for(int i=1; i<=3; ++i)f[u][i] = f[v][i];
            f[u][0] = f[u][4] = 0;
            sz[u] += sz[v];
            continue;
        }
        for(int i=0; i<5; ++i)temp[i] = 0;
        for(int i=-2; i<=2; ++i)for(int j=-1; j<=1; ++j){
            if(i+j >= -2 && i+j <= 2)
            (temp[i+j+2] += f[u][i+2] * f[v][j+2] % mod) %= mod;
        }
        for(int i=0; i<5; ++i)f[u][i] = temp[i];
        sz[u] += sz[v];
    }
    sz[u]++;
    if(sz[u] == 1){
        f[u][1] = f[u][3] = 1;
        f[u][0] = f[u][2] = f[u][4] = 0;
        // cout << u << ' ' << f[u][1] << ' ' << f[u][2] << ' ' << f[u][3] << endl;
        return;
    }
    if(sz[u] & 1){
        temp[1] = f[u][0] + f[u][2];
        temp[3] = f[u][4] + f[u][2];
        f[u][0] = f[u][2] = f[u][4] = 0;
        f[u][1] = temp[1] % mod;
        f[u][3] = temp[3] % mod;
    }
    else{
        f[u][2] = (f[u][1] + f[u][3]) % mod;
        f[u][0] = f[u][1] = f[u][3] = f[u][4] = 0;
    }
    // cout << u << ' ' << f[u][1] << ' ' << f[u][2] << ' ' << f[u][3] << endl;
}

ll qmi(ll n, ll m){
    ll res = 1ll;   
    n %= mod;
    while(m){
        if(m & 1)res = res * n % mod;
        n = n * n % mod;
        m >>= 1ll;
    }
    return res;
}

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i)g[i].clear();
    for(int i=2; i<=n; ++i){
        int x;cin >> x;
        g[x].push_back(i);
    }
    // dfs2(1, 0);
    // for(int i=1; i<=n; ++i)sort(g[i].begin(), g[i].end(), [&](int a, int b){
    //     return sz[a] % 2 < sz[b] % 2;
    // });
    dfs(1, 0);
    ll ans = 0;
    if(sz[1] & 1){
        ans = f[1][1] + f[1][3];
    }
    else ans = f[1][2];
    // cout << ans << endl;
    cout << qmi(ans, k) << endl;

}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
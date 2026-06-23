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

//vector<vector<int>>adj(N);

int f[N];
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];  
}

PII e[N];

ll qmi(ll a, ll b, ll c) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
} 

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        f[i] = i;
    } 

    for(int i = 1; i <= m; i ++) {
        cin >> e[i].first >> e[i].second;
    }
    ll ans = 0;
    for(int i = m; i >= 1; i --) {
        auto [u, v] = e[i];
        u = find(u), v = find(v);
        if(n != 2) {
            if(u != v) {
                n --;
                f[u] = v;
            }
        } else {
            if(u != v) {
                ans = (ans + qmi(2, i, mod)) % mod;
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
    return 0;
}
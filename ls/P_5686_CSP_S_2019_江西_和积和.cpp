#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9 + 7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

ll a[N], b[N];

ll sa[N], sb[N];
ll ssa[N], ssb[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sa[i] = sa[i - 1] + a[i];
        ssa[i] = ssa[i - 1] + sa[i];
        sa[i] %= mod;
        ssa[i] %= mod;
    }

    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
        sb[i] = sb[i - 1] + b[i]; 
        ssb[i] = ssb[i - 1] + sb[i]; 
        sb[i] %= mod;
        ssb[i] %= mod;
    }

    ll ans = 0;

    // for(int i = 1; i <= n; i ++) {
    //     for(int len = 1; len <= i; len ++) {
    //         ans += (sa[i] - sa[i - len]) * (sb[i] - sb[i - len]) % mod;
    //     }
    // }

    // for(int l = 1; l <= n; l ++) {
    //     for(int r = l; r <= n; r ++) {
    //         ans += (sa[r] - sa[l - 1]) * (sb[r] - sb[l - 1]);
    //     }
    // }

    for(int i = 1; i <= n; i ++) {
        ans += sa[i] * sb[i] % mod * i % mod;
        ans += sa[i - 1] * sb[i - 1] % mod * (n - i + 1) % mod;
        
        ans -= sb[i - 1] * (ssa[n] - ssa[i - 1]) % mod;
        ans -= sa[i - 1] * (ssb[n] - ssb[i - 1]) % mod;

        ans = (ans % mod + mod) % mod;
    }


    cout << ans % mod << endl;







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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=4e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
ll fac[N], invfac[N];
void solve()
{
    ll n;cin >> n;
    string s;cin >> s;
    ll a = 0, x = 1;
    string t = "xtu";
    int m = s.size();
    vector<int> A(m, -1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            if (s[i] == t[j]) {
                A[i] = j;
                break;
            }
        }
        if (A[i] == -1) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 1; i < m; i++) {
        if (A[i] > A[i - 1]) a++;
        else x++;
    }

    vector<ll> vala(a + 1), valb(a + 1);
    vala[0] = 1;
    valb[0] = 1;
    for (ll i = n; i >= n - x + 1; i--) {
        valb[0] = valb[0] * (i % mod) % mod;
    }
    for (ll i = 1; i <= a; i++) {
        vala[i] = vala[i - 1] * (a - i + 1) % mod;
        valb[i] = valb[i - 1] * ((n - x - i + 1) % mod) % mod;
        if (n - x - i + 1 < 0) valb[i] = 0;
    }
    // for (int i = 0; i <= a; i++) {
    //     cout << vala[i] << ' ' << valb[i] << '\n';
    // }
    ll ans = 0;
    for (int i = 0; i <= a; i++) {
        ans = (ans + vala[i] * valb[i] % mod * invfac[i] % mod * invfac[x + i] % mod) % mod;
        // cout << x + i << ' ';
        // cout << vala[i] << ' ' << valb[i] << ' ' << invfac[i] << ' ' << invfac[x + i] << '\n'; 
    }

    cout << ans << '\n';

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * i % mod;
    invfac[N - 1] = qpow(fac[N - 1], mod - 2);
    
    for (int i = N - 2; i >= 0; i--) {
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
        
    }
    // invfac[0] = 1;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
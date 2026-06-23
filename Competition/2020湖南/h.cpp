#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e6+10, mod = 1e9+7;

ll qmi(ll n, ll m){
    ll res = 1ll;
    while(m){
        if(m & 1)res = res * n % mod;
        n = n * n % mod;
        m >>= 1ll;
    }
    return res;
}

void solve(){
    ll a,b,a2,b2,x2,y2;
    ll inv2 = qmi(2ll, mod-2);
    auto get = [&](ll x, ll y, ll a){
        if(x > y)return 0ll;
        return (((x + y) % mod * (y - x + 1) % mod * inv2 % mod - (y - x + 1) % mod * a % mod) + mod) % mod;
    };
    while(cin >> x2 >> y2){
        cin >> a >> a2 >> b >> b2;
        ll res1 = get(a+1, min(a2, x2), a) * get(b+1, min(b2, y2), b) % mod;
        ll res2 = get(a+1, min(a2, x2), a) * (b2 - b) % mod * max(0ll, y2 - b2) % mod;
        ll res3 = get(b+1, min(b2, y2), b) * (a2 - a) % mod * max(0ll, x2 - a2) % mod;
        ll res4 = (a2 - a) * (b2 - b) % mod * max(0ll, x2-a2) % mod * max(0ll, y2-b2) % mod;
        // cout << res1 << ' ' << res2 << ' '<< res3 << ' ' << res4 << endl;
        ll ans = x2 * y2 % mod * (a2 - a) % mod * (b2 - b) % mod;
        ans = (ans + (x2 + 1) * x2 / 2 % mod * ((y2 + 1) * y2 / 2 % mod) % mod) % mod;
        cout << (ans - (res1 + res2 + res3 + res4) % mod + mod) % mod << endl;
    }


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}
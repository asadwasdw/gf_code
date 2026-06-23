#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 2e6 + 10, mod = 1e9+7;

ll n,k;
ll t[N], l[N], w[N];

void solve(){
    cin >> n >> k;
    for(int i=1; i<=n; ++i)cin >> t[i] >> l[i] >> w[i];
    auto check = [&](ll mid){
        __int128_t res = 0;
        for(int i=1; i<=n; ++i){
            ll cnt = mid / (t[i] * l[i] + w[i]);
            res += (__int128_t)cnt * l[i];
            if(res > 2e18)return true;
            ll yu = mid % (t[i] * l[i] + w[i]);
            res += min(yu / t[i], l[i]);    
        }
        return res >= k;
    };
    ll l = 1, r = 2e18;
    while(l < r){
        ll mid = l + r >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    cout << l << endl;


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)solve();
    return 0;
}
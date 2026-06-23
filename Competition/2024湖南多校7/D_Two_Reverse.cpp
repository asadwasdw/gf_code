#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
// #define int long long
constexpr int N = 1e6 + 50, LOGN = 30;
constexpr ll mod = 1e9 + 7, inf = 1e9;

const int B = 60;
struct linear_basic {
    vector<ll> num;
    linear_basic() {num.resize(B + 1);}
    linear_basic(int n) {num.resize(n);}
    bool insert(ll x) {
        for (int i = B - 1; i >= 0; i--) {
            if (x & (1ll << i)) {
                if (num[i] == 0) {num[i] = x; return true; }
                x ^= num[i];
            }
        }
        return false;
    }
    ll querymin(ll x) {
        for (int i = B - 1; i >= 0; i--) {
            x = min(x, x ^ num[i]);
        }
        return x;
    }
    ll querymax(ll x) {
        for (int i = B - 1; i >= 0; i--) {
            x = max(x, x ^ num[i]);
        }
        return x;
    }
} lb;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    ll bit = 0, res = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i], bit ^= a[i] ^ b[i];

    for (int i = 0; i < n; i++) {
    	a[i] -= a[i] & bit;
    	b[i] -= b[i] & bit;
    	res ^= a[i];
    	lb.insert(a[i] ^ b[i]);
    }
    res = lb.querymax(res);

    cout << res + (bit ^ res) << '\n';

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

typedef long long ll;

ll num(ll x) {
    ll ans = 0;
    while (x) {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve() {

    ll n, s; cin >> n >> s;
    ll t = n;
    while (1)
    {
        if (num(t) <= s) {
            break;
        }
        else {
            for (ll wz = 1;; wz++) {
                if (t % (ll)pow((ll)10, wz) != 0) {
                   // cout << t << endl;
                    ll z = t % (ll)pow((ll)10, wz);
                    ll a = pow((ll)10, wz);
                    t +=a - z;
                    break;
                }
            }
        }
    }
    cout << t-n << endl;

}


int main()
{
    int t; cin >> t; while (t--) {
        solve();
    }
}
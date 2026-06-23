#include<bits/stdc++.h>
using namespace std;


void solve() {
    int d, f;
    cin >> d >> f;
    int ans = ((d - f + 6) / 7 * 7 + f) % d;
    if(ans == 0) ans += 7;

    cout << ans << endl;

}

int main() {

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
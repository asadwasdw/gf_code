#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int INF = 0x3f3f3f3f;
using i64 = long long;




void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << "100" << endl;
    for(int i = 1; i <= 50; i ++) cout << x << " ";
    for(int i = 1; i <= 45; i ++) cout << y << " ";
    for(int i = 1; i <= 4; i ++) cout << z << " ";
    cout << z + 1 << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}
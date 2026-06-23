#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
using i64 = long long;
const int mod = 1e9 + 7;
#define endl "\n"



void solve() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    if(k) {
        s = " " + s + s.substr(0,min((int)s.size(), k));
    } else {
        s = " " + s;
    }
    
    vector<int> a(2 * n + 100, 0);

    int ans = 0;
    for(int i = 1; i < s.size(); i ++) {
        if(s.substr(i, 7) == "nanjing") a[i + 6] += 1;
        a[i + 6] += a[i - 1 + 6]; 
        ans = max(ans, a[i + 6] - a[max(0, i - n + 6 + 6)]);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t --) {
        solve();
    }
}
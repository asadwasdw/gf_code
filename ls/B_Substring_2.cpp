#include<bits/stdc++.h>
using namespace std;


void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ans = 0x3f3f3f3f;
    for(int i = 0; i + t.size() - 1 < s.size(); i ++) {
        string ss = s.substr(i, t.size());
        int res = 0;

        for(int j = 0; j < t.size(); j ++) {
            if(ss[j] == '0') ss[j] += 10;
            if(ss[j] >= t[j]) res += (ss[j] - t[j]) % 10;
            else {
                res += (10 - (t[j] - ss[j])) % 10;
            }
        }

        ans = min(ans, res);
    }

    cout << ans;


}

int main() {

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
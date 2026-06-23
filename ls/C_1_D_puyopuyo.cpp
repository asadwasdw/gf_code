#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

void solve() {
    int n;
    cin >> n;
    stack<PII> s;

    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        if(s.size() && s.top().first == x) {
            PII t = s.top(); s.pop();
            t.second ++;
            if(t.second < 4) s.push(t);
        } else {
            PII t = {x, 1};
            s.push(t);
        }
    }

    int ans = 0;
    while(s.size()) {
        ans += s.top().second;
        s.pop();
    }
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
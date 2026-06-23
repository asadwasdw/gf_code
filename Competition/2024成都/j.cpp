#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
const ll INF = 0x3f3f3f3f;
using i64 = long long;
typedef pair<ll,ll> PII;

void solve() {
    int n,m,q;
    cin >> n >> m >> q;
    ll fs = m;
    vector<ll> ans(m + 1, 0ll);
    unordered_map<int,bool> st;
    int now = 0;

    for(int i = 1; i <= q; i ++) {
        int op,id,x;
        cin >> op >> id;
        if(op == 1) {
            now = id;
            st.clear();
            fs = m;
            continue;
        }
        cin >> x; 
        if(x != now) continue;
        if(st[id]) continue;
        st[id] = true;
        
        if(op == 2) {
            ans[id] += fs;
            fs --; 
        }

    }

    vector<PII> v;
    for(int i = 1; i <= m; i ++) {
        v.push_back({i, ans[i]});
    }
    sort(v.begin(), v.end(),[&](PII a, PII b) {
        if(a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    for(auto [x, y] : v) cout << x << " " << y << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}
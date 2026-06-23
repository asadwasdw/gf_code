#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using i64 = long long;
typedef pair<int,int> PII;
const int N = 5e5 + 10, M = N;

int a[N],c[N];
vector<pair<int, int>> g[N];

int tr[N];

void add(int x, int c){
    while(x < N){
        tr[x] += c;
        x += x&-x;
    }
}

int query(int x){
    int res = 0;
    while(x > 0){
        res += tr[x];
        x -= x&-x;
    }
    return res;
}
vector<int> task[N];
void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> a[i];
    for(int i=1; i<=n; ++i)cin >> c[i];
    for(int i=1; i<=m; ++i){
        int l,r;
        cin >> l >> r;
        g[r].push_back({l, i});
    }
    vector<int> res(m+1);
    for(int i=1; i<=n; ++i){
        if(a[i]){
            if(task[c[i]].size())add(task[c[i]].back(), 1), task[c[i]].pop_back();
        }
        else{
            task[c[i]].push_back(i);
        }
        for(auto [l, id] : g[i]){
            res[id] = query(i) - query(l-1);
        }
    }
    for(int i=1; i<=m; ++i)cout << res[i] << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
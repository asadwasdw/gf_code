#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
using i64 = long long;
const int mod = 1e9 + 7;
#define endl "\n"

int n,m,k,w;
int a[N], b[N];
void solve() {
    cin >> n >> m >> k >> w;
    for(int i=1; i<=n; ++i)cin >> a[i];
    for(int i=1; i<=m; ++i)cin >> b[i];
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    int u = 1;
    vector<ll> res;
    b[m+1] = w + 1;
    for(int i=1; i<=m+1; ++i){
        u = upper_bound(a+1, a+1+n, b[i-1]) - a;
        if(u > n || a[u] >= b[i])continue;
        vector<pair<ll, ll>> p;
        while(u <= n){
            ll nx = a[u] + k;
            p.push_back({a[u], nx - 1});
            auto it = lower_bound(a+1, a+1+n, nx) - a;
            if(nx - 1 >= b[i]){
                ll cha = nx - 1 - b[i] + 1;
                p.back().first -= cha;
                p.back().second -= cha;
                for(int i=(int)p.size()-2; i>=0; --i){
                    if(p[i].second >= p[i+1].first){
                        cha = p[i].second - p[i+1].first + 1;
                        p[i].first -= cha;
                        p[i].second -= cha;
                    }
                }
                if(p[0].first <= b[i-1]){
                    cout << -1 << endl;return;
                }
                break;
            }
            
            if(it == n+1 || a[it] >= b[i]){
                break;
            }
            else{
                u = it;
            }
        }
        for(auto [x, y] : p)res.push_back(x);
    }
    cout << res.size() << endl;
    for(int i=0; i<res.size(); ++i)cout << res[i] << " \n"[i == (int)res.size()-1];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1; 
    cin >> t;
    while(t --) {
        solve();
    }
}
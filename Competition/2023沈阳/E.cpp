#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int x, y, p, q; cin >> x >> y >> p >> q;
    constexpr int inf = 1e9;
    vector dis(x + 1, vector (y + 1, vector<int> (2, inf)));
    dis[x][y][0] = 0;
    priority_queue<array<int, 4>, vector<array<int, 4>>, greater<array<int, 4>>> que;
    que.push({0, x, y, 0});
    while (!que.empty()) {
        auto [v, a, b, op] = que.top(); que.pop();
        for (int l = 0; l <= min(a, p); l++)
        for (int r = 0; l + r <= p && r <= b; r++) {
            if (a - l != 0 && a - l + q < b - r) continue;
            int na = x - (a - l), nb = y - (b - r);
            if (dis[na][nb][op ^ 1] > v + 1) {
                dis[na][nb][op ^ 1] = v + 1;
                que.push({v + 1, na, nb, op ^ 1});
            }
        }
    }
    int ans = inf;
    for (int i = 0; i <= y; i++) ans = min(ans, dis[x][i][1]);
    if (ans == inf) ans = -1;
    cout << ans << "\n";





}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
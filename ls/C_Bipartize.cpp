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
    int n, m;
    cin >> n >> m;
    vector<PII> edg;
    for(int i = 1; i <= m; i ++) {
        int x, y;
        x --, y --;
        cin >> x >> y;
        edg.push_back({x, y});
    }
    int ans = INF;

    for(int t = 0; t < (1 << n); t ++) {
        int cnt = 0;
        for(auto [u, v] : edg) {
            if( ((t >> u) & 1) == ((t >> v) & 1)) {
                cnt ++;
            }
        }
        // cout << t << " " << cnt << endl;
        ans = min(ans, cnt);
    }

    cout << ans << endl;
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
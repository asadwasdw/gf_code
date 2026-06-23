#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

struct work {
    int l, r, w, v;
};
const int N=1e3+10;
int dp[N][N];

void solve()
{
    int n, m, R;
    cin >> n >> m >> R;
    vector<work> s;
    for(int i = 0; i < m; i ++) {
        int l, t, w, v;
        cin >> l >> t >> w >> v;
        s.push_back({l, l + t, w, v});
    }

    sort(s.begin(), s.end(), [&](work a, work b){
        return a.l < b.l;
    });

    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 0; i < m; i ++) {
        int l = s[i].l, r = s[i].r, v = s[i].v, w = s[i].w;
        for(int j = s[i].v; j <= R; j ++) {
            dp[r][j] = max(dp[l][j - s[i].v] + w, dp[r][j]);
            // cout << l << " " << j - s[i].v << " " << w << endl;
        }
    }
    int ans = 0;
    for(int i = 0; i <= R; i ++) {
        ans = max(ans, dp[n][i]);
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
    return 0;
}
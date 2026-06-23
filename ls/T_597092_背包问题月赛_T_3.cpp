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
const int N=1e6+10;
int dp[N];

void solve()
{
    int n, m, R;
    cin >> n >> m >> R;
    vector<work> s;
    for(int i = 0; i < m; i ++) {
        int l, r, w, v = 0;
        cin >> l >> r >> w;
        s.push_back({l, r, w, v});
    }

    sort(s.begin(), s.end(), [&](work a, work b){
        return a.l < b.l;
    });
    
    int ans = 0, now = 0, res = 0;
    for(int i = 0; i < m; i ++) {
        int l = s[i].l, r = s[i].r, w = s[i].w;
        for(; now + R < l; now ++) {
            res = max(res, dp[now]);
        } 
        dp[r] = max(dp[r], res + w);
        // cout << res << " " << now << endl;
        ans = max(ans, dp[r]);
    }

    // for(int i = 0; i <= n; i ++) {
    //     cout << dp[i] << " \n"[i == n];
    // }
    cout << ans;
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
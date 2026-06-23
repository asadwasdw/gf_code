#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

ll a[N], s[N];

void solve()
{
    int n, k, x; cin >> n >> k >> x;
    a[0] = - INF;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    vector<map<int,int>> dp(n + 1);
    dp[0][0] = 0; // 已经打包了前i个物品， 现在时间是j， 可以继续打包的最小代价

    for(int i = 0; i < n; i ++) {
        for(auto [now, val] : dp[i]) {
            for(int j = 1; j <= k && i + j <= n; j ++) { 
                int t = max(now, a[i + j]); // 发货时间
                int w = t * j - (s[i + j] - s[i]);

                if(dp[i + j].count(t + x)) {
                    dp[i + j][t + x] = min(dp[i + j][t + x], val + w); 
                } else {
                    dp[i + j][t + x] = val + w;
                }
            }
        }
    }

    int ans = INFll;
    for(auto [x, y] : dp[n]) {

        ans = min(y, ans);
    }
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
}
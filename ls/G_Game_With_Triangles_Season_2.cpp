#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);



void solve()
{
    int n; cin >> n;
    vector a(2 * n + 1, 0ll);
    vector dp(2 * n + 1, vector(2 * n + 1, 0ll));
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    ll ans = 0;
    for(int len = 3; len <= n; len ++) {
        for(int l = 1; l <= n; l ++) {
            int r = l + len - 1;
            dp[l][r] = max({dp[l + 1][r], dp[l][r], dp[l + 1][r - 1]});
            for(int k = l + 1; k < r; k ++) {
                dp[l][r] = max(dp[l][r], dp[l + 1][k - 1] + dp[k + 1][r - 1] + a[l] * a[k] * a[r]);
                dp[l][r] = max({dp[l][r], dp[l][k] + dp[k + 1][r], dp[l][k - 1] + dp[k][r]});
            }
            if(len == n) ans = max(dp[l][r], ans);
        }
    }
    cout << ans << endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
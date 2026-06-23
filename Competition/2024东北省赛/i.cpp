#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

using i64 = long long;
void solve()
{
    int n, k; cin >> n >> k;
    vector<i64> fac(k + 1);
    fac[0] = 1;
    for (int i = 1; i <= k; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
    if (n < k) {
        cout << 0 << '\n';
        return;
    }
    vector<i64> dp(n + 1);
    dp[k] = fac[k];
    for (int i = k + 1; i <= n; i++) {
        dp[i] = dp[i - k] * fac[k - 1] % mod;
        for (int j = 1; j < k; j++) {
            dp[i] = (dp[i] + dp[i - j] * fac[j] % mod) % mod;
        }
    }
    cout << dp[n] << '\n';




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
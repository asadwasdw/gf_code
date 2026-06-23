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

using i64 = long long;
constexpr i64 P = 1e9 + 9;
void solve()
{
    int m, k; cin >> m >> k;
    vector<i64> f(k + 1), dp(k + 1), cnt(k + 1);
    cnt[0] = 1;
    auto qpow = [&](i64 a, i64 b) -> i64 {
        i64 res = 1;
        while (b) {
            if (b & 1) res = res * a % P;
            b >>= 1;
            a = a * a % P;
        }
        return res;
    };
    for (int i = 1; i <= k; i++) {
        cnt[i] = cnt[i - 1] + m - 1;
        dp[i] = (dp[i - 1] * cnt[i] % P + m) % P * qpow(cnt[i], P - 2) % P;
        f[i] = (f[i - 1] - dp[i - 1] * (cnt[i - 1] - 1) % P + dp[i] * cnt[i] % P + P) % P;
    }

    cout << f[k] << "\n";
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
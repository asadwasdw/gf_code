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
    int a, b, m;
    cin >> a >> b >> m;
    vector<ll> dp(m + 1, 0);
    dp[0] = 2;
    ll ans = 2, t = (b + a - 1)/a*a; // 刷新技能等着洗钱技能好
    // cerr << t << endl;
    for(int i = 0; i <= m; i ++) {
        if(i + t <= m) dp[i + t] = max(dp[i + t], dp[i] + 1 + t/a);
        if(i + b <= m) dp[i + b] = max(dp[i + b], dp[i] + 1 + b/a); // 刷新技能好了就用
        ans = max(ans, dp[i] + (m - i)/a); // 剩下的时间只洗钱
        // cout << dp[i] << endl;
    }
    cout << ans * 160 << endl;
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
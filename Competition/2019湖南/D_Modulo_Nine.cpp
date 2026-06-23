#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=1e9+7;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    int n, m;
    while(cin >> n >> m) {

    vector dp(n + 1, vector(n + 1, vector(n + 1, 0ll)));
    vector L(n + 1, 0);

    for(int i = 1; i <= m; i ++) {
        int l, r; cin >> l >> r;
        L[r] = max(L[r], l);
    }

    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < i; j ++) {
            for(int k = j; k < i; k ++) {
                dp[i][i][i] += dp[i - 1][j][k] * 2;
                if(j >= L[i]) dp[i][j][k] += dp[i - 1][j][k] * 6;
                if(k >= L[i]) dp[i][k][i] += dp[i - 1][j][k] * 2;

                dp[i][i][i] %= mod;
                dp[i][j][k] %= mod;
                dp[i][k][i] %= mod;
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i <= n; i ++) {
        for(int j = 0; j <= n; j ++) {
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans << endl;

    }









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
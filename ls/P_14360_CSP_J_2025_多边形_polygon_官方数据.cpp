#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N];
int dp[3][5010][5010];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    ll ans = 0;
    dp[0][0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = a[i] + 1; j <= 5001; j ++) {
            ans += dp[2][i - 1][j];
            ans %= mod;
        }

        for(int j = 0; j < 3; j ++) {
            for(int k = 0; k <= 5001; k ++) {
                dp[j][i][k] = (1ll * dp[j][i][k] + dp[j][i - 1][k]) % mod;
                dp[min(2, j + 1)][i][min(5001, k + a[i])] =  (1ll *dp[min(2, j + 1)][i][min(5001, k + a[i])] + dp[j][i - 1][k]) % mod;
            }
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
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
    return 0;
}
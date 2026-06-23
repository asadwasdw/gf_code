#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
int dp[N][15];

int gfmin(int l, int r) {
    int ans =  INF;
    for(int i = l; i <= r; i ++ ) ans = min(ans, a[i]);
    return ans * (r - l + 1);
}

void solve()
{
    int k;
    cin >> n >> k;
    a[n + 1] = INFll;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    // memset(dp, 0x3f, sizeof dp);

    for(int i = 1; i <= k; i ++) dp[0][i] = INFll;
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= k; j ++) {
            dp[i][j] = dp[i - 1][j] + a[i];
            for(int len = 2; len <= j + 1; len ++) {
                int l = i - len + 1;
                if(l >= 1)dp[i][j] = min(dp[i][j], dp[l - 1][j - len + 1] + gfmin(l,i));

                // cout << i << " " << j << " " << len << " " << l <<  endl;
            }

            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 0; j <= k; j ++) cout << i << " " << j << " " << dp[i][j] << endl;
    // }
    int ans = INFll;
    for(int i = 0; i <= k; i ++) {
        ans = min(dp[n][i], ans);
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
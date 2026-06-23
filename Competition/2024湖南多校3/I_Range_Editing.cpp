#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10,M=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int dp[M][M];
int a[M];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1;i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = dp[n+1][n+1] = 0;

    for(int len = 1; len <= n + 2; len ++) {
        for(int l = 0; l <= n + 1; l ++) {
            int r = l + len - 1;

            if(l == r) {
                dp[l][r] = 1;
                continue;
            } 
            if(r > n+1) continue;

            for(int k = l; k < r; k ++) {
                if(a[l]==a[r]) {
                    dp[l][r] = min(dp[l][r],dp[l][k] + dp[k+1][r] - 1);
                }
                else {
                    dp[l][r] = min(dp[l][r],dp[l][k] + dp[k+1][r]);
                }
            }
        }
    }

    cout << dp[0][n + 1] - 1 << endl;
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
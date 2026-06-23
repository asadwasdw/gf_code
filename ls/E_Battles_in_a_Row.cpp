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

int dp[3010][3010];

void solve()
{
    int n, h, w;
    cin >> n >> h >> w;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;
        

        for(int j = h; j >= 0; j --) {
            dp[i][j] = min(dp[i - 1][j] + b, dp[i][j]);
            if(j >= a) dp[i][j] = min(dp[i][j], dp[i - 1][j - a]);
        }
    }


    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= h; j ++) {
    //         cout << dp[i][j] << " \n"[j == h];
    //     }
    // }

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= h; j ++) {
            if(dp[i][j] <= w) ans = i;
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
}
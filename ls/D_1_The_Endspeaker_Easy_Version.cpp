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

int a[N], b[N], c[N], s[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
    dp[0][0] = 0;

    for(int i = 1; i <= m; i ++ ){
        for(int j = 1; j <= n;j ++) {
            dp[i][j] = dp[i - 1][j];
            for(int k = 1; k < j; k ++) {
                if(s[j] - s[k] <= b[i]) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + m - i);
                }
            }
        }
    }
    cout << dp[m][n] << endl;

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
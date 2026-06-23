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


int dp[20][20];
int a[20][20];
int pre[20][20];
int ans[N];

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            for(int k = 0; k <= j; k ++) {
                if(dp[i][j] <= dp[i - 1][j - k] + a[i][k]) {
                    dp[i][j] = dp[i - 1][j - k] + a[i][k];
                    pre[i][j] = j - k;
                }
            }

            // cout << dp[i][j] << " \n"[j == m];
        }
    }

    cout << dp[n][m] << endl;

    for(int i = n; i >= 1; i --) {
        ans[i] = m - pre[i][m];
        m -= ans[i];
    }

    for(int i = 1; i <= n; i ++) cout << i << " " << ans[i] << "\n"; 

    





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
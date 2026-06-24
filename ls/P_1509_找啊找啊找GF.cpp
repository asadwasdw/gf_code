#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e2+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int dp[N][N][N];

int rmb[N], rp[N], tim[N];

void solve()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> rmb[i] >> rp[i] >> tim[i];
    }
    int m, r;
    cin >> m >> r;

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;

    for(int i = 1; i <= n; i ++) {
        for(int j = i; j >= 1; j --) {
            for(int k = m; k >= rmb[i]; k --) {
                for(int z = r; z >= rp[i]; z --) {
                    dp[j][k][z] = min(dp[j][k][z], dp[j - 1][k - rmb[i]][z - rp[i]] + tim[i]);

                }
            }
        }
    }
    int cnt = 0, ans = INF;
    for(int j = 0; j <= n; j ++) {
        for(int k = 0; k <= m; k ++) {
            for(int z = 0; z <= r; z ++) {
                // cout << j << " " << k << " " << z << " " << dp[j][k][z] << endl;
                if(dp[j][k][z] != INF) {
                    if(j > cnt) {
                        cnt = j;
                        ans = dp[j][k][z];
                    } else if(j == cnt) {
                        ans = min(ans, dp[j][k][z]);
                    }
                }
            }
        }
    }
    // cout << cnt << " ";
    cout << ans;







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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N][N], s[N][N];
int dp[N][N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            char t; cin >> t;
            if(t == '#') a[i][j] = 1;

            s[i][j] = s[i][j - 1] + a[i][j];
        }
    }

    for(int i = 1; i <= n; i ++) {
        int minn = dp[i - 1][n + 1];
        for(int j = n + 1; j >= 1; j --) {
            int t = s[i][j - 1] + (n - j + 1) - (s[i][n] - s[i][j - 1]);
            minn = min(minn, dp[i - 1][j]);
            dp[i][j] = t + minn;
        }
    }

    int ans = INF;
    for(int i = 1; i <= n + 1; i ++) ans = min(ans, dp[n][i]);
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
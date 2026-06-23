#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int dp[N][N], l[N][N], u[N][N];
int a[N][N];

void solve()
{
    int n, m;
    cin >> n >> m;
    memset(a, -1, sizeof a);
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> a[i][j];

            if(a[i][j] != a[i][j - 1]) l[i][j] = l[i][j - 1] + 1;
            else l[i][j] = 1;

            if(a[i][j] != a[i - 1][j]) u[i][j] = u[i - 1][j] + 1;
            else u[i][j] = 1;

        }
    }

    int ans = 0;

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if( i > 1 && j > 1 && a[i][j] == a[i - 1][j - 1]) {
                dp[i][j] = min({dp[i - 1][j - 1] + 1,l[i][j], u[i][j]});
            } else {
                dp[i][j] = 1;
            }

            ans = max(dp[i][j], ans);

            // cout << dp[i][j] << " \n"[j == m];
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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int dp[N][N];
int a[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            dp[i][j] += dp[i - 1][j];
            if(j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]];

            // cout << dp[i][j] << " \n"[j == n];
        }
    }



    cout << dp[n][m] << endl;








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
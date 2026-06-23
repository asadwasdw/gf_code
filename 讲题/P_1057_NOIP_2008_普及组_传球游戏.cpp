#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
int dp[60][68];


void solve()
{
    int n,m;
    cin >> n >> m;
    dp[0][1] = 1;
    dp[0][n + 1] = 1;
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            // cout << dp[i][j] << " \n"[j == n];
        }
        dp[i][0] = dp[i][n];
        dp[i][n + 1] = dp[i][1];
        
    }
    cout << dp[m][1] << endl;
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
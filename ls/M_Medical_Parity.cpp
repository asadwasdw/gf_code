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



void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    a = " " + a;
    b = " " + b;
    vector<vector<int>> dp(n + 1,vector<int>(2, INF)); 
    dp[0][0] = 0;

    for(int i = 1; i <= n; i ++) {
        int A = a[i] - '0', B = b[i] - '0';

        dp[i][0] = min(dp[i][0], dp[i - 1][0] + (A == 0 ? 0 : 1) + (B == 0 ? 0 : 1));
        dp[i][0] = min(dp[i][0], dp[i - 1][1] + (A == 1 ? 0 : 1) + (B == 0 ? 0 : 1));

        dp[i][1] = min(dp[i][1], dp[i - 1][0] + (A == 1 ? 0 : 1) + (B == 1 ? 0 : 1));
        dp[i][1] = min(dp[i][1], dp[i - 1][1] + (A == 0 ? 0 : 1) + (B == 1 ? 0 : 1));

        // cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    }

    cout << min(dp[n][0], dp[n][1]) << endl;


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
    return 0;
}
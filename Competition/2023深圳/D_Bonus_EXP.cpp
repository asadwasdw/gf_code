#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int a[N];
int dp[N][2];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[0][1] = -INF;

    for(int i = 1; i <= n; i ++) {
        dp[i][1] = dp[i - 1][1];
        dp[i][0] = dp[i - 1][0];

        dp[i][1] = max(dp[i][1], dp[i - 1][0] + a[i]);
        dp[i][0] = max(dp[i][0], dp[i - 1][1] + a[i] + a[i]);
    }
    cout << max(dp[n][1], dp[n][0]) << endl;
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
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


void solve()
{
    int n, m;
    cin >> n >> m;
    vector dp(n + 1, vector (m + 1, INFll));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        int x, y;
        cin >> x >> y;
        int w = 0, v = 0;
        while(x || y) {
            if(x > y) swap(x, y);
            w += 1;
            v += x;
            // cout << w << " " << v << endl;
            y--;
            for(int j = 0; j <= m; j ++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
                if(j >= w)dp[i][j] = min(dp[i][j], dp[i - 1][j - w] + v);
            }
            
        }
    }
    if(dp[n][m] >= INF/2) dp[n][m] = -1;
    cout << dp[n][m] << endl;

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
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

void solve()
{
    int a, b, m;
    cin >> a >> b >> m;
    vector<vector<int>> dp(m + 1, vector<int>(2, 0));
    int ans = 2;
    if (a > b) {
        ans = (m / b) + 2;
        ans += (m%b)/(a - b);
    } 
    else if(b % a == 0) {
        ans = 2 + m / b * (b / a + 1) + (m % b) / a;
    }
    else {
        dp[0][0] = 1;
        dp[0][1] = 2;
    
        priority_queue<int> q;
        for(int i = 1; i <= m; i ++) {
            if(i >= a) {
                dp[i][0] = max(dp[i - a][0], dp[i - a][1]) + 1;   
            }
            if(i >= b) {
                q.push(dp[i - a][0]);
                dp[i][1] = max(dp[i - b][1] + 1 ,dp[i - b][1] + b/a + 1) ;
            }
            ans = max({dp[i][1], dp[i][0], ans});
            // cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
        }
        
    }cout << ans * 160 << endl;








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
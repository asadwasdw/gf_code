#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int dp[1000][1000];

void solve()
{
    string s;
    cin >> s;
    int k; cin >> k;
    int n = s.size();
    s = " " + s;
    //for(int i = 1; i <= n; i++) dp[i][i] = 1;

    for(int len = 1;len <= n; len ++) {
        for(int l = 1; l <= n; l++){
            int r = len + l - 1;
            if(r > n) break;
            dp[l][r] = dp[l + 1][r] + 1;

            if(s[l] != 'o')continue;
            for(int i = l + 1; i <= r; i++) {
                if(s[i] == 'f' && dp[l + 1][i - 1] == 0) {
                    dp[l][r] = min(dp[l][r], max(dp[i + 1][r] - k, 0));
                }
            }
        }
    }

    cout << dp[1][n] << endl;








}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
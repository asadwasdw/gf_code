#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1, INFll);
    dp[0] = 0;

    for(int i = 1; i <= n; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j = k; j >= 0; j --) {
            if(j >= 1)dp[j] = min(dp[j], dp[j - 1] + a);
            if(j >= 2)dp[j] = min(dp[j], dp[j - 2] + b);
            if(j >= 3)dp[j] = min(dp[j], dp[j - 3] + c);
            if(j >= 4)dp[j] = min(dp[j], dp[j - 4] + d);
        }

        // for(int i = 0; i <= k; i ++) cout << dp[i] << " \n"[i == k];
    }

 

    cout << dp[k] << endl;

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
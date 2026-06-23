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
#define x first
#define y second

//vector<vector<int>>adj(N);


void solve()
{
    vector<int> v(10);
    for(int i = 0; i < 10; i ++) cin >> v[i];
    int n, m; cin >> n >> m;
    vector<int> p;
    // vector<vector<int>> dp(n + 1, vector<int> (m + 1));
    vector<int> dp(m + 1, -INF);
    dp[0] = 0;
    for(int i = 1; i <= n; i ++ ){
        int x, y;
        cin >> x >> y;
        for(int j = x; j <= m; j ++) 
            dp[j] = max(dp[j],dp[j - x] + y);
    }

    vector<int> dp2(m + 1, 0);
    for(int i = 1; i <= m; i ++) {  
        if(dp[i] <= 0)continue;
        int b = (int)((double)(dp[i]*10-1)/i);
        int V = v[b]*i;
        // cout << dp[i] << " "  << V << endl;
        for(int j = i; j <= m; j ++) {
            dp2[j] = max(dp2[j], dp2[j - i] + V);
        }
        // cout << dp2[i] <<endl;
    }
    cout << dp2[m] << endl;
    
    







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
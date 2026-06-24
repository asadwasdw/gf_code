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


void solve1()
{
    int n, m;
    cin >> m >> n;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i ++) {
        int v, w; cin >> v >> w;
        for(int j = 0; j <= m; j ++) { // 转移， 注意要取max，因为会被多次更新
            for(int k = 0; k * v <= m; k ++ ) { // 枚举第 i 个物品选了多少次
                if(j < k * v) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                else dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v] + k * w);
            }
        }
    }
    cout << dp[n][m] << endl;
}

void solve2()
{
    int n, m;
    cin >> m >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0ll)); // 例题爆int了
    for(int i = 1; i <= n; i ++) {
        int v, w; cin >> v >> w;
        for(int j = 0; j <= m; j ++) { // 转移
            if(j < v) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - v] + w);
        }
    }
    cout << dp[n][m] << endl;
}

void solve3()
{
    int n, m;
    cin >> m >> n;
    vector<ll> dp(m + 1, 0ll);
    for(int i = 1; i <= n; i ++) {
        int v, w; cin >> v >> w;
        for(int j = v; j <= m; j ++) { // 转移
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[m] << endl;
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
        solve3();
    }
    return 0;
}
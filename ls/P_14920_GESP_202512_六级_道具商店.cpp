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

int dp[N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i ++) {
        int w, v;
        cin >> w >> v;
        for(int j = m; j >= v; j --) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[m];
}

void solve2() {
    int n, m;
    cin >> n >> m;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; i ++) {
        int v, w;
        cin >> w >> v;
        for(int j = 500 * 500; j >= w; j --) {
            dp[j] = min(dp[j], dp[j - w] + v);
        }
    }
    int ans = 0;
    for(int j = 0; j <= 500 * 500; j ++) {
        if(dp[j] <= m) ans = max(j, ans);
    }
    cout << ans << endl;
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
        solve2();
    }
    return 0;
}
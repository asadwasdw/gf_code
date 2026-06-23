#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e4+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[110][110];
int dp[110][N];

void solve()
{
    int t, n, m;
    cin >> t >> n >> m;

    for(int i = 1; i <= t; i ++) {
       for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
       }
    }

    int ans = m;
    
    for(int i = 2; i <= t; i ++) {
        int res = 0;
        for(int j = 1; j <= n; j ++) {
            int v = a[i - 1][j];
            int w = a[i][j];
            for(int z = v; z <= ans; z ++) {
                dp[i][z] = max(dp[i][z], dp[i][z - v] + w);
                res = max(res, dp[i][z] + ans - z); 
            }
        }
        ans = max(ans, res);
        // cout << ans << endl;
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
        solve();
    }
    return 0;
}
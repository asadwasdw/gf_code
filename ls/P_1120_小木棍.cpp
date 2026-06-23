#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=600+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);


int dp[4][N][N];

void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;

    int ans = INF;
    for(int i = 1; i <= n; i ++) {
        int a, b;
        cin >> a >> b;

        for(int j = a; j <= 600; j ++) {
            for(int z = b; z <= 600; z ++) {
                if(j == a && z == b) dp[i&1][j][z] = 1;
                else  dp[i&1][j][z] = min(dp[(i - 1)&1][j - a][z - b] + 1, dp[(i - 1)&1][j][z]);

                if(j >= x && z >= y && dp[i&1][j][z] != INF) {
                    ans = min(ans, dp[i&1][j][z]);
                } 
            }
        }
    }

    if(ans == INF) ans = -1;

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
}
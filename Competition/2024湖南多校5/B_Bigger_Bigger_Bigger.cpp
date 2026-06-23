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
int dp[36][N];

void solve()
{
    ll x, y, z, k , d;
    cin >> x >> y >> z >> k >> d;

    memset(dp,-0x3f,sizeof dp);

    if(x <= 1e6)dp[0][x] = y;
    if(y <= 1e6)dp[0][y] = x;
    int ans = INF;
    if((__int128_t)x * y >= z) ans = 0;
   
    for(int i = 1; i <= 35 && i <= ans; i ++) {
        for(int j = 0; j <= sqrt(z); j ++) {
            __int128_t dx = -INF;
            dx = max(dx, (__int128_t)dp[i - 1][j / k] + d);
if(j >= d)  dx = max(dx, (__int128_t)dp[i - 1][j - d] * k);
            if(j * dx >= z) ans = min(i,ans);
            dp[i][j] = dx;
       }
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
}
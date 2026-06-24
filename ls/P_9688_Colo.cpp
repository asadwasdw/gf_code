#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=5e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int dp[N][N]; // i, j个
int a[N], b[N];
int last[N], pre[N];

void solve()
{
    int n, cnt;
    cin >> n >> cnt;
    memset(dp, -0x3f, sizeof dp);
    memset(pre, 0x3f, sizeof pre);
    pre[0] = 0;

    for(int i = 1; i <= n; i ++) 
    {
        cin >> a[i];
        last[a[i]] = i;
        pre[a[i]] = min(pre[a[i]], i); 
    }
    for(int i = 1; i <= n; i ++) cin >> b[i];

    // for(int i = 0; i <= n; i ++) dp[i][0] = 0;
    dp[0][0] = 0;

    int ans = -1;

    for(int i = 1; i <= n; i ++) {

        for(int j = 1; j <= i; j ++) { 
            for(int k = 0; k < a[i]; k ++) {
                if(last[k] < pre[a[i]]){
                    dp[i][j] = max(dp[i][j], dp[last[k]][j - 1] + b[a[i]]);

                }
            }
        }
    }

    for(int i = 1; i <= n; i ++) {
        if(i == last[a[i]]) ans = max(ans, dp[i][cnt]);
    }

    cout << ans;







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
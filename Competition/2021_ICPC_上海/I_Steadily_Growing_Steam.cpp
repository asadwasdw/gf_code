#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dp[2][110][5500];
int K = 2600;

void solve()
{
    int n,m;
    cin>>n>>m;

    memset(dp,-0x3f,sizeof dp);
    dp[0&1][0][K] = 0;
    int ans = 0;
    for(int i = 1;i <= n;i++){
        int a,b;cin>>a>>b;
   
        for(int j = 0;j <=m ;j++){
            for(int k = 0;k<=2*K;k++){
                
                dp[i&1][j][k] = max(dp[i&1][j][k],dp[i-1&1][j][k]);

                if(j>=1){//用技能

                    dp[i&1][j][k] = max(dp[i - 1&1][j - 1][k + 2*b] + a,dp[i&1][j][k]);//放到A
                    dp[i&1][j][k] = max(dp[i - 1&1][j - 1][k - 2*b] + a,dp[i&1][j][k]);
                }

                {   //不用技能
                    dp[i&1][j][k] = max(dp[i - 1&1][j][k + b] + a,dp[i&1][j][k]);//放到A
                    dp[i&1][j][k] = max(dp[i - 1&1][j][k - b] + a,dp[i&1][j][k]);
                }

                if(k==K)ans = max(ans,dp[i&1][j][K]);
            }
        }
    }
    cout<<ans<<endl;

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
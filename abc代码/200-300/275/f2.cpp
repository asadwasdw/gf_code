#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=3e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;


int dp[N][N][2];

void solve()
{
    memset(dp,0x3f,sizeof dp);
    dp[0][0][1]=0;
  //  dp[0][0][0]=0;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        for(int j=0;j<=m;j++)
        {
            if(j>=x)dp[i][j][1]=min(dp[i-1][j-x][1],dp[i-1][j-x][0]);
            dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]+1);
        }
    }

    for(int i=1;i<=m;i++)
    {
        int ans =min(dp[n][i][1],dp[n][i][0]);
        if(ans == 0x3f3f3f3f)ans=-1;
        cout<<ans<<endl;
    }

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
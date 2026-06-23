#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=3e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;

int dp[N][N];
int pre[N];



void solve()
{
    memset(dp,0x3f,sizeof dp);
    memset(pre,0x3f,sizeof pre);
    int n,m;
    cin>>n>>m;
    dp[0][0]=0;
    pre[0]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<=m;j++)
        {
            if(j>=x)dp[i][j]=min(dp[i][j],dp[i-1][j-x]);

            dp[i][j]=min(dp[i][j],pre[j]+1);
            pre[j]=min(dp[i][j],pre[j]);
        }
    }

    for(int i=1;i<=m;i++)
    {
        if(dp[n][i]==INF)dp[n][i]=-1;
        cout<<dp[n][i]<<endl;
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
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
typedef long long ll;
ll dp[110][110][110];


void solve()
{
    int n,K,d;
    cin>>n>>K>>d;

    memset(dp,-1,sizeof dp);
    dp[0][0][0]=0;


    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        for(int j=0;j<=K;j++)
        {
            for(int k=0;k<d;k++)
            {
                if(dp[i][j][k]==-1)continue;
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);

                if(j!=K){
                    dp[i+1][j+1][(k+x)%d]=max(dp[i+1][j+1][(k+x)%d],dp[i][j][k]+x);
                }
                
            }

        }
    }

    cout<<dp[n][K][0];



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
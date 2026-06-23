#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 1e6 + 10;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>> edg(N);

int dp[N][5];
int WW[N][5];

void solve()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        WW[a][b]=w;
    }
    memset(dp,0x8f,sizeof dp);
    dp[0][0]=0;

    ll ans =0;

    for(int i=1;i<=100001;i++)
    {
        for(int j=0;j<5;j++)
        {
            int W = WW[i][j];
            if(j!=0)dp[i][j]=max(dp[i-1][j-1]+W,dp[i][j]);
            if(j!=4)dp[i][j]=max(dp[i-1][j+1]+W,dp[i][j]);
            dp[i][j]=max(dp[i-1][j]+W,dp[i][j]);

        //    cout<<dp[i][j]<<" ";

            ans = max(dp[i][j],ans);
        }
      //  cout<<endl;
    }

    cout<<ans<<endl;

    
   
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    // cin>>t;
    for (int i = 1; i <= t; i++)
    {
        // printf("Case %d: ",i);
        solve();
    }
}
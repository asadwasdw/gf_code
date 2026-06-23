#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

ll dp[N][N];
int n,m;

void solve()
{
    cin>>n>>m;

    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=m;j++)dp[i][j]=-1e18;
    }


    for(int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;

        for(int j=1;j<=i&&j<=m;j++){
            dp[i][j]=max(dp[i-1][j-1]+x*j,dp[i-1][j]);
        }
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=m;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[n][m]<<endl;







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
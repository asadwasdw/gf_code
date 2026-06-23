#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=300+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int dp[N][N][N];
int a[N];
int v[N];
int w[N];

void solve()
{
    int n,h;
    cin>>n>>h;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        cin>>v[i]>>w[i];
    }
    memset(dp,0x3f,sizeof dp);
    for (int i = 0; i <= h; i++) {
        dp[0][h][0] = 0;
    }

    for(int i = 0; i < n; i++) {
        int d = a[i+1] - a[i];
        
        for(int j = 0; j <= h;j++){
            for(int k = 0;k <= h;k++){

                int nj = j - d;int nk=k+d;
                if(nj<0||nk>h)continue;

                dp[i+1][nj][nk]=min(dp[i+1][nj][nk],dp[i][j][k]);
                dp[i+1][min(h,nj+w[i+1])][nk]=min(dp[i+1][min(h,nj+w[i+1])][nk],dp[i][j][k]+v[i+1]);
                dp[i+1][nj][max(0,nk-w[i+1])]=min(dp[i+1][nj][max(0,nk-w[i+1])],dp[i][j][k]+v[i+1]);
            }
        }
    }

    int ans = INF;

	for(int i = 0;i <= h; ++i) 
		for(int j = 0;j <= h; ++j)
			if(j <= i) ans = min(ans, dp[n][i][j]); 
    if(ans>INF/2)ans=-1;
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
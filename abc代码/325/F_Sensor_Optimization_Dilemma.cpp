#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];
ll dp[105][10000];

void solve()
{
    [](){

    }();
    
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l1,l2,c1,c2,k1,k2;

    cin>>l1>>c1>>k1;
    cin>>l2>>c2>>k2;
    memset(dp,0x3f,sizeof dp);
    dp[0][0]=0;
    ll ans = INFll;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k1;j++)
        {
            for(int k=0;k<=j;k++)
            {
                int kk = max(0ll,((a[i]-k*l1)+l2-1)/l2);
                dp[i][j]=min(dp[i-1][j-k]+kk,dp[i][j]);
            }
            if(dp[i][j]<=k2 && i==n) {
                ans = min(ans, 1ll*j*c1+dp[i][j]*c2);
            }
            //cout<<dp[i][j]<<" ";
        }//cout<<endl;
    }
    if(ans>=INFll)ans=-1;
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
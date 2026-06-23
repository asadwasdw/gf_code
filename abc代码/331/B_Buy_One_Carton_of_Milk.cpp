#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int dp[1010];

void solve()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;

    for(int i=1;i<=999;i++){
        if(i>=6)dp[i]=min(dp[i-6]+x,dp[i]);
        if(i>=8)dp[i]=min(dp[i-8]+y,dp[i]);
        if(i>=12)dp[i]=min(dp[i-12]+z,dp[i]);
    }

    for(int i=999;i;i--) {
        dp[i]=min(dp[i],dp[i+1]);
    }
    cout<<dp[n]<<endl;
    







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